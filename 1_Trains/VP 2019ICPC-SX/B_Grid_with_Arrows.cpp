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
        int dl,dr;
        cin >> dl >> dr;
        vector<string> mtx(dl);
        vector<vector<int>> d(dl,vector<int>(dr));
        for(auto &x:mtx) cin >> x;
        for(auto &x:d)
            for(auto &y:x) cin >> y;
        
        auto c2i = [&](pair<int,int> cod) -> int {
            return cod.first * dr + cod.second + 1;
        };
        auto i2c = [&](int idx) -> pair<int,int> {
            return {idx/dl,idx%dl};
        };
        int n = dl * dr;
        vector<vector<int>> cnj(n+1);
        vector<int> idj(n+1);

        auto link = [&](int u,int v) -> void {
            cnj[u].pb(v);
            idj[v] ++;
        };

        for(int i = 0;i < dl;i ++)
            for(int j = 0;j < dr;j ++) {
                switch (mtx[i][j])
                {
                case 'u':
                {
                    if(i-d[i][j] >= 0) link(c2i({i, j}),c2i({i- d[i][j], j}));
                }
                    break;
                case 'd':
                {
                    if(i+d[i][j] < dl) link(c2i({i, j}),c2i({i+ d[i][j], j}));    
                }
                    break;
                case 'l':
                {
                    if(j-d[i][j] >= 0) link(c2i({i, j}),c2i({i, j-d[i][j]}));
                }
                    break;
                case 'r':
                {
                    if(j + d[i][j] < dr) link(c2i({i, j}) , c2i({i, j+d[i][j]}));
                }
                    break;
                
                default:
                    break;
                }
            }
        int bf = 1;
        int zec = 0;
        for(int i = 1;i <= n;i ++) 
        {
            if(idj[i] == 0) {bf = i;zec ++;}
        }
        if(zec > 1) {
            cout << "No\n";
            return;
        }
        vector<int> rc(n+1);
        auto dfs = [&](auto self,int p) -> void{
            if(rc[p]) return;
            rc[p] = 1;
            for(auto x:cnj[p]) self(self,x);
        };
        dfs(dfs,bf);
        for(int i = 1;i <= n;i ++) {
            if(rc[i] == 0) {cout << "No\n";return;}
        } 
        cout << "Yes\n";
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