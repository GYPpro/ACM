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
    int n,c;
    cin >> n >> c;
    vector<int> w(n+1);
    lop(i,1,n+1) cin >> w[i];
    vector<vector<int>> cnj(n+1);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    vector<array<int,2>> dp(n+1);
    lop(i,1,n+1) dp[i][1] = w[i];
    using itf = function<void(int,int)>;
    itf dfs = [&](int p,int f) -> void {
        if(cnj[p].size() == 1 && f ) return;
        for(auto x:cnj[p])
            if(x == f) continue;
            else dfs(x,p);
        for(auto x:cnj[p])
        {
            if(x == f) continue;
            dp[p][0] += max(dp[x][0] , dp[x][1]); // 0
            dp[p][1] += max(dp[x][0] , dp[x][1] - (c << 1));
        }
    };
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]) << "\n";
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
