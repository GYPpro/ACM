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
        bool flag = 0;
        vector<vector<int>> pt(2,vector<int>());
        pt[0].pb(INT_MAX);
        pt[1].pb(INT_MAX);
        for(auto x:arr)
        {
            int ed0 = pt[0][pt[0].size()-1],ed1 = pt[1][pt[1].size()-1];
            if(ed0 < ed1) {//1lr
                if(x > ed1) pt[0].pb(x);
                else if(x > ed0) pt[1].pb(x);
                else pt[0].pb(x);
            } else { // ed0 > ed1
                if(x > ed0) pt[1].pb(x);
                else if(x > ed1) pt[0].pb(x);
                else pt[1].pb(x);
            }
        }
        // pt[flag].push_back(arr[0]);
        // for(int i = 0;i < arr.size()-1;i ++)
        // {
        //     if(arr[i] < arr[i+1]) flag = !flag;
        //     pt[flag].push_back(arr[i+1]);
        // }
        int ans = 0;
        for(int i = 0;i < 2;i ++)
        {
            for(int j = 0;j < (int)pt[i].size()-1;j ++)
                if(pt[i][j] < pt[i][j+1]) ans ++;
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