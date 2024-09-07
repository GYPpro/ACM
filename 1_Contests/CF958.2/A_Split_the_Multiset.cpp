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
        // if(k > n){ cout << 0 << "\n";return;}
        if(n == 1) {cout << 0 << "\n";return;}
        int t = 0;
        while(n >= 0) {
            if (n <= k) n = 0;
            n -= k-1;
            t ++;
        }
        cout << t << "\n";
    }
};
//5
//1 1 3
//1 1 1 1 1
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