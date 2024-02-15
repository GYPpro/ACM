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
        for(auto& x:arr) cin >> x;
        int eq = 0;
        map<int,int> cnt;
        cnt[arr[0]] ++;
        cnt[arr[n-1]] ++;
        for(int i = 0;i < n-1;i ++)
            if(arr[i] == arr[i+1]) cnt[arr[i]] ++;
            else break;
        for(int i = n-1;i >= 0;i --)
            if(arr[i] == arr[i-1]) cnt[arr[i]] ++;
            else break;
        if(cnt.size() > 1){
            int mx = 0;
            for(auto x:cnt) mx = max(x.second,mx);
            cout << n - mx << "\n";
        } else cout << max(0LL,n-cnt.begin()->second) << "\n";
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