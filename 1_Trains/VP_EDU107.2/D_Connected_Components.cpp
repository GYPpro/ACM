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
    
    void init(int n) {
        // n ++
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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> vis(n+1);
    vector<pair<int,set<int>>> o(n+1);
    DSU dsu(n+1);
    for(int i = 1;i <= n;i ++) o[i].fi = i;
    for(int i = 0;i < m;i ++){
        int u,v;
        cin >> u >> v;
        o[u].se.insert(v);
        o[v].se.insert(u);
    } 

    using itf = function<void(int)>;
    // vector<int> vis(n+1);
    // vector<int> unv;
    set<int> unv;
    for(int i = 1;i <= n;i ++) unv.insert(i);
    // for()
    vector<int> tmp;
    queue<int> q;
    // q.push(1);
    // for(int i = 1;i < n;i ++) q.pu
    for(int i = 1;i <= n;i ++)
    {
        if(unv.find(i) != unv.end()){
            q.push(i);
            while(q.size()){
                auto p = q.front();
                q.pop();
                tmp.clear();
                for(auto x:unv) if(o[p].se.find(x) == o[p].se.end()){
                    tmp.push_back(x);
                    dsu.merge(p,x);
                    q.push(x);
                }
                for(auto x:tmp) unv.erase(x);
            }
        }
    }
    // itf dfs = [&](int p) -> int {
    //     tmp.clear();
    //     for(auto )
    // };
    
    // // for(int i = 1;i <= n;i ++)
    // // {
    // //     cout << "i " << i << ":";
    // //     for(auto x:o[i].se) cout << x << " ";
    // //     cout << "\n";
    // // }
    // // vector<
    // sort(all(o),[](pair<int,set<int>> &a,pair<int,set<int>> &b){return a.se.size() < b.se.size();});
    // // cout <
    // // vector<int> tbm;
    // vis[0] = 1;
    // for(auto [idx,val]:o){
    //     if(vis[idx]) continue;
    //     // cout << idx << " : ";
    //     // for(auto x:val) cout << x << " ";cout << "\n"; 
    //     // tbm.clear();
    //     for(int i = 1;i <= n;i ++) if(val.find(i) == val.end())dsu.merge(idx,i),vis[i]=1;//,cout << i << " "; cout << "\n"
    //     // for(int i = 1;i <= n;i ++) cout << dsu.find(i) << " "; cout << "\n";
    // }
    vector<int> anss;
    for(auto &x:vis) x = 0;
    for(int i = 1;i <= n;i ++){
        // cout << dsu.find(i) << " "; 
        if(vis[dsu.find(i)] == 0) {
            anss.push_back(dsu.size(i));
            vis[dsu.find(i)] = 1;
        } else continue;
    }
    sort(all(anss));
    cout << anss.size() << "\n";
    for(auto &x:anss) cout << x << " ";cout << "\n";
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
