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
    vector<vector<pii>> cnj2(n+1);
    lop(i,1,m+1)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w});
        cnj2[v].pb({u,w});
    }
    // priority_queue<pii,vector<pii>,greater<pii>> q;
    set<pii> q;
    vector<int> dis(n+1,INF);
    vector<int> LOCK(n+1,0);
    dis[1] = 0;
    q.insert({0,1});
    while(q.size())
    {
        pii _ = *q.begin();
        int p = _.se;
        q.erase(_);
        for(auto x:cnj[p]) {
            int t = x.fi,w = x.se;
            if(LOCK[t]) continue;
            q.erase({dis[t],t});
            dis[t] = min(dis[t],dis[p]+w);
            q.insert({dis[t],t});
        }
        LOCK[p] = 1;
    }
    // priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> dis2(n+1,INF);
    vector<int> LOCK2(n+1,0);
    dis2[1] = 0;
    q.insert({0,1});
    while(q.size())
    {
        pii _ = *q.begin();
        int p = _.se;
        q.erase(_);
        for(auto x:cnj2[p]) {
            int t = x.fi,w = x.se;
            if(LOCK2[t]) continue;
            q.erase({dis2[t],t});
            dis2[t] = min(dis2[t],dis2[p]+w);
            q.insert({dis2[t],t});
        }
        LOCK2[p] = 1;
    }

    int sum = 0;
    lop(i,2,n+1) sum += dis[i] + dis2[i];
    cout << sum << "\n";
    
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
