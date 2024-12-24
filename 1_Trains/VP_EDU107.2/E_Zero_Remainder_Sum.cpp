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

const int N=75;
int dp[N][N][N][N];
void solve()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                for(int l=0;l<N;l++) dp[i][j][k][l]=-1e18;
            }
        }
    }
    int n,m,k;
    cin>>n>>m>>k;
    dp[1][0][0][0]=0;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int x=0;x<=m;x++){
                for(int y=0;y<k;y++){
                    dp[i][j+1][x][y] = max(
                        dp[i][j+1][x][y],
                        dp[i][j][x][y]  
                    );
                    dp[i][j+1][x+1][(y+a[i][j])%k] = max(
                        dp[i][j+1][x+1][(y+a[i][j])%k],
                        dp[i][j][x][y]+a[i][j]
                    );
                }
            }
        }
        for(int x=0;x<=m/2;x++){
            for(int y=0;y<k;y++){
                dp[i+1][0][0][y]=max(dp[i+1][0][0][y],dp[i][m+1][x][y]);
            }
        }
    }
    cout<<dp[n+1][0][0][0];
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
