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

int get1(int x)
{
    int t = 0;
    while(!(x%2)){
        t ++;
        x >>= 1;
    }
    return t;
}

public:
    void solve()
    {
        int x,y;
        cin >> x >> y;
        vector<int> binx;
        vector<int> biny;
        auto getbin = [&](int t) -> vector<int> {
            vector<int> rt;
            while(t)
            {
                rt.pb(t%2);
                t >>= 1;
            }
            return rt;
        };
        binx = getbin(x);
        biny = getbin(y);

        // for(auto x:binx )cout << x << " ";
        // cout << "\n";

        // for(auto x:biny )cout << x << " ";
        // cout << "\n";
        

        int eqmx = 0;
        for(int i = 0;i < max(binx.size(),biny.size());i ++)
        {
            if(i >= binx.size()) binx.pb(0);
            if(i >= biny.size()) biny.pb(0);
            if(binx[i] != biny[i]) break;
            eqmx ++;
        }
        cout << (1 << eqmx) << "\n";
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