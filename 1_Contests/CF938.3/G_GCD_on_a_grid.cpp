#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution{
    private:

    public:
    void solve()
    {
        int n ,m;
        cin >> n >> m;
        vector<vector<int>> mtx(n,vector<int>(m));
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < m;j ++)
                cin >> mtx[n-i-1][m-j-1];
        dp[0][0] = mtx[0][0];
        for(int i = 1;i < n;i ++) dp[i][0] = __gcd(mtx[i][0],dp[i-1][0]);
        for(int i = 1;i < m;i ++) dp[0][i] = __gcd(mtx[0][i],dp[0][i-1]);
        for(int i = 1;i < n;i ++)
            for(int j = 1;j < m;j ++)
                dp[i][j] = max(__gcd(dp[i-1][j],mtx[i][j]),__gcd(dp[i][j-1],mtx[i][j]));
        cout << dp[n-1][m-1] << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}