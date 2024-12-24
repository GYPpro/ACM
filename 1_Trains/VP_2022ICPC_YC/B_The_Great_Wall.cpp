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
const int INF = 1e18;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

int dp[2][10005][3];

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n+1);
    lop(i,1,n+1) cin >> h[i];
    lop(i,0,2)
        lop(j,0,10004)
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
    
    lop(i,0,2) dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = 0;

    int cur = 0;

    lop(i,1,n+1){
        cur = !cur;
        lop(j,1,n+1)
        {
            dp[cur][j][0] = max({ dp[!cur][j][1]-h[i],
                                dp[!cur][j][2]+h[i],
                                dp[!cur][j-1][0],
                                dp[!cur][j][0]        });
            dp[cur][j][1] = max({dp[!cur][j][1],dp[!cur][j-1][0] + h[i]});
            dp[cur][j][2] = max({dp[!cur][j][2],dp[!cur][j-1][0] - h[i]});
        }
    }
    lop(i,1,n+1) cout << dp[cur][i][0] << "\n";
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
