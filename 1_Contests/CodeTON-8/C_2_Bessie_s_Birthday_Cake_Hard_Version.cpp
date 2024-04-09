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

class solution
{
private:
    int dif(int x)
    {
        if (x > 1)
            return x;
        else
            return 0;
    }

public:
    void solve()
    {
        int n, xn, y;
        cin >> n >> xn >> y;
        vector<int> arr(xn);
        for (auto &x : arr)
            cin >> x;
        sort(arr.begin(), arr.end());
        vector<pair<int, int>> nxt;
        for (int i = 0; i < xn - 1; i++)
        {
            nxt.pb({arr[i], arr[i + 1] - arr[i] - 1});
        }
        nxt.pb({arr[xn - 1], n + arr[0] - arr[xn - 1] - 1});
        int sum = 0;
        for (auto x : nxt)
            sum += dif(x.second);
        vector<int> p;
        vector<int> d;
        for (auto x : nxt)
        {
            // if(x.second <= 1) continue;
            if(x.second % 2)
                p.pb(x.second);
            else 
                d.pb(x.second);
        }
        sort(p.begin(),p.end());
        sort(d.begin(),d.end());
        for(auto x:p)
        {
            int req =( x - 1)/2;
            if(y > req){ sum -= dif(x); y -= req;}
            else {
                sum -=  dif(x) - dif(x - 2 * y);
                y = 0;
                break;
            }
        }
        for(auto x:d)
        {
            int req = x / 2;
            if(y >= req){ sum -= dif(x); y -= req;}
            else {
                sum -=  dif(x) - dif(x - 2 * y);
                y = 0;
                break;
            }
        }
        cout << n-2-sum  << "\n";
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