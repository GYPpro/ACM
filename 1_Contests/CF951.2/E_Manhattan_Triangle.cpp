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
#define X first
#define Y second
#define pii pair<int,int>


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
        int n,d;
        cin >> n >> d;
        vector<pii> cod;
        FI cin >> cod[i].X >> cod[i].Y;
        FI {
            int tx = cod[i].X,ty = cod[i].Y;
            cod[i].X = tx+ty;
            cod[i].Y = tx-ty;
        }
        map<int,map<int,int>> cnt;
        map<pii,int> rev;
        int INF = 1145141919810LL;
        FI
        {
            auto x = cod[i];
            cnt[x.X][x.Y] ++;
            rev[x] = i;
            // minx = min(minx,x.X);
        }
        // auto check = [&](vector<int> &t) -> pii{
        //     map<int,int> ttcnt;
        //     for(auto x:t) ttcnt[x] ++;
        //     for(auto x:ttcnt) if(ttcnt[x.first + d] >= 0) return {x.X,x.X+d};
        //     return {INF,INF};
        // };

        auto qbf = [&](pii a,pii b) -> int{
            return max(abs(a.X-b.X),abs(a.Y - b.Y));
        };  

        bool f = 0;
        for(auto x:cnt)
        {
            if(!cnt[x.X].size()) continue;
            if(cnt[x.X+d].size())
            {
                for(auto y:cnt[x.X +d])
                {
                    if(cnt[x.X +d][y.first+d] >= 1)
                    {
                        pii a1 = {x.X,(*cnt[x.X].begin()).Y};
                        pii a2 = {x.X+d,y.first};
                        pii a3 = {x.X+d,y.first+d};
                        if(qbf(a1,a2) == qbf(a1,a3) && qbf(a1,a3) == qbf(a3,a1))
                        {
                            cout << rev[a1] << " " << rev[a2] << " " << rev[a3] << "\n";
                        }
                    }
                }
            }
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