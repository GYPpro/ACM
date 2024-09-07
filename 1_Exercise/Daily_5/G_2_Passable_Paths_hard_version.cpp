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
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
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
        vector<vector<int>> tr(n + 1);
        vector<int> dep(n+1);
        vector<vector<int>> fa(n+1);
        fa[0] = vector<int>(32);
        for(int i = 0;i < n-1;i ++)
        {
            int u, v;
            cin >> u >> v;
            tr[u].pb(v);
            tr[v].pb(u);
        }
        // fa:lca倍增值 dep:深度 tr:树
        auto dfs = [&](int fno, int root,auto self) -> void
        {
            fa[root].push_back(fno);
            dep[root] = dep[fa[root][0]] + 1;
            for (int i = 1; i < 31; i++)
            {
                fa[root].push_back(fa[fa[root][i - 1]][i - 1]);
            }
            int sz = tr[root].size();
            for (int i = 0; i < sz; i++) // 遍历子节点
            {
                if (tr[root][i] == fno)
                    continue;
                self(root, tr[root][i],self);
            }
            return;
        };
        dfs(0,1,dfs);
        auto lca = [&](int u,int v) -> int{
            if (dep[u] > dep[v])
            {
                int swap = u;
                u = v;
                v = swap;
            }
            int tmp = dep[v] - dep[u];
            for (int j = 0; tmp; j++, tmp >>= 1)
            {
                if (tmp & 1)
                    v = fa[v][j];
            }
            if (u == v)
                return v;
            for (int j = 30; j >= 0 && v != u; j--)
            {
                if (fa[u][j] != fa[v][j])
                {
                    u = fa[u][j];
                    v = fa[v][j];
                }
            }
            return fa[u][0]; // 返回最近公共祖先
        };
        int q;cin >> q;
        while(q--)
        {
            vector<int> subl,subr;
            int k;
            cin >> k;
            vector<pair<int,int>> d2i;
            for(int i = 0;i < k;i ++)
            {
                int tmp;
                cin >> tmp;
                d2i.pb({dep[tmp],tmp});
            }
            sort(d2i);
            if(d2i.size() <= 2) {cout << "YES\n";continue;}
            subl.pb(d2i[d2i.size() -1].se);
            bool f = 1;
            for(int i = d2i.size() - 2;i >= 0;i --)
            {
                if(lca(d2i[i].se,subl[0]) != d2i[i].se)
                    if(subr.size())
                        if(lca(d2i[i].se,subr[0]) != d2i[i].se)
                            {cout << "NO\n";f = 0;break;}
                        else
                            subr.pb(d2i[i].se);
                    else subr.pb(d2i[i].se);
                else subl.pb(d2i[i].se);
            }
            if(!f) continue;
            if(subr.size()){
            if(lca(subl[0],subr[0]) == lca(subl[subl.size()-1],subr[0])) cout << "YES\n";
                else cout << "NO\n";}
            else cout << "YES\n";
        }
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