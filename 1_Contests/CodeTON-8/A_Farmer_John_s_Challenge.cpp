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
        int n,k;
        cin >> n >> k;
        if(k != 1 && k != n) {
            cout << -1 << "\n";
        }else {
            if (k == 1)
            {
                for(int i = 0;i < n;i ++) cout << i + 1 <<" ";
                cout << "\n";
            } else {
                for(int i = 0;i < n;i ++) cout << 1 << " ";
                cout << "\n";
            }
        }

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