// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update>;
// #define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
// const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    n ++;
    m ++;
    a.pb(0);
    vector<vector<int>> rg_tel(n),rg_wei(n);
    vector<int> prv_tel,prv_wei;
    int prv = 0;
    vector<int> gis;
    for(int i = 0;i < n;i ++)
    {
        if(a[i] == 0) {
            gis.pb(i);
            sort(all(prv_tel)),sort(all(prv_wei));
            if(prv_tel.size())rg_tel[i] = prv_tel;prv_tel.clear();
            if(prv_wei.size())rg_wei[i] = prv_wei;prv_wei.clear();
        } else if(a[i] > 0) prv_tel.pb(a[i]);
        else prv_wei.pb(abs(a[i]));
    }
    // for(int i = 0;i < n;i ++) 
    // int dp(m+1,vector<int>(m+1));
    vector<vector<int>> dp(2,vector<int>(m+1));
    // int dp[m+1][m+1];
    // for(int i = 0;i <= m;i ++)
    //     for(int j = 0;j <= m;j ++) dp[i][j] = 0;
    // dp[i][j] 到第i为选了j个1
    // j个1(tel) i-j个-1(wei)
    // 1 1 4 4 4 5
    //
    auto get = [&](int i,int cnt1,int cntd1) -> int {
        return 
            (upper_bound(all(rg_tel[i]),cnt1)-rg_tel[i].begin()) + 
            (upper_bound(all(rg_wei[i]),cntd1)-rg_wei[i].begin());
            
            // rg_tel[i].order_of_key(cnt1+1)+rg_wei[i].order_of_key(cntd1+1);
    };

    for(int i = 1;i <= m;i ++)
    {
        dp[!(i&1)][0] = dp[i&1][0] + get(gis[i-1],0,i-1);
        for(int j = 1;j <= i;j ++)
            if(j != i)
                dp[!(i&1)][j] = max(
                    dp[i&1][j] + get(gis[i-1],j,i-j-1),
                    dp[i&1][j-1] + get(gis[i-1],j-1,i-j)
                );
            else  dp[!(i&1)][j] = dp[i&1][j-1] + get(gis[i-1],j-1,i-j);
    }
    int mx = 0;
    for(int i = 0;i <= m;i ++)
        mx = max(mx,dp[!(m&1)][i]);
    cout << mx << "\n";
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
