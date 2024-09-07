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
        int n;
        cin >> n;
        vector<int> arr(n);
        string s;
        cin >> s;
        for(int i = 0;i < n;i ++)
        {
            arr[i] = s[i] - '0';
        }
        int cnt0 = 0,cnt1 = 0;
        if(arr[0] == 0) cnt0 ++;
        for(int i = 0;i < n-1;i ++) {
            if(arr[i] == 1 && arr[i+1] == 0) cnt0 ++;
            if(arr[i]) cnt1++;
        } if(arr[n-1]) cnt1++;
        // cout << cnt1 << " " << cnt0 << "\n";
        if(cnt1 > cnt0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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