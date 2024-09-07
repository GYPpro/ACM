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
#define fi first
#define se second


using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int n;
        cin >> n;
        // vector<vector<char>> mp(2,vector<char>(n));
        vector<char> mp(2 * n);
        for(auto &x:mp)
            cin >> x;
            // for(auto &y:x) cin >> y;
        // vector<vector<int>> vst(2,vector<int>(n));
        vector<int> vst(2 * n);
        int MAXCNJ = 0;
        auto ifcpm = [&](int k) -> bool {
            if (k >= 0 && k < 2 * n) return mp[k] == 'R';
            else return false; 
        };
        auto dfs = [&](auto self,int p,int f) -> int {
            if(vst[p]) return vst[p]-1;
            vst[p] = 1;
            vector<int> cnj = {(p+n)%(2 * n),(p == n-1 ? -1:p+1),(p%n == 0 ? -1:p-1)};
            // cout << "--" << p << "\n";
            // for(auto x:cnj) cout << x << " ";
            // cout << "\n";
            int MXT = 0;
            for(auto x:cnj)
            {
                if(!ifcpm(x) || x == f) continue;
                MXT = max(MXT,self(self,x,p));
                // MXT += self(self,x);
            }
            // vst[p] = 0;
            return MXT+1;
        };
        for(int i = 0;i < n;i ++)
        {
            
            if(!vst[i] && ifcpm(i)){
                int rt = dfs(dfs,i,-1)-1;
                // cout << i%n << " " << i/n << " : " << rt << "\n";
                MAXCNJ = max(MAXCNJ,rt);
            }

        }
        for(auto &x:vst) x = 0;
        for(int i = n;i < 2 * n;i ++)
        {
            
            if(!vst[i] && ifcpm(i)){
                int rt = dfs(dfs,i,-1)-1;
                // cout << i%n << " " << i/n << " : " << rt << "\n";
                MAXCNJ = max(MAXCNJ,rt);
            }

        }
        cout << MAXCNJ << "\n";
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