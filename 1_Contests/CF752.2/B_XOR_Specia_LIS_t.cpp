#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#pragma GCC optimize(2)

// #define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution{
    private:

    public:
    void solve()
    {
        int n;
        cin >> n;
        if(n%2)
        {
            int pv = 0;
            cin >> pv;
            bool flag = 0;
            for(int i = 1;i < n;i ++)
            {
                int tmp;
                cin >> tmp;
                if(pv >= tmp)
                    flag = 1;
                pv = tmp;
            }
            if(flag)
                cout << "YES\n";
            else
                cout << "NO\n";
            return;
        }
        else {
            int tmp = 0;
            for(int i = 0;i < n;i ++)
            cin >> tmp;
        }
        cout << "YES\n";
        return;
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