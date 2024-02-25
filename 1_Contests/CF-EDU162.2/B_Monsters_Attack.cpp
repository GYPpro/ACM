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
        int n,k;
        cin >> n >> k;
        map<int,int> mtr;
        vector<pair<int,int>> tmp(n);
        for(int i = 0;i < n;i ++)
            cin >> tmp[i].second;
        for(int i = 0;i < n;i ++)
            cin >> tmp[i].first;
        for(auto x:tmp) mtr[abs(x.first)] += x.second;
        
        int usd = 0;
        for(auto x:mtr)
        {
            usd += x.second;
            if(usd > x.first * k) {
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