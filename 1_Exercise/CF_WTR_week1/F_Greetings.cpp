#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define int long long
#define mod1 998244353
#define pb push_back

class solution{
    private:

    public:
    void solve()
    {
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(auto &x:arr) cin >> x.first >> x.second;
        sort(arr.begin(),arr.end());
        vector<int> f,e;
        for(auto x:arr)f.pb(x.first),e.pb(x.second);  
        int ans = 0;
        ordered_set st;
        for(int i = n-1;i >= 0;i --)
        {
            st.insert(arr[i].second);
            ans += st.order_of_key(arr[i].second);
        }
        cout << ans << "\n";
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