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
        int x,y,p,q;
        cin >> x >> y >> p >> q;
        vector<vector<vector<int>>> sta(x+1,vector<vector<int>>(y+1,{0,0}));
        // auto fst = [&](int lx,int ly,bool ps) -> int&{
        //     return sta[lx][ly][ps];
        // };
        auto chk = [&](int lx,int ly,bool ps) -> bool{
            // if(ps)
                if(x - lx + q >=  y - ly) return 1;
                else if(x - lx != 0) return 0;
                else return 1;
            // else if(lx + q >= ly) return 1;
            //     else return 0;
        };
        auto dfs = [&](int lx,int ly,bool ps,auto self) -> int{
            // if(ps) cout << lx << " " << ly << " " << x - lx <<" " << y-ly << " " << ps << "\n";
            // else cout << x - lx <<" " << y-ly << " " << lx << " " << ly << " " << ps << "\n";
            if(!chk(lx,ly,ps)){ return 1145141919810LL;} //cout << "--FL--\n";
            if(sta[lx][ly][ps]) return sta[lx][ly][ps];
            if(ps == 0 && lx == x) {return 1;} //cout << "--ED--\n";
            sta[lx][ly][ps] = 1145141919810LL;
            int t = 1145141919810LL;
            if(ps) for(int i = min(lx,p);i >= 0;i --)
                for(int j = 0;j <= min(ly,p-i);j ++)
                     t = min(t,self(x-lx+i,y-ly+j,!ps,self));
            // else for(int i = 0;i <= min(p,lx);i ++)
            //     t = min(t,self(x-lx+i,y-ly+min(ly,p-i),!ps,self));
            else for(int i = 0;i <= ly;i ++)
                t = min(t,self(x - lx,y - ly + i,!ps,self));
            // cout << "---rt---\n";
            // if(ps) cout << lx << " " << ly << " " << x - lx <<" " << y-ly << " " << ps << "\n";
            // else cout << x - lx <<" " << y-ly << " " << lx << " " << ly << " " << ps << "\n";
            return sta[lx][ly][ps] =  t + 1;
        };
        cout << (dfs(x,y,1,dfs) >= 1145141919810LL ? -1 : sta[x][y][1]-1) << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}