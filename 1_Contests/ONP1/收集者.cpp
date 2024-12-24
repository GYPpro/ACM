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

const int mod = 1e9+7;

int binpow(int x,int y)
{
    if(y < 0) return 1;
    int ans = 1;
    while(y)
    {
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int cnt0 = 0,cnt1 = 0;
    int ans = 2;
    vector<array<int,2>> dp(s.size()+1);
    // if(s.back() == '1') dp[s.size()-1][1] = 1;
    // else dp[s.size()-1][0] = 1;
    int f = 0;
    for(int i = 1;i <= s.size();i ++)
    {
        if(s[i-1] == '0') dp[i][0] = dp[i-1][0] + dp[i-1][1],dp[i][1] = dp[i-1][1],f = 1;
        else dp[i][1] = dp[i-1][1] + dp[i-1][0] + 1,dp[i][0] = dp[i-1][0];
        dp[i][1] %= mod;
        dp[i][0] %= mod;
    }
    cout <<( dp[s.size()][1]+dp[s.size()][0] +f )%mod<< "\n";
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
