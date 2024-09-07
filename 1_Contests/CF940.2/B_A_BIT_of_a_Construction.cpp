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

    int MEX(int k)
    {
        if(!k) return 0;
        int t = 0;
        while(k)
        {
            k /= 2;
            t ++;
        }
        int ans = 1;
        t --;
        while(t--)
            ans *= 2;
        return ans -1;
    }

public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        // n --;
        // FI
        // {
        //     cout << min((int)pow(2,i),k) << " ";
        //     k -= min((int)pow(2,i),k);
        // }
        // cout << k <<<< " \n";
        // cout << MEX(k) << " ";
        // k -= MEX(k);
        // while(n--)
        if(n >= 2)
        {
            cout << MEX(k) << " " << k-MEX(k) << " ";
            for(int i = 0;i < n-2;i ++) cout << "0 ";
            cout << "\n";
        } else cout << k << "\n";
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