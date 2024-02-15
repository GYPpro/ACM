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
        int t;
        cin >> t;
        t -= 3;
        string ans;
        ans.push_back('a'+ (min(t,25LL)));
        t -= min(t,25LL);
        ans.push_back('a'+ (min(t,25LL)));
        t -= min(t,25LL);
        ans.push_back('a'+ (min(t,25LL)));
        for(int i = ans.size()-1;i >= 0;i --)
            cout << ans[i];
        cout << "\n";
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