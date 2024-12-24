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
            for(int i = 1;i <= lg[dep[p]];i ++) wei[p][i] = max(wei[p][i-1],wei[fa[p][i-1]][i-1]);
            for(auto [x,w]:cnj[p]) if(x == f) continue;
            else wei[x][0] = w,dfs(x,p);
        };
        dfs(rt,0);
    }

    int skipUp(int x,int len) {
        assert(len < dep[x]);
        int tar = dep[x] - len;
        while(dep[x] > tar) x = fa[x][lg[dep[x]-tar]-1];
        return x;
    }

    int get(int x,int y) {
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return x;
        for(int k = lg[dep[x]]-1;k >= 0;k --) if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
        return fa[x][0];
    }

    int getmaxw(int x,int y) {
        int curmx = 0;
        if(dep[x] < dep[y]) swap(x,y);
        while(dep[x] > dep[y]) curmx = max(curmx,wei[x][lg[dep[x] - dep[y]] - 1]), x = fa[x][lg[dep[x] - dep[y]] - 1];
        if(x == y) return curmx;
        for(int k = lg[dep[x]]-1;k >= 0;k --) 
            if(fa[x][k] != fa[y][k]) 
                curmx = max(curmx,wei[x][k]),x = fa[x][k],
                curmx = max(curmx,wei[y][k]),y = fa[y][k];
        return max({curmx,wei[x][0],wei[y][0]});
    }

};

// #define D

pair<pii,pii> getMX (map<int,int> & vals) { //[fi,se];
    // assert(vals.size() >= 2);
    vals[-1] = 0;
#ifdef D
    // cout << "\n";
    for(auto [idx,val]:vals) cout << "{" << idx << "," << val  << "} ";
#endif
    int mxidx = 0,mxval = -2;
    for(auto [idx,val]:vals) if(val > mxval) mxidx = idx,mxval = val;
    int semidx = 0,semval = -2;
    for(auto [idx,val]:vals) if(idx == mxidx) continue;
    else if(val > semval) semidx = idx,semval = val;
#ifdef D
    cout << "getmax:" << mxidx << " " << mxval << "  " << semidx << " " << semval << "\n";
#endif
    return {{mxidx,mxval},{semidx,semval}};
};

void solve()
{
    int n;
    cin >> n;
    LCA lca(n);

    for(int i = 1;i < n;i ++)
    {
        int u,v;
        cin >> u >> v;
        lca.addEdge(u,v,1);
    }
    lca.build();
    auto cnj = lca.cnj;
    auto fa = lca.fa;
    // vector<pii> tmp


    vector<int> mxlen(n+1),palen(n+1);
    vector<map<int,int>> subwei(n+1);
    vector<pair<pii,pii>> mxs;
    
    using itf = function<void(int,int)>;
    itf dfs1 = [&](int p,int f) -> void { // cacu mxlen
        int mx = 0;
        for(auto [v,_]:cnj[p]) if(v != f) dfs1(v,p),mx = max(mx,mxlen[v]);
        mxlen[p] += mx + (f == 0 || cnj[p].size() > 1);
    };dfs1(1,0);

    map<int,int> tmp;
    // for(auto [v,_]:cnj[1]) tmp[v] = mxlen[v];

    // auto [mx,semx] = getMX(tmp);//[idx,val]
    // // for(auto x:palen) cout << x << " ";cout << "\n";

    // palen[1] = mx.se;
    // for(auto [v,_]:cnj[1]) {
    //     if(v == mx.fi) palen[v] = semx.se +2;
    //     else palen[v] = mx.se +2;
    // }
    
    // for(auto x:palen) cout << x << " ";cout << "\n";
    palen[0] = 0;
    itf dfs2 = [&](int p,int f) -> void { // caccu palen
        tmp.clear();
        tmp[f] = palen[p] + 1;
        for(auto [v,_]:cnj[p]) if(v != f) tmp[v] = mxlen[v] + 2;
        // if()

#ifdef D
        cout << "dfs2:" << p << " " << f << "\n";
#endif

        auto [mx,semx] = getMX(tmp);

        for(auto [v,_]:cnj[p]) if(v != f){
            if(v == mx.fi) palen[v] = semx.se;
            else palen[v] = mx.se;
#ifdef D
            cout << "setpalen:" << v << " to " << palen[v] << "\n";
#endif
        }

        // // int sum = 0;  
        // if(f != 1) palen[p] = palen[f] + 1;
        for(auto [v,_]:cnj[p]) if(v != f) dfs2(v,p);
    };
    dfs2(1,0);
    // for(auto [u,_]:cnj[1])
    //     for(auto [v,_]:cnj[u])
    //         dfs2(v,u);
    
    itf dfs3 = [&](int p,int f) -> void {
        subwei[p][f] = palen[p];
        for(auto [v,_]:cnj[p]) if(v != f) subwei[p][v] = mxlen[v] + 1;
        for(auto [v,_]:cnj[p]) if(v != f) dfs3(v,p);
    };
    dfs3(1,0);
    // for(auto [v,_]:cnj[1]) dfs3(v,1);

    for(auto x:subwei) mxs.pb(getMX(x));
    // mx.se ++,semx.se ++;
    // mxs[1] = {mx,semx};
#ifdef D
    // for(auto x:mxlen) cout << x << " ";cout << "\n";
    // for(auto x:palen) cout << x << " ";cout << "\n";
    cout << "--mxlen--\n";
    for(int i = 1;i <= n;i ++) cout << i << ":" << mxlen[i] << "\n";
    cout << "--palen--\n";
    for(int i = 1;i <= n;i ++) cout << i << ":" << palen[i] << "\n";

    cout << "-----\n";
    getMX(subwei[4]);
#endif

    int q;
    cin >> q;
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        int lc = lca.get(u,v);
        int dis = -lca.dep[lc]+lca.dep[u]-lca.dep[lc]+lca.dep[v];
        if(lc == v) {
            int tu = lca.skipUp(u,abs(lca.dep[lc]-lca.dep[u])-1);
#ifdef D
            cout << "path lc==v:" << q << "\n";
            cout << lc << " " << tu << " " << dis << " " << v << "\n";
#endif
            if(tu == mxs[v].fi.fi) cout << dis + mxs[v].se.se << "\n";
            else cout << dis + mxs[v].fi.se << "\n";
#ifdef D
            if(tu == mxs[v].fi.fi) cout << "se" <<  mxs[v].se.se << "\n";
            else cout << "fi" << mxs[v].fi.se << "\n";
#endif
        } else {
#ifdef D
            cout << "path lc!=v:" << q << "\n";
            cout << lc << " "  << mxlen[v]  << " " << dis << " " << v << "\n";
#endif
            cout << dis + mxlen[v] << "\n";
        }
    }
}

signed main()
{
    freopen("temp.in","r",stdin);
    freopen("temp.out","w",stdout);
    
    #ifdef FC
        freopen("A.A.in","r",stdin);
        freopen("A.A.ptc","w",stdout);
    #endif


    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
