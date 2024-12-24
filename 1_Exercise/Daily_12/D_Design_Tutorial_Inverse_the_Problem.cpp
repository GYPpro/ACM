// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
// #define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) min(u ,v ),max(u ,v )
// #define set unordered_set
// #define map unordered_map

class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        for(int i = 0;i < n;i ++) f[i] = i;
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

class graph {
public:
using tii = array<int,3>;
    vector<vector<pii>> cnj;
    vector<pii> links;
    vector<tii> edges;
    vector<vector<int>> bcc, h;
    vector<int> dfn, scc, sz, fa;
    int sc,dc;
    int n;
    graph(int _n) {
        n = _n;
        reset(cnj);
        reset(h);
    };
    graph(vector<vector<pii>> _cnj) {
        n = _cnj.size();
        cnj = _cnj;
    }

private:
    void reset(auto &t) {
        t.clear();
        t.resize(n + 1);
    };

public:
    void addOrdEdge(int u, int v, int w = 1) {
        cnj[u].push_back({v, w});
        edges.pb({u,v,w});
    }

    void addUnordEdge(int u, int v, int w = 1) {
        cnj[u].push_back({v, w});
        cnj[v].push_back({u, w});
        //邻接表↑--链式前向星↓
        links.pb({u,v});
        h[u].pb(links.size()-1);
        links.pb({v,u});
        h[v].pb(links.size()-1);
        edges.pb({u,v,w});
        edges.pb({v,u,w});
    }
    // 强连通分量缩点
    void runSCC() {
        reset(dfn), reset(scc), reset(sz);
        vector<int> low(n + 1), s, vst(n + 1), sz(n + 1);
        sc = 0;
        int tp = 0, dfncnt = 0;
        using itf = function<void(int)>;
        itf dfs = [&](int u) -> void
        {
            low[u] = dfn[u] = ++dfncnt;
            s.pb(u), vst[u] = 1;
            for (auto [v, _] : cnj[u])
            {
                if (!dfn[v])
                {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                }
                else if (vst[v])
                {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u])
            {
                sc++;
                while (s.back() != u)
                {
                    scc[s.back()] = sc;
                    sz[sc]++;
                    vst[s.back()] = 0;
                    s.pop_back();
                }
                scc[s.back()] = sc;
                sz[sc]++;
                vst[s.back()] = 0;
                s.pop_back();
            }
        };
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                dfs(i);
    }
    /**双联通分量缩点
     * E：边双：支持重边
     * D：点双
     */
    void runBCC(char mod = 'E') {
        reset(bcc),reset(sz);
        if(mod == 'E') {
            auto [ib,_] = this->findBridge();
            using itf = function<void(int,int)>;
            dc = 0;
            itf dfs = [&](int u,int tv) -> void {
                bcc[u] = {dc};
                for(auto rv:h[u]){
                    int v = links[rv].se;
                    if(ib[rv] || bcc[v].size() || rv == (tv^1)) continue;
                    else dfs(v,rv);  
                }
            };
            for(int i = 1;i <= n;i ++) if(!bcc[i].size()) ++dc,dfs(i,0);
        } else if(mod == 'D') {
            auto ic = this->findCut();
            using itf = function<void(int,int)>;
            dc = 0;
            itf dfs = [&](int u,int f) -> void {
                for(auto [v,_]:cnj[u]) {
                    if(v == f || (!ic[v] && bcc[v].size())) continue;
                    else if(ic[v] || bcc[v].size()) bcc[v].pb(dc);
                    else bcc[v].pb(dc),dfs(v,u);
                } 
            };
            for(int i = 1;i <= n;i ++) if(!bcc[i].size()) ++dc,bcc[i].pb(dc),dfs(i,0);
        } else assert(0);
    }

    /**最小生成树，默认Kruskal
     * Kruskal:O(m log m) for 稀疏图 
     * Prim:O((n+m) log n) for 稠密图
     * 返回邻接表
     */
    vector<vector<pii>> runMST(string method = "Prim") {
        graph ng(n);
        using tii = array<int,3>;
        const int INF = 1e17;
        if (method == "Kruskal") {
            priority_queue<tii,vector<tii>,greater<tii>> q;
            DSU dsu(n+1);
            for(auto [u,v,w]:edges) q.push({w,u,v});
            while(q.size())
            {
                auto [w,u,v] = q.top();
                q.pop();
                if(!dsu.same(u,v)) {
                    ng.addUnordEdge(u,v,w);
                    dsu.merge(u,v);
                }
            }
            return ng.cnj;
        }
        else if (method == "Prim") {
            // cout << 1 << "\n";
            vector<int> dis(n+1,INF);
            using fii = array<int,4>;
            priority_queue<fii,vector<fii>,greater<fii>> q;
            q.push({0,0,0,1});
            dis[1] = 0;
            vector<int> LOCK(n+1);
            while(q.size()) 
            {
                auto [_,w,f,u] = q.top();
                q.pop();
                if(LOCK[u]) continue;
                else LOCK[u] = 1;
                if(f) ng.addUnordEdge(f,u,w);
                for(auto [v,wv]:cnj[u])
                {
                    if(dis[v] >= dis[u] + wv) {
                        dis[v] = dis[u] + wv;
                        q.push({dis[v],wv,u,v});
                    }
                }
            }
            return ng.cnj;
        } else assert(0);
    }

    /**
     * tarjin找桥
     * 返回{res,ib}中ib[x]!=0代表某点的出边x是桥，res为桥的列表
     */
    pair<vector<int>,vector<pii>> findBridge() {
        reset(dfn),reset(fa);
        vector<int> low(n+1),ib(links.size()+2);
        vector<pii> res;
        int dfncnt = 0;
        using itf = function<void(int,int)>;
        itf dfs = [&](int u,int tv) -> void {
            fa[u] = tv;
            low[u] = dfn[u] = ++dfncnt;
            // for(auto [v,_]:cnj[u]) {
            for(auto rv:h[u]){
                int v = links[rv].se;
                if(!dfn[v]){
                    dfs(v,rv);
                    low[u] = min(low[u],low[v]);
                    if(low[v] > dfn[u]) ib[rv] = ib[rv^1] = 1,res.pb({u,v});
                } else if(dfn[v] < dfn[u] && rv != (tv^1))
                    low[u] = min(low[u],dfn[v]);
            }
        };
        for(int i = 1;i <= n;i++) if(!dfn[i]) dfs(i,0);
        return {ib,res};
    }

    // tarjin找割点
    vector<int> findCut() {
        reset(dfn);
        vector<int> low(n+1),ic(n+1);
        vector<bool> vis(n+1);//能不能去掉？
        int dfscnt = 0;
        using itf = function<void(int,int)>;
        itf dfs = [&](int u,int f) {
            vis[u] = 1;
            low[u] = dfn[u] = ++dfscnt;
            int ch = 0;
            for(auto [v,_]:cnj[u]){
                if(!vis[v]){
                    ch ++;
                    dfs(v,u);
                    low[u] = min(low[u],low[v]);
                    if(f != u && low[v] >= dfn[u] && !ic[u]) ic[u] = 1;
                } else if(v != f) low[u] = min(low[u],dfn[v]);
            }
            if(f == u && ch >= 2 && !ic[u]) ic[u] = 1;
        };
        for(int i = 1;i <= n;i ++) if(!vis[i]) dfscnt = 0, dfs(i,i);
        return ic;
    }
};

class LCA{ 
public:
    vector<vector<pii>> cnj;
    vector<int> lg,dep;
    vector<array<int,32>> fa,wei;
    int n;

    LCA(int _n) {
        n = _n;
        cnj.resize(n+1);
        lg.resize(n+1),fa.resize(n+1),dep.resize(n+1),wei.resize(n+1);
        for(int i = 1; i <= n; i ++)
            lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    }

    void addEdge(int u,int v,int w) {
        cnj[u].push_back({v,w});
        cnj[v].push_back({u,w});
    }

    void build(int rt = 1) {
        using itf = function<void(int,int)>;
        itf dfs = [&](int p,int f) -> void {
            fa[p][0] = f,dep[p] = dep[f] + 1;
            // wei[p][0] = 0;
            for(int i = 1;i <= lg[dep[p]];i ++) fa[p][i] = fa[fa[p][i-1]][i-1];
            for(int i = 1;i <= lg[dep[p]];i ++) wei[p][i] = wei[p][i-1]+ wei[fa[p][i-1]][i-1];
            for(auto [x,w]:cnj[p]) if(x == f) continue;
            else wei[x][0] = w,dfs(x,p);
        };
        dfs(rt,0);
    }

    int get(int x,int y) {
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return x;
        for(int k = lg[dep[x]]-1;k >= 0;k --) if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
        return fa[x][0];
    }

    int getsumw(int x,int y) {
        int cursum = 0;
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y]) cursum += wei[x][lg[dep[x] - dep[y]] - 1], x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return cursum;
        for(int k = lg[dep[x]]-1;k >= 0;k --) 
            if(fa[x][k] != fa[y][k]) 
                cursum += wei[x][k],x = fa[x][k],
                cursum += wei[y][k],y = fa[y][k];
        return cursum + wei[x][0] + wei[y][0];
    } 
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> mtx(n+1,vector<int>(n+1));
    graph gp(n+1);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++) {
            cin >> mtx[i][j];
            if(i > j)
                gp.addUnordEdge(i,j,mtx[i][j]);
        }
    auto cnj = gp.runMST();
    // // for(auto x:cnj)
    // for(int  i = 1;i <= n;i ++)
    // {
    //     auto x = cnj[i];
    //     for(auto [y,w]:x) cout << i <<  "-" << y << ":" << w << "\n";
    //     cout << "----\n";
    // }

    LCA lca(n+1);
    lca.cnj = cnj;
    lca.build();


    for(int i = 1;i <= n;i ++)
        for(int j = i+1;j <= n;j ++)
        {
            if(mtx[i][j] != mtx[j][i]) {
                cout << "NO\n";
                return;
            }
            if(!mtx[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    for(int i = 1;i <= n;i ++)
        if(mtx[i][i] != 0) {
            cout << "NO\n";
            return;
        }

    // // vector<vector<pii>> cnj(n+1);
    // graph gp(n+1);
    // LCA lca(n+1);
    // map<int,vector<int>> ndp;
    // set<pii> adde;
    // set<int> added;
    // set<int> tmp;
    // added.insert(1);
    // using tii = array<int,3>;
    // set<tii> tbo;

    // auto ade = [&](int i,int x) -> void {
    //     if(i == x) return;
    //     if(adde.find({ord(i,x)}) != adde.end()) return;
    //     added.insert(i),added.insert(x);
    //     cout << "adde:" << i << " " << x << " " << mtx[i][x] << "\n";
    //     adde.insert({ord(i,x)});
    //     gp.addUnordEdge(i,x,mtx[i][x]);
    //     lca.addEdge(i,x,mtx[i][x]);
    // };

    // for(int i = 1;i <= n;i ++)
    // {
    //     for(int j = 1;j <= n;j ++)
    //     {
    //         if(j != i)
    //         ndp[mtx[i][j]].push_back(j);
    //     }
    //     if(ndp.size() == 0) continue;
    //     auto [u,v] = *ndp.begin();
    //     for(auto x:v){
    //         ade(i,x);
    //     }
    //     ndp.clear();
    // }

    // for(int i = 1;i <= n;i ++)
    // {
    //     tmp = added;
    //     while(tmp.size()){
    //         int rt = *tmp.begin();
    //         tmp.erase(rt);
    //         bool accForRT = 1;
    //         for(auto [x,w]:lca.cnj[rt]) {
    //             tmp.erase(x);
    //             if(mtx[x][rt] + mtx[rt][i] != mtx[x][i]) accForRT = 0;
    //             if(mtx[i][rt] == mtx[i][x] + mtx[x][rt]) {
    //                 cout << "pass at:" << i << " " << rt << " " <<x  << "\n";
    //                 ade(i,x);
    //             }
    //         }
    //         if(accForRT) {
    //                 cout << "pass at:" << i << " " << rt << " "  << "\n";
    //             ade(i,rt);
    //         }
    //     }
    // }
    // // return;
    // gp.runBCC();

    // // for(auto x:gp.bcc) cout << x.size() << " ";cout << "\n";
    // map<int,int> cnt;
    // for(auto x:gp.bcc) if(x.size()) cnt[x[0]] ++;

    // for(auto [k,x]:cnt) if(x > 1) {
    //     // cout << k << " " << x << "\n";
    //     cout << "NO\n";
    //     return;
    // }

    // lca.build();

    for(int i = 1;i <= n;i ++)
    {
        for(int j = i;j <= n;j ++)
        {
            if(lca.getsumw(i,j) != mtx[i][j]){
                // if(n > 100){
                    // cout  << i << " " << j << ":found " << lca.getsumw(i,j) << " expect " << mtx[i][j] << "\n";
                    // cout << added.size() << "\n";
                // }
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
