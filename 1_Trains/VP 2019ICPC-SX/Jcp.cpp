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
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
void sort(auto &x)
{
    sort(x.begin(), x.end());
};

class s1
{
private:
public:
    int solve(int n,vector<pair<int, int>> itv)
    {
        // int n;
        // cin >> n;
        // vector<pair<int, int>> itv(n);
        // for (auto &x : itv)
        //     cin >> x.fi >> x.se;
        vector<int> res(32);

        auto checkALL = [&](int n) -> bool
        {
            for (auto x : itv)
            {
                if (x.se - x.fi > (1LL << n))
                    continue;
                if (((x.se >> (n)) % 2) || ((x.first >> (n)) % 2))
                    continue;
                // if(x.se >= (1LL << n) && x.fi <= (1LL << n)) continue;
                else
                    return 0;
                // x.se
            }
            return 1;
        };

        auto declALL = [&](int n) -> void
        {
            // cout << n << "--\n";
            for (auto &x : itv)
            {
                // if(x.se >= (1<<(n+1))){
                //     x.se = x.se - x.se%(1<<(n+1)- 1) ;
                //     x.fi = x.se - (1<<n)+1;
                // } else {
                // }
                int d2 = (1 << (n+1));
                int d1 = (1 << (n));
                
                if((x.fi >> n)%2) // 1 
                {
                    x.se = min(x.se,x.fi - x.fi % d1 + d1 - 1);
                } else { // 0
                    x.fi = x.fi - x.fi%d1 + d1;
                    x.se = min(x.se,x.fi+d1 - 1);
                }
                // cout << x.first << " " << x.second << "\n";
            }
        };

        for (int i = 31; i >= 0; i--)
        {
            if (checkALL(i) == 1)
            {
                res[i] = 1;
                declALL(i);
            }
            else
                res[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < res.size(); i++)
            ans += res[i] * (1LL << i);
        // cout << ans << "\n";
        return ans;
    }
};
class so
{
private:
public:
    int solve(int n,vector<pair<int, int>> itv)
    {
        int maxans = 0;
        auto dfs = [&](auto self,int pn,int i) -> void {
            int tM = 0;
            if(i >= n) {
                maxans = max(maxans,pn);
                return;
            }
            for(int j = itv[i].fi;j <= itv[i].se;j ++)
                self(self,pn & j,i+1);
        };
        for(int iff= itv[0].fi;iff <= itv[0].se;iff ++) dfs(dfs,iff,1);
        return maxans;
    }
};

signed main()
{
        srand(114514);
    for(;;)
    {
        int n = 4;
        vector<pair<int, int>> itv;
        int r = 0;
        for(int i = 0;i < 4;i ++) itv.pb({r = rand()%10,r + rand()%10});
        s1 a;
        int t1 = a.solve(n,itv);
        so b;
        int t2 = b.solve(n,itv);
        if(t1 != t2) {
            cout << "EX\n";
            for(auto x:itv) cout << x.fi << " " << x.se << "\n";
            cout << t1 << " " << t2 << "\n";
            system("pause");
        } else cout << "ct..";
    }
}