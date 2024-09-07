// #define D


#pragma GCC optimize(2)

#include <bits/stdc++.h>
// #define set unordered_set
// #define map unordered_map
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;


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
    vector<set<int>> luncnj(n+1);// {tar,from,type}
    vector<vector<int>> cnj(n+1);// {tar,from,type}
    vector<pii> lun; //{tar,from}
    vector<pii> qie; //{tar,from}
    DSU dsu(n+1);
    lop(i,0,m)
    {
        int u,v;
        string type;
        cin >> u >> v >> type;
        bool t = type == "Lun"; 
        cnj[u].pb(v);
        cnj[v].pb(u);
        if(t) {
            luncnj[u].insert(v);
            luncnj[v].insert(u);
        }
        else qie.pb(ord(u,v));
    }
    priority_queue<int> q;
    lop(i,1,n+1) if(luncnj[i].size() == 1) q.push(i);
    auto removeEdge = [&](int u,int v) -> void {
        luncnj[u].erase(v); 
        luncnj[v].erase(u);
    };
    while (q.size())
    {
        auto p = q.top();
        q.pop();
        vector<pii> tbm;
        for(auto x:luncnj[p])
            tbm.pb({p,x});
        for(auto x:tbm)
            removeEdge(x.fi,x.se);
        for(auto x:tbm)
        {
            if(luncnj[x.fi].size() == 1) q.push(x.fi);
            if(luncnj[x.se].size() == 1) q.push(x.se);
        }
    }
    const int MAXN = n+1;
    vector<int> low(MAXN), dfn(MAXN);
    int dfs_clock = 0;
    vector<int> isbridge(n+1);
    vector<vector<int>> G(MAXN);
    int cnt_bridge = 0;
    vector<int> father(MAXN);
    lop(i,1,n+1)
    for(auto x:luncnj[i]) G[i].pb(x);

    auto tarjan = [&](auto self,int u, int fa)->void{
        father[u] = fa;
        low[u] = dfn[u] = ++dfs_clock;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (!dfn[v]) {
            self(self,v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                isbridge[v] = true;
                ++cnt_bridge;
            }
            } else if (dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
            }
        }
        return;
    };
    tarjan(tarjan,1,0);
    lop(i,1,n+1) {
        if(isbridge[i]) removeEdge(father[i],i);
    }
    lop(i,1,n+1)
    {
        for(auto x:luncnj[i])
        {
            dsu.merge(i,x);
        }
    }
    for(auto x:qie) {
        if(dsu.find(x.fi) != dsu.find(x.se))
        {
            dsu.merge(x.fi,x.se);
            luncnj[x.fi].insert(x.se);
            luncnj[x.se].insert(x.fi);
        }
    }
    set<pii> out;
    lop(i,1,n+1)
    {
        for(auto x:luncnj[i]) out.insert(ord(i,x));
    }
    bool check = 1;
    int rfi = dsu.find(1);
    lop(i,1,n+1) if(dsu.find(i) != rfi){check = 0;break;}
    if(check) cout << "YES\n";
    else {cout << "NO\n";return;}
    cout << out.size() << "\n";
    for(auto x:out) cout << x.fi << " " << x.se << "\n";
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
