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
        int n,k,x,p_0;
        cin >> n >> k >> x >> p_0;
        vector<int> s(n);
        for(auto & x:s) cin >> x;
        vector<int> t(k+1);
        for(int i = 1;i <= k;i ++) cin >> t[i];

        vector<int> p(k+1);
        for(int i = 1;i <= k;i ++) cin >> p[i];
        p[0] = p_0;

        int vmin = INT_MAX;
        int curt = 0;
        int curp = p[0];
        for(int i = 0;i <= k;i ++)
        {   
            vmin = min(vmin,x / (p[i] - t[i]) + (x % (p[i] - t[i]) != 0));
        }
        // cout << vmin << "\n";
        sort(s.begin(),s.end());
        for(int i = 0;i < n;i ++) if(s[i] >= vmin) {
            cout << n-i << "\n";
            return;
        } cout << 0 << "\n";

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