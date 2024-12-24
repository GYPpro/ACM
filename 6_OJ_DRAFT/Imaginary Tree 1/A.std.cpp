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
    int n;
    cin >> n;
    vector<vector<int>> cnj(n+1);
    for(int i = 1;i < n;i ++)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    int q;
    cin >> q;

    using itf = function<int(int,int)>;
    vector<int> dep(n+1),fa(n+1);
    
    itf cacudep = [&](int p,int f) -> int {
        dep[p] = dep[f] + 1;
        fa[p] = f;
        for(auto x:cnj[p]) if(x != f) cacudep(x,p);
        return 0;
    }; cacudep(1,0);

    auto dis =  [&](int u,int v) -> int {
        int ttl = 0;
        while(u != v) {
            if(dep[u] > dep[v]) {
                u = fa[u],ttl ++;
            } else v = fa[v],ttl ++;
        }
        return ttl;
    };

    while(q--)
    {
        int u,v;
        cin >> u >> v;
        itf dfs = [&](int p,int f) -> int {
            int mx = 0;
            if(p == u) return -INF;
            for(auto x:cnj[p]) if(x != f) {
                int tv = dfs(x,p);
                if(tv < 0) return -INF;
                mx  = max(mx,tv);
            }  
            return mx + 1;
        };
        int mx = 0;
        for(auto x:cnj[v]) mx = max(mx,dfs(x,v));
        cout << dis(u,v) + mx << "\n";
    }
}

signed main()
{
    // freopen("temp.in","r",stdin);
    // freopen("temp.out","w",stdout);
    
#ifdef DFC
    freopen("A.A.in","r",stdin);
    freopen("A.A.std","w",stdout);
#endif


    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
