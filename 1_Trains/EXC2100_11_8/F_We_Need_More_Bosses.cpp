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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> dfn(n+1),fa(n+1);
    vector<int> low(n+1);
    vector<pii> links;
    vector<vector<int>> h(n+1);
    auto addE = [&](int u,int v) {
        links.pb({u,v});
        h[u].pb(links.size()-1);
        links.pb({v,u});
        h[v].pb(links.size()-1);
        // edge
    };
    for(int i = 1;i <= m;i ++)
    {
        int u,v;
        cin >> u >> v;
        addE(u,v);
    }
    vector<int> ib(links.size() + 2);
    int dfncnt = 0;
    using itf = function<void(int,int)>;
    vector<pii> res;
    int cnt = 0;
    itf dfs = [&](int u,int tv) -> void {
        fa[u] = tv;
        low[u] = dfn[u] = ++dfncnt;
        for(auto rv:h[u]) {
            int v = links[rv].se;
            if(!dfn[v]) {
                dfs(v,rv);
                low[u] = min(low[u],low[v]);
                if(low[v] > dfn[u]) ib[rv] = ib[rv^1] = 1,res.push_back({u,v});
            } else if(dfn[v] < dfn[u] && rv != (tv ^ 1)) low[u] = min(low[u],dfn[v]);
        }
    }; 
    for(int i = 1;i <= n;i ++) if(!dfn[i]) dfs(i,0);
    // cout << res.size() << "\n";
    vector<int> bcc(n+1);
    int dc = 0;

    itf dfs2 = [&](int u,int tv) -> void {
        bcc[u] = dc;
        for(auto rv:h[u]){
            int v = links[rv].se;
            if(ib[rv] || bcc[v] || rv == (tv ^ 1)) continue;
            else dfs2(v,rv);
        }
    };
    for(int i = 1;i <= n;i ++ ) if(!bcc[i]) ++dc,dfs2(i,0);
    vector<set<int>> newcnj(dc+2);
    // for(auto x:bcc) cout << x[0] << " ";
    // for(int i = 1;i <= n;i ++) cout << ib[i] << " ";cout << "\n"; 
    // for(int i = 1;i <= n;i ++) cout << bcc[i] << " ";cout << "\n"; 
    // cout << "\n";
    for(auto [u,v]:res){
        newcnj[bcc[u]].insert(bcc[v]);
        newcnj[bcc[v]].insert(bcc[u]);
    }
    vector<int> dep(n+1);
    int mx = 0,tmp = -1;
    // for(int i = 0;i < newcnj.size();i ++)
    // {
    //     cout << i <<  " :";
    //     for(auto x:newcnj[i]) cout << x << " ";cout << "\n";
    // }
    itf dfs3 = [&](int p,int f) -> void {
        dep[p] = dep[f] + 1;
        for(auto x:newcnj[p]) {
            if(x == f) continue;
            dfs3(x,p);
        }
        if(dep[p] > mx) {
            mx = dep[p];
            tmp = p;
        }
    };  
    dfs3(1,0);
    int d1 = tmp;
    dep[d1] = 0;
    dep[0] = 0;
    mx = 0;
    dfs3(d1,0);
    cout << mx -1<< "\n";
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
