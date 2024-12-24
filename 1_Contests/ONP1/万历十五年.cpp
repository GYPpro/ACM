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
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    using itf =  function<void(int,int)>;
    vector<int> wei(n+1);
    vector<int> cost(n+1);
    itf dfs = [&](int p,int f) -> int {
        wei[p] = 1;
        for(auto x:cnj[p]) if(x == f) continue;
        else dfs(x,f),wei[p] += wei[x];
    };
    dfs(1,0);
    itf cacu = [&](int p,int f) -> int {
        int sum = wei[p]-1;
        int prfx = 0;
        int minans = INF;
        for(auto x:cnj[p]) if(x == f) continue;
        else {
            prfx += wei[x];
            minans = min(minans,abs(prfx-(sum-prfx)));
        }
    };
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
    cin >> T;
    while(T--) solve();
    return 0;
}
