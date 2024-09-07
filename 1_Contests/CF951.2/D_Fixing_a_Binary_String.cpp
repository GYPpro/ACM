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
        int n,k;
        cin >> n >> k;
        string a;
        cin >> a;
        int BMC = 0;
        int tmps = 0;
        int MEX = -1;
        bool f = 1;

        for(int i = 0;i < n-1;i ++)
        {
            if(a[i] != a[i+1])
            {
                tmps ++;
                if(tmps != k) {f = 0;break;}
                tmps = 0;
            } else {
                tmps ++;
                if(tmps >= k) {
                    f = 0;break;
                }
            }
        }
        if(f){cout << n << "\n";return;}
        tmps = 0;
        f = 1;

        for(int i = n-1;i > 0;i --)
        {
            if(a[i] != a[i-1]){
                MEX = i-1;
                break;
            }
        }
        if(MEX == -1) 
            if(n == k){cout << n << "\n";return;}
            else {cout << -1 << "\n";return;}
        for(int i = MEX;i > 0;i --)
        {
            if(a[i] != a[i-1])
            {
                tmps ++;
                if(tmps != k) {f = 0;break;}
                BMC = i-1;
                tmps = 0;
            } else {
                tmps ++;
                if(tmps >= k) {BMC = i-1;f = 0;break;}
            }
        }
        // if(tmps == k-1) BMC = -1;
        // if(f && tmps == k-1) BMC = -1;
        f = 1;
        // cout << BMC +1<< "\n";
        // if(BMC == 0) {cout << k << "\n";return;}
        if(BMC >= 0) 
            for(int i = 0;i <= BMC/2;i ++)
                swap(a[i],a[BMC-i]);
        // cout << a << "\n";
        auto r = [&](int _i) -> int{
            return _i%n;
        };
        tmps = 0;
        int i = BMC +1;
        for(int tk = 0;tk < n-1;tk ++)
        {
            if(a[r(i+tk)] != a[r(i+1+tk)])
            {
                tmps ++;
                if(tmps != k) {f = 0;break;}
                tmps = 0;
            } else {
                tmps ++;
                if(tmps >= k) {
                    f = 0;break;
                }
            }
        }
        if(f) cout << BMC +1 << "\n";
        else cout << -1 << "\n";
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