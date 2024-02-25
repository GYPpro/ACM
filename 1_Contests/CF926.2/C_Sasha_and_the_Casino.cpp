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

class solution{
    private:

    public:
    void solve()
    {
        int k,x,a;
        cin >> k >> x >> a;
        int pvct = 1;
        for(int i = 0;i < x;i ++)
        {
            pvct += max(1LL, pvct/(k-1)+1);
            if(pvct > a){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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