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
        int p,k;
        cin >> p >> k;
        vector<int> rs;
        // set<int> MEX;
        // for(int i = 0;i < p;i ++) MEX.insert(i+1);
        // while(MEX.size()) {
        //     auto t = *MEX.begin();
        //     while(MEX.find(t) != MEX.end()) {
        //         rs.pb(t);
        //         MEX.erase(t);
        //         t += k;
        //     }
        // }
        for(int i = 0;i < k;i ++) {
            int t = i;
            while(t < p)
            {
                rs.pb(t+1);
                t += k;
            }
        }
        for(auto x:rs) cout << x << " ";

    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}