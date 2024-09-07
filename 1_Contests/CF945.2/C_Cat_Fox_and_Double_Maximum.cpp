#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

// #define map unordered_map
// #define set unordered_set

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
        int n;
        cin >> n;
        set<int,greater<int>> dis;
        set<int> upper;

        FI dis.insert(i+1),upper.insert(i+1);

        vector<int> arr(n);
        for(auto &x:arr) cin >> x;

        int maxidx = 0;
        int maxnum = 0;
        for(int i = 0;i < n;i ++)
        {
            if(arr[i] > maxnum)
            {
                maxnum = arr[i];
                maxidx = i;
            }
        }

        vector<int> ans;

        bool f = !maxidx%2;
        FI{
            f = !f;
            if(f){
                int t = *upper.upper_bound(n+1-arr[i]);
                // if(t == *upper.end())
                //     t = *upper.begin();
                ans.pb(t);
                upper.erase(t);
                dis.erase((int)(t));
            } else {
                auto tR = upper.lower_bound(n+1-arr[i]) --;
                int t = *tR;
                // if(t == *upper.end())
                //     t = *upper.begin();
                ans.pb(t);
                upper.erase(t);
                dis.erase((int)(t));

                // if(t == *dis.end())
                //     t = *dis.begin();
                // ans.pb(t);
                // dis.erase(t);
                // upper.erase((int)(t));
            }
        }
        for(auto x:ans ) cout << x << " ";
        cout << "\n";
        FI cout << arr[i] + ans[i] << " ";
        cout << "\n";
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