#define D

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

bool comp(int a,int b) {return a < b;}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> cnj(n+1);
    lop(i,0,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w,0});
        cnj[v].pb({u,w,0});
    }
    lop(i,0,k)
    {
        int v,w;
        cin >> v >> w;
        cnj[1].pb({v,w,1});
        cnj[v].pb({1,w,1});
    }
    priority_queue<pair<int,pii> ,vector<pair<int,pii>> ,greater<pair<int,pii>> > q;
    vector<int> dis(n+1,INF);
    vector<int> locked(n+1,0);
    int cnt = 0;
    q.push({0,{0,1}});
    while(q.size())
    {
        auto [w,_] = q.top();
        auto [rutetype,p] = _;
        q.pop();
        if(locked[p]) continue;
        locked[p] = 1;
        // if(dis[p] <= w) continue;
        // dis[p] = w;
        if(rutetype) cnt ++;
        for(auto x:cnj[p])
        {
            if(dis[x[0]] > x[1] + w) {
                dis[x[0]] = x[1] + w;
                q.push({x[1] + w,{x[2],x[0]}});
            }
        }
        // auto [w,[rutetype,p]] = q.top();
    }
    cout << k-cnt << "\n";
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