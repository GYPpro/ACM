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
    int n,m,s;
    cin >> n >> m >> s;
    vector<vector<pii>> cnj(n+1);
    lop(i,0,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w});
    }
    vector<int> dis(n+1,INF);
    vector<int> LOCK(n+1,0);
    using pwi = pair<int,int>;
    // priority_queue<pwi,vector<pwi>,greater<pwi>> q;
    set<pwi> q;
    q.insert({0,s});
    dis[s] = 0;
    while(q.size())
    {
        auto [_,cur] = *q.begin();
        q.erase(q.begin());
        if(LOCK[cur]) continue;
        LOCK[cur] = 1;
        for(auto [t,w]:cnj[cur])
        {
            if(dis[t] > w+dis[cur])
            {
                q.erase({dis[t],t});
                dis[t] = w + dis[cur];
                q.insert({dis[t],t});
            }
        }
    }
    lop(i,1,n+1) cout << dis[i] << " ";cout << "\n";
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
