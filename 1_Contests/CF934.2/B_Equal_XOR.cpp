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
        set<int> eqlr;       // 分居左右的数字 equal left and right
        set<int> eqdsf;      // 两个都在左边的数字 equal char doubled (at) string (where located at) first
        set<int> eqdss;      // 两个都在右边的数字 equal char doubled (at) string (where located at) second
        vector<int> fs(n);   // 左边输入 fisrt string
        vector<int> ss(n);   // 右边输入 secone string
        map<int,int> cntf;   // 左边计数 count first
        map<int,int> cnts;   // 右边计数 count second
        vector<int> gnans1;  // 生成左边答案 generated ans 1
        vector<int> gnans2;  // 生成右边答案 generated ans 2
        vector<int> leqdsf;  // 两个都在左边的数字，set不好处理，于是用vector接住 list (of) equal char doubled (at) string (where located at) first
        vector<int> leqdss;  // 两个都在右边的数字 list (of) equal char doubled (at) string (where located at) right
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