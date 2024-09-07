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
        int n,m;
        cin >> n >> m;
        map<string,int> s2i = {
            {"above",0}, {"below",1},
            {"left",2},  {"right",3},
        };
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        vector<int> rev = {3,2,1,0};
        map<char,vector<int>> flt = {
            {'-',{0,1,3,2}},
            {'|',{1,0,2,3}},
            {'/',{2,3,0,1}},
            {'\\',{3,2,1,0}},
        };
        vector<vector<char>> M(n,vector<char>(m));
        for(auto &x:M)
            for(auto &y:x)
                cin >> y;
        vector<vector<vector<int>>> mem(4,vector<vector<int>>(n,vector<int>(m)));

        auto gtm = [&](pii a) -> int {
            return M[a.first][a.se];
        };
        int q;
        cin >> q;
        while(q--){
            set<pii> vst;
            auto dfs = [&](auto self,pii p,int inv,pii & rtv,pii f,int fotv) -> pii {
                rtv = p;
                if(p.first < 0 || p.first >= n || p.second < 0 || p.second >= m) return{0,0};
                int v = flt[gtm(p)][inv];
                if(p == f && v == fotv) return {1,0};
                pii np = {p.fi + dx[v],p.se + dy[v]};
                auto rt = self(self,np,rev[v],rtv,f,fotv);
                int t = (vst.find(p) != vst.end() && v == rev[inv]);
                mem[v][p.fi][p.se] = rt.se + t; 
            };
        }
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