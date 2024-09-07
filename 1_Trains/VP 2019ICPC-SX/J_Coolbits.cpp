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
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second

void sort(auto &x)
{
    sort(x.begin(), x.end());
};

using namespace std;

class solution
{
private:
public:
    void solve()
    {
        int n;
        cin >> n;
        vector<pair<int, int>> itv(n);
        for (auto &x : itv)
            cin >> x.fi >> x.se;
        vector<int> res(32);

        auto checkALL = [&](int n) -> bool
        {
            for (auto x : itv)
            {
                if (x.se - x.fi > (1LL << n))
                    continue;
                if (((x.se >> (n)) % 2) || ((x.first >> (n)) % 2))
                    continue;
                // if(x.se >= (1LL << n) && x.fi <= (1LL << n)) continue;
                else
                    return 0;
                // x.se
            }
            return 1;
        };

        auto declALL = [&](int n) -> void
        {
            // cout << n << "--\n";
            for (auto &x : itv)
            {
                // if(x.se >= (1<<(n+1))){
                //     x.se = x.se - x.se%(1<<(n+1)- 1) ;
                //     x.fi = x.se - (1<<n)+1;
                // } else {
                // }
                // pair<int,int> x = {nt.first % }
                // if ((x.se >= ((1 << (n + 1)) - 1) && x.fi <= ((1 << (n + 1)) - 1)))
                // {
                //     x.fi = max(x.fi,((1LL << (n + 1)) - 1));
                //     x.se = x.fi;
                // } else if ((x.se / (1 << n)) % 2)
                //     // x.fi = max(x.fi,x.fi - x.fi % (1 << (n + 1)) + (1 << n));
                //     x.fi = max(x.fi, x.se - (x.se) % (1 << n));
                // else
                // {
                //     x.se = x.se - (x.se + 1) % (1 << (n + 1)); //---
                //     x.fi = max(x.fi, x.se - (1 << n) + 1);
                // }

                int d2 = (1 << (n+1));
                int d1 = (1 << (n));
                
                if((x.fi >> n)%2) // 1 
                {
                    x.se = min(x.se,x.fi - x.fi % d1 + d1 - 1);
                } else { // 0
                    x.fi = x.fi - x.fi%d1 + d1;
                    x.se = min(x.se,x.fi+d1 - 1);
                }

                // cout << x.first << " " << x.second << "\n";
            }
        };

        for (int i = 31; i >= 0; i--)
        {
            if (checkALL(i) == 1)
            {
                res[i] = 1;
                declALL(i);
            }
            else
                res[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < res.size(); i++)
            ans += res[i] * (1LL << i);
        cout << ans << "\n";
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