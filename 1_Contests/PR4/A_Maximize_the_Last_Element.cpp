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

        vector<vector<int>> cnj;

        /*
        
        cnj[1] : [2,3]
        cnj[2]:[1,...]
        */
        vector<int> vst();

    void dfs(int p)
    {
        if(vst[p]) return;
        vst[p] = 1;
        for(int i = 1;i <= n;i ++) dfs(cnj[p][i]);
    }
public:
    void solve()
    {
        cin >> n;
        vector<int> a(n);
        lop(i,0,n) cin >> a[i];
        vector<pii> mp;
        lop(i,0,n) mp.pb({a[i],i});
        sort(all(mp));
        int mexans = 0;
        for(auto x:mp)
        {
            // cout << x.fi << " " << x.se << "\n";
            if(x.se %2 == 0 && (n-x.se-1)%2 == 0) mexans = max(mexans,x.fi);
            // else break;
        }
        // auto dfs = [&](auto self,int p,int f) -> int { //p 从f来
        //     if(vst[p]) return;
        //     vst[p] = 1;
        //     for(auto x:cnj[p]) if(x != f) self(self,x,p);
        // };

        dfs(dfs,1,0); //1 0 
        //；[1,0] -> [2,1] -> [NIL] ...-> [3,1]

        cout << mexans << "\n";
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
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}