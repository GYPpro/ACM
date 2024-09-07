#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
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
        // cout << "?";
        // int n = 1000;
        // FI{
        //     cout << i << ":";
        //     for(int j = 1;j <= i;j ++)
        //         if((i+j)%(j*__gcd(i,j)) == 0) cout << j << " ";
        //     cout << "\n";
        // }
        int n,m;
        cin >> n >> m;
        int ans = n;
        for(int i = 2;i <= m;i ++){
            for(int k = i*i-i;k <= n;k += i*i)
                ans ++;
        }
        cout << ans << "\n";
    }
};

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

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