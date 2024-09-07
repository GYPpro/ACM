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
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        int cnt0 = 0;
        for(auto x:arr) if(!x) cnt0 ++;
        if(cnt0 > m) {cout << "Impossible" << "\n";return;}
        if(n == m) {cout << "Richman\n";return;}
        m -= cnt0;
        int ttlC = 0;
        int MEX = 0;
        for(;MEX < n;MEX ++)
        {
            if(!m) break;
            ttlC += arr[MEX];
            if(arr[MEX]) m --;
        }
        // cout << ttlC << "\n";
        int minn = 1e18;
        for(;MEX < n;MEX ++)
            minn = min(minn,(arr[MEX]?arr[MEX]:(int)1e18));
        cout << ttlC + minn - 1 << "\n";
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