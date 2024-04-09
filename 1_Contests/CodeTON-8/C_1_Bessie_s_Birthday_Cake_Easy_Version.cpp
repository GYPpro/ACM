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

class solution
{
private:

    int dif(int x)
    {
        if(x > 1) return x;
        else return 0;
    }

public:
    void solve()
    {
        int n,xn,y;
        cin >> n >> xn >> y;
        vector<int> arr(xn);
        for(auto &x:arr) cin >> x;
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> nxt;
        for(int i = 0;i < xn-1;i ++)
        {
            nxt.pb({arr[i],arr[i+1]-arr[i] -1});
        }
        nxt.pb({arr[xn-1],n + arr[0]-arr[xn-1] -1});
        set<pair<int,int>> prio;

        // for(auto x:nxt) prio.insert({ x.second  == 3 ? 3 : dif(x.second) - dif(x.second - 2),x.second});
        // sort(prio.begin(),prio.end());

        // for(int i = 0;(i < nxt.size()) && y;i ++)
        // {
        //     if(nxt[i].second > 2)
        // }
        int sum = 0;
        for(auto x:nxt) sum += dif(x.second);
        cout << n-2-sum << '\n';
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