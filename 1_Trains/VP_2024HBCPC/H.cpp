// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1e18;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

class LCA{
public:
    vector<vector<int>> cnj;
    vector<int> lg,dep;
    vector<array<int,25>> fa,wei_x,wei_y;
    vector<int> d,irs;
    int n;
    bool ifinit = 0;

    LCA(int _n) {
        n = _n;
        cnj.resize(n+1);
        array<int,25> tmp;
        tmp.fill(INF);
        lg.resize(n+1),fa.resize(n+1),
        dep.resize(n+1),wei_x.resize(n+1,tmp),
        wei_y.resize(n+1,tmp),irs.resize(n+1);
        for(int i = 1; i <= n; i ++)
            lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    }

    void addEdge(int u,int v,int w = 1) {
        cnj[u].push_back(v);
        cnj[v].push_back(u);
    }

    void setIrs(int k) {
        irs[k] = 1;
    }

    void init(int rt = 1) {
        ifinit = 1;
        queue<int> q;
        vector<int> dis(n+1,INF);
        vector<int> LOCK(n+1);
        lop(i,0,n) if(irs[i]) q.push(i),dis[i] = 0;
        while(q.size())
        {
            auto u = q.front();
            q.pop();
            if(LOCK[u]) continue;
            LOCK[u] = 1;
            for(auto v:cnj[u]) {
                if(dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        this->d = dis;
    }

    void build(int rt = 1) {
        using itf = function<void(int,int)>;
        init();
        // dep[0] = -1;
        itf caudep = [&](int p,int f) -> void {
            dep[p] = dep[f] + 1;
            for(auto x:cnj[p]) if(x == f) continue;
            else caudep(x,p);
        };caudep(rt,0);

        itf dfs = [&](int p,int f) -> void {
            fa[p][0] = f,dep[p] = dep[f] + 1;
            // wei[p][0] = 0;
            for(int i = 1;i <= lg[dep[p]];i ++) fa[p][i] = fa[fa[p][i-1]][i-1];
            for(int i = 1;i <= lg[dep[p]];i ++) wei_x[p][i] = min(wei_x[p][i-1],wei_x[fa[p][i-1]][i-1]);
            for(int i = 1;i <= lg[dep[p]];i ++) wei_y[p][i] = min(wei_y[p][i-1],wei_y[fa[p][i-1]][i-1]);

            for(auto x:cnj[p]) if(x == f) continue;
            else {
                wei_x[x][0] = 3*d[x]-dep[x] , wei_y[x][0] = 3*d[x]+dep[x] ;
                dfs(x,p);
            }
        };
        dfs(rt,0);
    }

    int get(int x,int y) {
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y])
            x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y)
            return x;
        for(int k = lg[dep[x]]-1;k >= 0;k --)
            if(fa[x][k] != fa[y][k])
                x = fa[x][k],y = fa[y][k];
        return fa[x][0];
    }

    int getminx(int x,int y) {
        if(x == y) return 3*d[x] - dep[x];
        int curmx = 3*d[x] - dep[x];
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y])
            curmx = min(curmx,wei_x[x][lg[dep[x] - dep[y]] - 1]),
                    x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return curmx;
        for(int k = lg[dep[x]]-1;k >= 0;k --) 
            if(fa[x][k] != fa[y][k]) 
                curmx = min(curmx,wei_x[x][k]),x = fa[x][k],
                curmx = min(curmx,wei_x[y][k]),y = fa[y][k];
        return min({curmx,wei_x[x][0],wei_x[y][0]});
    } 
    int getminy(int x,int y) {
        if(x == y) return 3*d[x] + dep[x];
        int curmx = 3*d[x] + dep[x];
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y]) 
            curmx = min(curmx,wei_y[x][lg[dep[x] - dep[y]] - 1]),
                x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return curmx;
        for(int k = lg[dep[x]]-1;k >= 0;k --) 
            if(fa[x][k] != fa[y][k]) 
                curmx = min(curmx,wei_y[x][k]),x = fa[x][k],
                curmx = min(curmx,wei_y[y][k]),y = fa[y][k];
        return min({curmx,wei_y[x][0],wei_y[y][0]});
    }
    
    int dis(int x,int y) {
        int m = this->get(x,y);
        return dep[x]-dep[m]+dep[y]-dep[m];
    }
};



void solve()
{
    int n,k;
    cin >> n >> k;
    LCA lca(n+1);
    vector<vector<int>> cnj(n+1);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
        lca.addEdge(u,v,1);
    }
    vector<int> bikes(k);
    for(auto &x:bikes) cin >> x;
    for(auto x:bikes) lca.setIrs(x);
    lca.build();
    // lca.init();
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int r = lca.get(x,y);
        // cout << lca.dis(x,y)*2 << " " << lca.dis(x,y)   + lca.dep[x] + lca.getminx(r,x) << " " <<  lca.dis(x,y)*2 - lca.dep[y] + lca.getminy(r,y) << "\n";
        cout << min({
            lca.dis(x,y)*2 ,
            lca.dis(x,y)   + lca.dep[x] + lca.getminx(r,x) ,
            lca.dis(x,y)*2 - lca.dep[y] + lca.getminy(r,y)  }) << "\n";
    }

}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
