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

// #define int long long
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
        // cout << "===\n";
        int n;
        cin >> n;
        // vector<int> pa(n+1),dep(n+1),md(n+1),tail(n+1);
        vector<int> pa(n+1),md(n+1),lzt(n+1);
        for(int i = 1;i <= n;i ++) pa[i] = i;
        // for(int i = 1;i <= n;i ++) tail[i] = i;
        int Q = n-1;
        while(Q--)
        {
            // #define D
            int a,b,q;
            cin >> a >> b >> q;
            #ifdef D
            cout <<" ---- "<<  n-Q << " -------------------\n";
            for(auto x:pa) cout << x << " "; cout << "\n";
            // for(auto x:dep) cout << x << " "; cout << "\n";
            for(auto x:md) cout << x << " "; cout << "\n";
            #endif
            int t = b;
            pa[b] = a;
            int f = t;
            lzt[t] =max(0, md[t]-md[pa[t]] +1);
            while(pa[t] != t)
            {
                if(md[pa[t]] < md[t]) md[pa[t]] = md[t] + lzt[t],lzt[t] = 0;
                else lzt[t] = max(0,md[t]-md[pa[t]]+1),md[t] = md[pa[t]]-1;
                // int div = md[pa[t]]-md[t];
                // if(div < 0) md[pa[t]] = max(md[t] + lzt[t],md[pa[t]]);
                // lzt[t] -= div;
                // if(lzt[t] > md[pa[t]]-md[t]) md[pa[t]] = lzt[t]+md[t],lzt[t] -= md[pa[t]]-md[t];
                // else md[pa[t]] = md[pa[t]];
                
                lzt[pa[t]] = lzt[t];
                lzt[t] = 0;
                // md[pa[t]] += lzt[t];
                // lzt[t] = 0;
                // md[pa[t]] += md[t];
                t = pa[t];
                pa[f] = pa[pa[f]];
                f = t;
                // md[pa[t]] = max(md[pa[t]],md[t]+1);
                // md[pa[t]] = md[t] + 1;
            }
            // md[t] --;
            // md[pa[b]] += md[b] + (b != t);
            // pa[b] = t;
            // t = b;
            // while(pa[t] != t)
            // {
            //     t = pa[t] = pa[pa[t]];
            // }
            
            // auto pusht = [&](auto self,int cur) -> int{
            //     if(pa[cur] == cur) return dep[cur];
            //     cout << "push:" << cur << "\n";
            //     // md[pa[pa[t]]] = max(md[pa[pa[t]]],dep[t]+md[pa[t]]);
            //     // int pvt = t;
            //     // t = pa[t];
            //     // pa[t] = pa[pa[t]];
            //     md[pa[cur]] = max(md[pa[cur]],md[cur]+1); 
            //     dep[cur] = self(self,pa[cur]) + 1;
            //     cout << "rt:" << cur << " " << md[pa[cur]] << " " << md[cur]+1 << "\n";
            //     pa[cur] = pa[pa[cur]];
            //     // if(dep[t] > md[pa[t]]) md[pa[t]] = md[t]+1;
            //     return dep[cur];
            // };
            // // md[pa[b]] = max(md[pa[b]],dep[b]);
            // pusht(pusht,t);
            // md[pa[t]] = max(md[pa[t]],md[t]+1);
            #ifndef D
            cout << md[q] << " ";
            #endif
            
            #ifdef D
            cout <<" ---- "<<  n-Q << " -------------------\n";
            for(auto x:pa) cout << x << " "; cout << "\n";
            // for(auto x:dep) cout << x << " "; cout << "\n";
            for(auto x:md) cout << x << " "; cout << "\n";
            #endif
        } cout << "\n";
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