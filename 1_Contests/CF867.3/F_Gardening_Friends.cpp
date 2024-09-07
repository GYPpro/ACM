#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define ll long long
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
        int n,k,c;
        cin >> n >> k >> c;
        vector<vector<int>> tr(n+1);
        for(int i = 0;i < n-1;i ++)
        {
            int u,v;
            cin >> u >> v;
            tr[u].pb(v);
            tr[v].pb(u);
        }

        vector<int> deepth(n+1,0);
        vector<int> iflef(n+1);
        
        auto dep = [&](auto self,int f,int p) -> int{
            int minn = INT_MAX;
            for(auto x:tr[p])
                if(x != f) minn = min(minn,self(self,p,x));
            if(minn == INT_MAX) return 1;
            else return deepth[p] = minn;
        };

        auto bfs = [&](auto self,int f,int p) -> int{
            if(deepth[p]) return deepth[p];
            deepth[p] = deepth[f] +1;
            if(tr[p].size() == 1 && tr[p][0] == f) iflef[p] = 1;
            for(auto x:tr[p])
                if(x != f) self(self,p,x);
            return 0;
        };

        // auto maxdep = [&](auto self,int f,int p) -> int{
        //     int maxn = 1;
        //     for(auto x:tree[p])
        //         if(x != f) maxn = max(maxn,self(self,p,x));
        //     return maxn;
        // };


        vector<int> deep(n+1); //: deep[i]为i结点的深度
        vector<vector<int>> fa(n+1); //: fa[i][j]为i的第2^i个祖先结点
        fa[0].resize(32);
        // fa:lca倍增值 deep:深度 tr:树
        auto dfs = [&](auto self,int fno,int root) -> void{
            fa[root].push_back(fno);
            deep[root] = deep[fa[root][0]] + 1;
            for (ll i = 1; i < 31; i++)
            {
                fa[root].push_back(fa[fa[root][i - 1]][i - 1]);
            }
            ll sz = tr[root].size();
            for (ll i = 0; i < sz; i++) // 遍历子节点
            {
                if (tr[root][i] == fno)
                    continue;
                self(self,root, tr[root][i]);
            }
            return;
        };

        auto lca = [&](int u,int v) -> int{
            if (deep[u] > deep[v])
            {
                ll swap = u;
                u = v;
                v = swap;
            }
            ll tmp = deep[v] - deep[u];
            for (ll j = 0; tmp; j++, tmp >>= 1)
            {
                if (tmp & 1)
                    v = fa[v][j];
            }
            if (u == v)
                return v;
            for (ll j = 30; j >= 0 && v != u; j--)
            {
                if (fa[u][j] != fa[v][j])
                {
                    u = fa[u][j];
                    v = fa[v][j];
                }
            }
            return fa[u][0]; // 返回最近公共祖先
        };

        // cout << max(maxdep * k,maxdep + mindep)
        // bfs(bfs,0,1);
        dfs(dfs,0,1);
        auto dis = [&](int u,int v) -> int{
            int t = lca(u,v);
            return abs(deep[t]-deep[u]) + abs(deep[t]-deep[v]);
        };

        bfs(bfs,0,1);
        // for(int i = 1;i <= n;i ++)

        int rf = 0,re = 0;
        int maxdep = 0;
        int maxdepidx = 0;
        // for(auto x:deepth) maxdep = max(maxdep,x);
        // int mindep = INT_MAX;
        for(int i = 1;i <= n;i ++)
            if(deepth[i] > maxdep && iflef[i] == 1){
                maxdep = deepth[i];
                maxdepidx = i;
            }
        rf = maxdepidx;
        // for(auto x:deepth) cout << x << " ";cout << "\n";
        deepth.clear();
        deepth.clear();
        deepth.resize(n+1);
        // cout << mindepidx << "\n";
        bfs(bfs,0,rf);
        for(int i = 1;i <= n;i ++)
            if(deepth[i] > maxdep && iflef[i] == 1){
                maxdep = deepth[i];
                maxdepidx = i;
            }
        re = maxdepidx;
        // int maxdepn = 0;
        // for(auto x:deepth) maxdepn = max(maxdepn,x);
        // for(auto x:deepth) cout << x << " ";cout << "\n";
        int maxans = max(dis(1,re),dis(1,rf));
        for(int i = 1;i <= n;i ++)
            maxans = max(max(dis(i,re),dis(i,rf)) *k -  dis(i,1) * c,maxans);
        // cout << max((maxdep-1) * k,(maxdepn-1) * k - (maxdep-1) * c) << "\n"; 
        cout << maxans << "\n";
        // FI cout << "i:" << i+1 << " lca to re "  << re  << ": "<< lca(i+1,re)<<  " lca to rf "  << rf  << ": "<< lca(i+1,rf) << " maxdis:" <<max(dis(i,re),dis(i,rf))<< "\n";
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