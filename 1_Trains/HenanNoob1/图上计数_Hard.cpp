// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) pii({min(u ,v ),max(u ,v )})
using namespace std;
const int MAXN = 4e5+7;

int low[MAXN], dfn[MAXN], dfs_clock;
bool isbridge[MAXN];
vector<int> G[MAXN];
int cnt_bridge;
int father[MAXN];
int vis[MAXN];
void tarjan(int u, int fa) {
vis[u] = 1;
  father[u] = fa;
  low[u] = dfn[u] = ++dfs_clock;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        isbridge[v] = true;
        ++cnt_bridge;
      }
    } else if (dfn[v] < dfn[u] && v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        // std::iota(f.begin(), f.end(), 0);
        for(int i = 0;i < n;i ++) f[i] = i;
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve()
{
    int n,m;
    cin >> n >> m;
    lop(i,1,m+1)
    {
        int u,v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    DSU dsu(n+1);
    lop(i,1,n+1)
    {
        if(!vis[i]) {
            tarjan(i,i);
        }
    }
    // lop(i,1,n+1) if(isbridge[i]) cout << i << " " << father[i] << "\n";
    vector<vector<int>> cnj(n+1);
    lop(i,1,n+1)
    {
        lop(j,0,G[i].size())
        {
            if(
                (isbridge[i] ) && ord(i,G[i][j]) == ord(i,father[i]) || 
                (isbridge[G[i][j]] ) && ord(i,G[i][j]) == ord(G[i][j],father[G[i][j]])
                ) {
                // cout << "deled" << i << " " << father[i] << "\n";
                continue;
                }
            else cnj[i].pb(G[i][j]),cnj[G[i][j]].pb(i);
        }
    }
    vector<int> lgs;
    vector<int> pst(n+1);
    function<void(int)> dfs = [&](int p) -> void {
        if(pst[p]) return;
        pst[p] = 1;
        for(auto x:cnj[p]) dsu.merge(p,x),dfs(x);
    };
    set<int> geted;
    lop(i,1,n+1) if(!pst[i]) dfs(i);
    lop(i,1,n+1)
    {
        if(geted.find(dsu.find(i)) != geted.end()) continue;
        geted.insert(dsu.find(i));
        lgs.pb(dsu.size(i));
    }
    // for(auto x:lgs) cout << x << " ";cout << "\n";
    int lsum = 0,rsum = 0;
    sort(all(lgs));
    for(int i = (int)lgs.size()-1;i >= 0;i --)
    {
        if(lsum > rsum) rsum += lgs[i];
        else lsum += lgs[i];
    }
    cout << lsum * rsum << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
