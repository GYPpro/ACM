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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        int s = 0;
        for(auto x:arr) s += x;
        int t = s/n;
        s = 0;
        for(auto x:arr)
        {
            s += x-t;
            if(s < 0){
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