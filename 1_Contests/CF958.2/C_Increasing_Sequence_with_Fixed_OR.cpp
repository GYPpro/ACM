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
        int n;
        cin >> n;
        vector<int> bin;
        int t = n;
        while (t)
        {
            bin.pb(t%2);
            t /= 2;
        }
        // for(auto x:bin) cout << x << " ";cout << "\n";
        vector<int> oneidx;
        for(int i = bin.size()-1;i >= 0;i --)
        {
            if(bin[i]) oneidx.pb(i);
        }
        if(oneidx.size() <= 1) {cout << 1 << "\n" << n << "\n";return;}
        cout << oneidx.size() + 1 << "\n";
        auto bin2int = [&]() -> int {
            int t = 0;
            for(int i = 0;i < bin.size();i ++)
                t += ((1LL<<i) * bin[i]);
            return t;
        };
        for(auto x:oneidx) {
            bin[x] = !bin[x];
            cout << bin2int() << " ";
            bin[x] = !bin[x];
        }
        cout << n << "\n";
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