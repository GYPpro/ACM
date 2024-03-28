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

    // bool comp(pair<int,int> a,pair<int,int> b)
    // {
    //     if(a.first == b.first)
    //         return a.second > b.second;
    //     else return a.first < b.first;
    // }

    public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> arr;
        for(auto &x:arr) cin >> x.first >> x.second;
        int maxw = 0;
        for(auto x:arr)
        {
            vector<pair<int,int>> cac;
            for(auto xx:arr) cac.push_back({xx.first,abs(xx.second - x.second)});
            sort(cac.begin(),cac.end());
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