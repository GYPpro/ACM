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
        int n;
        cin >> n;
        vector<vector<int>> cnj(n+1);
        vector<int> wei(n+1);
        for(int i = 1;i <= n;i ++) cin >> wei[i];
        for(int i = 0;i < n-1;i ++){
            int u,v;
            cin >> u >> v;
            cnj[u].pb(v);
            cnj[v].pb(u);
        }
        vector<__int128> c(n+1);
        vector<__int128> nc(n+1);
        vector<int> FD(n+1);

        __int128 cnt = 0;
        for(auto x:wei) cnt += x;
        
        auto dfs = [&](auto self,int p,int f) -> void {
            nc[p] = 0;
            c[p] = (__int128)wei[p];
            // if(wei[p] == 0) FD[p] = 1;
            // FD[p] = 1;
            for(auto x:cnj[p])
            {
                if(x == f) continue;
                self(self,x,p);
                // Sc += c[x];
                c[p] += nc[x];
                if(nc[x] > c[x]) FD[x] = 1;
                // else FD[x] = 0;
                nc[p] += max(nc[x],c[x]);
            }
        };
        auto check = [&]() -> bool{
            for(auto x:wei) if(x) return 0;
            return 1;
        };
        // auto drop = [&](auto self,bool st,int p,int f) -> void {
        //     if(FD[p]) st = 1;
        //     else st = 0;
        //     wei[p] = ((int)st) * wei[p];
        //     for(auto x:cnj[p])
        //         if(x != f)
        //             self(self,st,x,p);
        // };

        __int128 DMG = cnt;
        while(!check()){
            for(auto &x:FD) x = 0;
            for(auto &x:nc) x = 0;
            for(auto &x:c) x = 0;
            int rt = 1;
            // for(int i = 1;i <= n;i ++)
            for(int i = n;i >= 0;i --)
            {
                if(wei[i] != 0) {rt = i;break;}
            }
            dfs(dfs,rt,0);
            // cnt -= max(nc[rt],c[rt]);
            // if(nc[rt] > c[rt]) drop(drop,1,rt,0);
            // drop(drop,1,rt,0);
            for(auto x:FD) cout << x << " " ;cout << "\n";
            // system()
            for(int i = 1;i <= n;i ++) if(FD[i]) wei[i] = 0;
            cnt = 0;
            for(auto x:wei) cnt += x;
            DMG += cnt;
            // for(auto x:wei) cout << x << " ";cout << "\n";
        }
        // cout << DMG << "\n";
        string s;
        while(DMG) {
            s.pb('0'+(DMG%10));
            DMG /= 10;
        }
        for(int i = s.size()-1;i >= 0;i --) cout << s[i];
        cout << "\n";

    }
};

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

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