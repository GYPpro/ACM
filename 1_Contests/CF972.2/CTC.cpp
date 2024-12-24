// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

map<char,int> tr = {
    {'n',0},
    {'a',1},
    {'r',2},
    {'e',3},
    {'k',4}
};

string md = "narek";

void solve()
{
    int n,m;
    cin >> m >> n;
    vector<string> st(m);
    for(auto &x:st) cin >> x;
    vector<array<pii,5>> mp(1); //  from c to [c_1,earn]
    vector<array<int,5>> dp(m+1);
    for(auto x:st)
    {
        auto finda = [&](int tar) -> pii{
            int l = tar,r = 0;
            int cnt = 0;
            int cnt2 = 0;
            while(r < x.size())
            {
                l %= 5;
                if(x[r] == md[l]) l++,r++,cnt++;
                else r++;
            }
            // l --;
            l %= 5;
            for(auto c:x) if(tr.find(c) != tr.end()) cnt2 ++;
            // cnt = cnt-cnt%5;
            return {cnt-(cnt2-cnt),l};
        };
        array<pii,5> st;
        lop(k,0,5) st[k] = finda(k);
        mp.pb(st);
        cout << x << "----\n";
        for(auto x:st) cout << x.fi << " " << x.se << "\n";
    }
    lop(i,0,5) dp[1][i] = mp[1][i].fi;
    lop(f,0,5) cout << dp[1][f] << " ";cout << "\n";
    for(int i = 2;i <= m;i ++)
    {
        dp[i] = dp[i-1];
        // lop(f,0,5) dp[i][mp[i-1][f].se] = -n;
        dp[i][mp[i]]
        lop(f,0,5)
        {
            dp[i][mp[i-1][f].se] = max({
                dp[i][mp[i-1][f].se] , 
                dp[i-1][f] + mp[i-1][f].fi,
                dp[i-1][f] });
            cout << "covex:"<< i-1 << " " << f << " to " << i << " " << mp[i-1][f].se << "\n";
            cout << dp[i-1][f] << " " << mp[i-1][f].fi << "\n";
        }
        lop(f,0,5) cout << dp[i][f] << " ";cout << "\n";
        
    }
    cout << max(0LL,dp[m][0]) << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
