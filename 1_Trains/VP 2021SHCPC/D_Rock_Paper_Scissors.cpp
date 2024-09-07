#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        // vector<vector<int>> rtc = {{0,0,0,0},{0,0,-1,1},{0,1,0,-1},{0,-1,1,0}};
        vector<vector<int>> rtc = {{0,-1,1},{1,0,-1},{-1,1,0}};
        // int BR,BP,BS;
        // cin >> BR >> BP >> BS;
        // int DR,DP,DS;
        // cin >> DR >> DP >> DS;
        vector<int> B(3);
        for(auto &x:B) cin >> x;
        vector<int> D(3);
        for(auto &x:D) cin >> x;
        int ans = 0;
        auto disc = [&](int &a,int &b)->int{
            int t = min(a,b);
            a -= t;
            b -= t;
            return t;
        };

        for(int i = 0;i < 3;i ++)
            for(int j = 2;j >= 0;j --)
                ans += rtc[i][(i + 2 + j)%3] * disc(B[i],D[(i + 2 + j)%3]);
        // ans += disc(BR,DP);
        // disc(BR,DR);
        // ans -= disc(BR,DS);
        // ans += disc(BP,DS);
        // disc(BP,DP);
        // ans -= disc(BR,DR);
        // ans += disc(BS,DR);
        // disc(BS,DS);
        // ans -= disc(BS,DP);
        cout << -ans << "\n";
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