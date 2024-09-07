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

const int mod = 998244353LL;
const int N = 1e3+7;

vector<vector<int>> C;

void solve()
{
    int n,k,m;
    cin >> n >> k >> m;
    string s1,s2;
    cin >> s1 >> s2;
    int tar = 0;
    lop(i,0,n) tar += (s1[i] != s2[i]);
    // cout << tar << "\n";
    vector<vector<int>> dp(k+2,vector<int> (n+1+m+1));
    dp[0][tar] = 1;
    for(int i = 0;i < k;i ++)
    {
        // int flag;
        // if(i == 0) flag = tar;
        // else flag = n-1;
        for(int j = n;j >= 0;j --){
            for(int x = min(m,j);x>= 0;x --)
                if(n-j < m-x) continue;
                else dp[i+1][j-x+(m-x)] = 
                    ( dp[i+1][j-x+(m-x)] + 
                    dp[i ][j ] * C[j][x] % mod * C[n-j][m-x] % mod ) % mod;
        }
    }

    // lop(i,0,k+1){
    //     lop(j,0,n+1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }cout << "\n";}

    cout << dp[k][0] << "\n";
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
    C.resize(N+2,vector<int>(N+2));
    C[0][0] = 1;
    lop(i,1,N)
    {
        C[i][0] = 1;
        lop(j,1,i+1) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }

// lop(i,0,10) {lop(j,0,10) cout << C[i][j] << " "; cout << "\n";}

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
