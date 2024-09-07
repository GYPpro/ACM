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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> cnj(n+1);
        lop(i,0,m)
        {
            int u,v;
            cin >> u >> v;
            cnj[u].pb(v);
            cnj[v].pb(u);
        }
        vector<int> vst(n+1,0);
        vector<int> col(n+1,0);
        vector<int> set1,set2;
        bool ifbint = 1;
        auto dfs = [&](auto self,int p,bool f) -> void {
            if(vst[p]) {
                if(col[p] != f) ifbint = 0;
                return;
            }
            vst[p] = 1;
            if(f) set1.pb(p);
            else set2.pb(p);
            col[p] = f;
            for(auto x:cnj[p]) self(self,x,!f);
        }; 
        dfs(dfs,1,1);
        if(ifbint) {
            cout << "Bob" << "\n";
            int t = n;
            bool f = 1;
            while(t--)
            {
                int u,v;
                cin >> u >> v;
                pii cur = {min(u,v),max(u,v)};
                if(cur == pii({1,2})) 
                {
                    if(set1.size()) cout << set1[set1.size()-1] << " " << 1 << "\n",set1.pop_back();
                    else cout << set2[set2.size()-1] << " " << 2 << "\n",set2.pop_back();
                } else if(cur == pii({1,3})) 
                {
                    if(set1.size()) cout << set1[set1.size()-1] << " " << 1 << "\n",set1.pop_back();
                    else cout << set2[set2.size()-1] << " " << 3 << "\n",set2.pop_back();
                } else if(cur == pii({2,3})) 
                {
                    if(set2.size()) cout << set2[set2.size()-1] << " " << 2 << "\n",set2.pop_back();
                    else cout << set1[set1.size()-1] << " " << 3 << "\n",set1.pop_back();
                }
            }
        } else {
            cout << "Alice" <<"\n";
            lop(i,0,n) {cout << 1 << " " << 2 << "\n";
            int u,v;
            cin >> u >> v;}
        }
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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