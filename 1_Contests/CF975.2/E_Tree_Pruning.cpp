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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> cnj(n+1);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    vector<int> fa(n+1);
    vector<set<int>> leaf(n+1);
    using itf = function<void(int,int)>;
    itf dfs1 = [&](int p,int f) -> void {
        fa[p] = f;
        for(auto x:cnj[p]) if(x == f) continue;
        else {
            leaf[p].insert(x);
            dfs1(x,p);
        }
    };
    dfs1(1,0);
    int ans = n-1;
    int cur = n-1;
    vector<int> leafs(1,1);

    auto erase = [&](int i) -> int {
        int cnt = 1;
        while(leaf[fa[i]].size() >= 1 && i != 1) // > 1 break
        {
            leaf[fa[i]].erase(i);
            if(leaf[fa[i]].size() > 0) break;
            i = fa[i];
            cnt ++;
        }
        return cnt;
    };

    vector<int> newl;
    while(leafs.size())
    {
        newl.clear();
        for(auto x:leafs)
        {
            if(leaf[x].size() == 0) cur += erase(x);
            else for(auto v:leaf[x]) newl.pb(v),cur--;
        }
        ans = min(ans,cur);
        leafs = newl;
    }
    cout << ans << "\n";
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
