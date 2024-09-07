#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

#pragma GCC optimize("O3")
// #define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution{
    private:

        // set<int> mg(set<int> a,set<int> b)
        // {
        //         set<int> mgr;
        //         for(auto x:a) mgr.insert(x);
        //         for(auto x:b) mgr.insert(x);
        //         return mgr;
        // }

        // int __gcd(int a,int b){
        //         return b == 0 ? a : __gcd(b, a % b);
        // }

    public:
    void solve()
    {
        int n ,m;
        cin >> n >> m;
        vector<vector<int>> mtx(n,vector<int>(m));
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < m;j ++)
                cin >> mtx[i][j];
        // dp[0][0].insert(mtx[0][0]);
        // for(int i = 1;i < n;i ++) dp[i][0].insert(__gcd(mtx[i][0],*(dp[i-1][0].begin())));
        // for(int i = 1;i < m;i ++) dp[0][i].insert(__gcd(mtx[0][i],*(dp[0][i-1].begin())));
        // for(int i = 1;i < n;i ++)
        //     for(int j = 1;j < m;j ++)
        //     {
        //         for(auto x:dp[i-1][j])
        //             dp[i][j].insert(__gcd(mtx[i][j],x));
        //         for(auto x:dp[i][j-1])
        //             dp[i][j].insert(__gcd(mtx[i][j],x));
        //     }
        // cout << *dp[n-1][m-1].rbegin() << "\n";
        // vector<int> ans;
        // for(auto x:dp[n-1][m-1]) ans.pb(x);
        // sort(ans.begin(),ans.end());
        // cout << ans[ans.size()-1] << "\n";
        vector<vector<char>> dp(n,vector<char>(m));
        auto check = [&](int tar)->bool{
            dp.assign(n,vector<char>(m));
            dp[0][0] = 1;
            // cout << tar;
            for(int i = 1;i < n;i ++) dp[i][0] = dp[i-1][0] & (mtx[i][0] % tar == 0);
            for(int i = 1;i < m;i ++) dp[0][i] = dp[0][i-1] & (mtx[0][i] % tar == 0);
            for(int i = 1;i < n;i ++)
                for(int j = 1;j < m;j ++)
                {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                    dp[i][j] = (mtx[i][j] % tar == 0) & dp[i][j];
                }
            // cout << tar << "\n";
            return dp[n-1][m-1];
        };

        // for(int k = mtx[0][0];k >= 1;k --)
        //     if(mtx[0][0] % k == 0)
        //         if (check(k)) {
        //             cout << k << "\n";
        //             return;
        //         }
        auto get_fac = [&] (int x) {
            vector<int> res;
            for (int i = 1; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    res.push_back(i);
                    if (i * i != x) res.push_back(x / i);
                }
            }
            return res;
        };

        // auto g = __gcd(a[1][1], a[n][m]);z

        auto fac = get_fac(mtx[0][0]);

        sort (fac.begin(), fac.end(), greater<int>());

        for (auto x : fac) {
            if (check(x)) {
                cout << x << "\n";
                return;
            }
        }
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
    