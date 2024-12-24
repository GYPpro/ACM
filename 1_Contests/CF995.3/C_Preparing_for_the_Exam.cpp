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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> que(m);
    map<int,int> qst;
    for(int i = 0;i < m;i ++)
    {
        int q;
        cin >> q;
        que[i] = q;
        // qst[q] = 1;
    }
    vector<int> vis(n+1,0);
    for(int i = 0;i < k;i ++)
    {
        int v;
        cin >> v;
        vis[v] = 1;
    }
    set<int> MM;
    for(int i = 1;i <= n;i ++) if(vis[i] == 0) MM.insert(i);

    for(auto x:que)
    {
        if(MM.find(x) != MM.end() && MM.size() == 1) cout << 1;
        else if(MM.size() == 0) cout << 1;
        else cout << 0;
    }cout << "\n";

    // for()
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
