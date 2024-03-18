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
        k *= 2;
        set<int> eqlr;
        set<int> eqdsf;
        set<int> eqdss;
        vector<int> fs(n);
        vector<int> ss(n);
        map<int,int> cntf;
        map<int,int> cnts;
        vector<int> gnans1;
        vector<int> gnans2;
        vector<int> leqdsf;
        vector<int> leqdss;
        for(auto &x:fs) cin >> x;
        for(auto &x:ss) cin >> x;
        for(auto x:fs) cntf[x] ++;
        for(auto x:ss) cnts[x] ++;
        for(auto x:cntf) if(x.second == 1) eqlr.insert(x.first);
        for(auto x:cnts) if(x.second == 1) eqlr.insert(x.first);
        for(auto x:cntf) if(x.second == 2) eqdsf.insert(x.first);
        for(auto x:cnts) if(x.second == 2) eqdss.insert(x.first);
        for(auto x:eqdsf) leqdsf.push_back(x);
        for(auto x:eqdss) leqdss.push_back(x);
        int idx = 0;
        for(;gnans1.size() < k;)
        {
            if(idx >= leqdsf.size()) break;
            gnans1.pb(leqdsf[idx]);
            gnans1.pb(leqdsf[idx]);
            gnans2.pb(leqdss[idx]);
            gnans2.pb(leqdss[idx]);
            idx ++;
        }
        for(auto x:eqlr){
            if(gnans1.size() >= k) break;
            gnans1.pb(x);
            gnans2.pb(x);
        }
        for(auto x:gnans1) cout << x << " ";
        cout << "\n";
        for(auto x:gnans2) cout << x << " ";
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