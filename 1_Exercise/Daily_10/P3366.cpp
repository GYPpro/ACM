// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int get(int x) {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y)
    { // 设x是y的祖先
        x = get(x), y = get(y);
        if (x == y)
            return false;
        fa[y] = x;
        return true;
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
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
            // cout << "yes\n";
            auto [ib,_] = this->findBridge();
            // for(auto [u,v]:_) cout << u << " " << v << "|";
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
        } else {
            auto ic = this->findCut();
            using itf = function<void(int,int)>;
            dc = 0;
            itf dfs = [&](int u,int f) -> void {
                // bcc[u].pb(bc);
                for(auto [v,_]:cnj[u]) {
                    if(v == f || (!ic[v] && bcc[v].size())) continue;
                    else if(ic[v] || bcc[v].size()) bcc[v].pb(dc);
                    else bcc[v].pb(dc),dfs(v,u);
                } 
            };
            for(int i = 1;i <= n;i ++) if(!bcc[i].size()) ++dc,bcc[i].pb(dc),dfs(i,0);
        }
    }

    /**最小生成树
     * Kruskal:O(m log m) for 稀疏图
     * Prim:O((n+m) log n) for 稠密图
     * 返回邻接表
     */
    vector<vector<pii>> runMST(string method = "Kruskal") {
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
            vector<int> dis(n+1,INF);
            priority_queue<tii,vector<tii>,greater<tii>> q;
            q.push({0,1});
            dis[1] = 0;
            while(q.size())
            {
                auto [w,u,v] = q.top();
                q.pop();
                ng.addUnordEdge(u,v,w);
                for(auto [t,wt]:cnj[v])
                {
                    if(dis[t] > dis[v]+wt) {
                        dis[t] = dis[v]+wt;
                        q.push({dis[t],v,t});
                    }
                }
            }
            return ng.cnj;
        }
    }

    vector<vector<pii>> runDMST(string method = "Tarjin") {

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
            // cout << "et:" << u << " ";
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
        // dfs(1,1);
        return ic;
    }

    // 生成kruskal重构树，返回邻接表
    void kruskalRefactor() {
    }
};

void solve()
{
    int n,m;
    cin >> n >> m;
    graph gp(n);
    lop(i,0,m) {
        int u,v,w;
        cin >> u >> v >> w;
        gp.addUnordEdge(u,v,w);
    }
    auto cnj = gp.runMST("Kruskal");
    using itf = function<void(int,int)>;
    int wei = 0;
    itf dfs = [&](int p,int f) -> void {
        for(auto [v,w]:cnj[p])
        {
            if(v == f) continue;
            else wei += w;
        }
    };
    cout << wei << "\n";
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