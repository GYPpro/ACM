// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}

 struct HLD {
    int n, idx;
    vector<vector<int>> ver;
    vector<int> siz, dep;
    vector<int> top, son, parent;
    HLD(int n) {
        this->n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }
    void add(int x, int y) { // 建立双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs1(int x) {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y : ver[x]) {
            if (y == parent[x]) continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]]) {
                son[x] = y;
            }
        }
    }
    void dfs2(int x, int up) {
        top[x] = up;
        if (son[x]) dfs2(son[x], up);
        for (auto y : ver[x]) {
            if (y == parent[x] || y == son[x]) continue;
            dfs2(y, y);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                x = parent[top[x]];
            } else {
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }
    int clac(int x, int y) { // 查询两点间距离
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    void work(int root = 1) { // 在此初始化
        dfs1(root);
        dfs2(root, root);
    }
 };

void solve()
{
    int n,r,q;
    cin >> n >>  r >> q;
    HLD hld(n);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        hld.add(u,v);
    }
    hld.work(r);
    vector<int> fib = {1,1};
    while(fib.back() <= n*n)
    {
        int sz = fib.size()-1;
        fib.pb(fib[sz]  + fib[sz-1]);
    }
    while(q--)
    {
        int x,k;
        cin >> x >> k;
        vector<int> cat;
        int i = k;
        while(i < fib.size() && fib[i] + x <= n)
        {
            cat.pb(x+fib[i]);
            i ++;
        }
        if(cat.size() == 0) cout << "0\n";
        else if(cat.size() == 1) cout << cat.back() << "\n";
        else {
            int lc = hld.lca(cat[0],cat[1]);
            lop(j,2,cat.size()) lc = hld.lca(lc,cat[j]);
            cout << lc << "\n";
        }
    }
    
}
// 1 2 0 4 XNOR  p p*2+1
signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
//     cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
