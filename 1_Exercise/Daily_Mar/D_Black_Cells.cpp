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
///   5:■■□□□■■■□□□□□□
    public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> rg(n);
        for(auto &x:rg) cin >> x.first;
        for(auto &x:rg) cin >> x.second;
        map<int,int> steps;
        int step = 0;
        int nowRg = 0;
        int nowBlks = 0;
        int rqOvr = 0;
        bool ifOvr = 0;
        for(auto x:rg)
        {
            nowRg = x.first;
            int leng = x.second - x.first +1;
            step += 2;
            if(!ifOvr){
                if(leng <= 1) rqOvr ++;
                if(nowBlks + leng >= k)
                {
                    ifOvr = 1;
                    nowRg = x.first + k-nowBlks -1;
                    nowBlks = k;
                } else {
                    nowBlks += leng;
                    nowRg = x.second;
                } 
            }

            if(ifOvr)
                for(int i = nowRg;(i <= x.second) && (steps.size() <= rqOvr);i ++){
                    nowRg = i;
                    steps[nowBlks + i-nowRg] = step + nowRg;
                    nowBlks ++;
                }
        }
        if(!ifOvr)
        {
            cout << -1 << "\n";
            return;
        }
        step = 1145141919810LL;
        for(auto x:steps)
            step = min(step,x.second-2*(x.first-k));
        cout << step << "\n";
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