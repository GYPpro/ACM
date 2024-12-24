// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }

    void clear() {
        int n = f.size();
        f.clear();
        f.resize(n);
        iota(all(f),0);
        siz.clear();
        siz.resize(n,1);
    }
    
    void init(int n) {
        f.resize(n);
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


int C(int x) {
    return (x)*(x-1) >> 1;
};

// class map_Tarjin

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> cnj(n+1);
    DSU dsu(n+1);
    set<pii> edges;
    lop(i,0,m)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
        dsu.merge(u,v);
        edges.insert(ord(u,v));
    }
    const int MAXN = n+5;
    vector<int> low(MAXN), dfn(MAXN);
    int dfs_clock = 0;
    vector<int> isbridge(MAXN);
    // vector<int> G[MAXN];
    int cnt_bridge = 0;
    vector<int> father(MAXN);
    using itf = function<void(int,int)>;
    itf tarjan = [&](int u, int fa) -> void{
        father[u] = fa;
        low[u] = dfn[u] = ++dfs_clock;
        for (int i = 0; i < cnj[u].size(); i++) {
            int v = cnj[u][i];
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
    };
    lop(i,1,n+1) if(!dfn[i]) tarjan(i,0);

    int ans = 0;
    set<int> ited;
    lop(i,1,n+1) if(ited.find(dsu.find(i)) != ited.end()) continue;
    else ans += C(dsu.size(i)),ited.insert(dsu.find(i));
    lop(i,1,n+1) if(isbridge[i]) edges.erase(ord(i,father[i]));
    dsu.clear();
    for(auto [u,v]:edges) dsu.merge(u,v);

    int mxctr = 0;
    vector<vector<int>> cnjN(n+1);
    int rt = INF;
    lop(i,1,n+1)
        if(isbridge[i])
            rt = min(rt,dsu.find(i)),
            cnjN[dsu.find(i)].pb(dsu.find(father[i])),
            cnjN[dsu.find(father[i])].pb(dsu.find(i));
    vector<int> swei(n+1);
    itf cacu = [&](int p,int f) -> void{
        swei[p] = dsu.size(p);
        for(auto x:cnjN[p]) if(x == f) continue;
        else {
            cacu(x,p);
            swei[p] += swei[x];
        }
        mxctr = max(mxctr, (n-swei[p]) * swei[p]);
    };
    if(rt != INF) cacu(rt,0);
    // lop(i,1,n+1) cout << swei[i] << " ";
    // cout << mxctr << " " << ans << "\n";
    // lop(i,1,n+1) cout << isbridge[i] << " "; cout << "\n";
    // lop(i,1,n+1) cout << father[i] << " "; cout << "\n";
    // lop(i,1,n+1) cout << dfn[i] << " "; cout << "\n";
    cout << ans - mxctr << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
