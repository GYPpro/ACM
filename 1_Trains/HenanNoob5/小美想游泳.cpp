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
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> cnj(n+1);
    lop(i,1,m+1)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w});
        cnj[v].pb({u,w});
    }
    int s,tar;
    cin >> s >> tar;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> dis(n+1,INF);
    vector<int> LOCK(n+1,0);
    dis[s] = 0;
    q.push({0,s});
    while(q.size())
    {
        pii _ = q.top();
        int p = _.se;
        q.pop();
        for(auto x:cnj[p]) {
            int t = x.fi,w = x.se;
            if(LOCK[t]) continue;
            dis[t] = min(dis[t],max(dis[p],w));
            q.push({dis[t],t});
        }
        LOCK[p] = 1;
    }
    cout << dis[tar] << "\n";
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
