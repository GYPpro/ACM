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

    int getdi(int n) {
        if(n == 8) return 2;
        if(n == 0 || n ==  6 || n == 9 || n == 4) return 1;
        return 0;
    }

public:
    void solve()
    {
        int t,k;
        cin >> t >> k;
        int TCL = t;
        while(TCL && (k--)) {
            int f = TCL;
            int tmp = 0;
            while(f){
                tmp += getdi(f%10);
                f /= 10;
            }
            TCL = tmp;
        }
        if(k != 0 && TCL == 0) TCL = k%2;
        cout << TCL << "\n";
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