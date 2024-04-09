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
        for (auto &x:arr) cin >> x;
        set<int> nextMex;
        for(int i = 0;i < n;i ++) nextMex.insert(i);
        vector<int> ans;
        int MEX = 0;
        for(auto x:arr)
        {
            if(x > 0) {
                ans.pb(MEX);
                nextMex.erase(MEX);
                MEX = *(nextMex.begin());
            } else {
                ans.pb(abs(x) + MEX);
                nextMex.erase(abs(x) + MEX);
                MEX = *(nextMex.begin());
            }
        }
        for(auto x:ans) cout << x << " ";
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