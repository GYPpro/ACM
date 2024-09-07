// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cnj(n+1);
        lop(i,0,m)
        {
            int u,v;
            cin >> u >> v;
            cnj[u].pb(v);
            cnj[v].pb(u);
        }
        vector<int> vis(n+1,0);
        vector<int> lock(n+1,0);
        int ttlmx = 0;
        
        auto dfs = [&](auto self,int p,int f,int cur) -> int {
            // if(lock[p]) return 0;
            // cout << "et:" << p << "\n";
            // int maxn = 1;
            // int maxn = cur;
            ttlmx = max(ttlmx,cur);
            // vis[p] = 1;
            lock[p]=1;
            vector<int> xx;
            for(auto x:cnj[p]) if(!lock[x]) xx.pb(x);
            for(auto x:xx) lock[x] = 1;
            for(auto x:xx)
            {
                // if(x != f) {
                    // lock[x] = 0;
                    self(self,x,p,cur+1);
                    // lock[x] = 1;
                // }
            }
            for(auto x:xx) lock[x] = 0;
            // vis[p]=0;1
            return 1 ;
        };
        lop(i,1,n+1){
            // cout << "\n----dfs:" << i << "-----\n";
            lop(j,0,n+1) vis[j] = 0,lock[j] = 0;
            // ttlmx = max(ttlmx,dfs(dfs,i,0));
            dfs(dfs,i,0,1);
            // lop(j,0,n+1) vis[j] = 0,lock[j] = 0;
            // cout << "res: " << dfs(dfs,i,0) << " ";
        }
        cout << ttlmx << "\n";
        // cout << dfs(dfs,1,0);
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
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