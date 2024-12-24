#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
const int mod = 1e9+7;
void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    s1 = "-" + s1;
    s2 = "-" + s2;
    vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1));
    // dp[i][j] s1->i,s2->j
    // lop(i,1,s1.size())
    lop(i,1,s1.size()+1)
        if(s1[i] == s2[1]) dp[i][1] = dp[i-1][1] +1;
        else dp[i][1] = dp[i-1][1];
    lop(j,2,s2.size()+1)
        lop(i,1,s1.size()+1)
        {
            if(s1[i] == s2[j]) dp[i][j] += dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
        }
    cout << dp[s1.size()][s2.size()] % mod << "\n";
        // lop(j,1,s2.size())
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}