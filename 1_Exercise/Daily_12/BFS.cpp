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
// 
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> mtx(n+1,vector<bool>(m+1));
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            char c;
            cin >> c;
            mtx[i][j] = c == '.';
        }
    pii u,v;
    cin >> u.fi >> u.se >> v.fi >> v.se;
    int k;
    cin >> k;
    vector<vector<vector<pii>>> cnj(n+1,vector<vector<pii>>(m+1));
    for(int i = 0;i < k;i ++)
    {
        pii u,v;
        cin >> u.fi >> u.se >> v.fi >> v.se;
        cnj[u.fi][u.se].pb(v);
    }
    using tii = array<int,3>;
    vector<vector<int>> dis(n+1,vector<int>(m+1,INF));
    vector<vector<bool>> LOCK(n+1,vector<bool>(m+1));
    dis[u.fi][u.se] = 0;

    queue<tii> q;
    q.push({u.fi,u.se,0}); //[x,y,dis]
    auto ovf = [&](pii tr) -> bool {
        if(tr.fi <= 0 || tr.fi > n) return 1;
        if(tr.se <= 0 || tr.se > m) return 1;
        return 0;
    };

    while(q.size()) {
        auto [x,y,_] = q.front();
        q.pop();
        if(LOCK[x][y]) continue;
        LOCK[x][y] = 1;

        bool ifSKIP = 0;
        auto addTX = [&](pii u,pii v) -> void {
            auto [x,y] = u;
            auto [tx,ty] = v;
            if(ovf({tx,ty})) return;
            if(!ifSKIP) if(mtx[x][y] == 0) return;
            if(dis[tx][ty] > dis[x][y] + 1) {
                dis[tx][ty] = dis[x][y] + 1;
                q.push({tx,ty});
            }
        };

        ifSKIP = 1;
        for(auto [tx,ty]:cnj[x][y]) addTX({x,y},{tx,ty});
        ifSKIP = 0;
        addTX({x,y},{x+1,y});
        addTX({x,y},{x,y+1});
        addTX({x,y},{x-1,y});
        addTX({x,y},{x,y-1});
    }
    
    cout << (dis[v.fi][v.se] == INF ? -1 : dis[v.fi][v.se]) << "\n";
}

signed main()
{
#ifdef FC
    freopen("J.A.in","r",stdin);
    freopen("J.A.ptc","w",stdout);
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
