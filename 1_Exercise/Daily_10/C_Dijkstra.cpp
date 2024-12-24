// // #pragma GCC optimize(2)

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update>;
// // #define int long long
// #define pii pair<int,int>
// #define pb push_back
// #define fi first
// #define se second
// const int INF = 1145141919810LL;
// #define lop(i, a, b) for(int i = a; i < b ; i++) 
// #define all(x) x .begin(), x .end()
// #define ord(u, v) {min(u ,v ),max(u ,v )}
// // #define set unordered_set
// // #define map unordered_map

// void solve()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<vector<pii>> cnj(n+1);
//     lop(_,0,m)
//     {
//         int u,v,w;
//         cin >> u >> v >> w;
//         cnj[u].pb({v,w});
//         cnj[v].pb({u,w});
//     }
//     set<pii> q;
//     q.insert({0,1});
//     vector<int> LOCK(n+1);
//     vector<int> path;
//     vector<int> dis(n+1,INF);
//     vector<int> CRT(n+1);
//     dis[1] = 0;
//     while(q.size())
//     {
//         auto [cur,u] = *q.begin();
//         q.erase(q.begin());
//         if(!LOCK[u]) LOCK[u] = 1;
//         else continue;
//         for(auto [v,w]:cnj[u])
//         {
//             if(LOCK[v]) continue;
//             if(dis[v] > dis[u]+w) {
//                 q.erase({dis[v],v});
//                 dis[v] = dis[u]+w;
//                 q.insert({dis[v],v});
//                 CRT[v] = u;
//             }
//         }
//     }
//     // using itf = function<int(int,int)>;
//     // itf dfs = [&](int p,int f) -> int {
//     //     if(p == 1) return 1;
//     //     for(auto x:CRT[p])
//     // };
//     // for(auto x:CRT) cout << x << " ";
//     int ptr = n;
//     while(ptr != 1) path.pb(ptr),ptr = CRT[ptr];
//     path.pb(1);
//     reverse(all(path));
//     for(auto x:path) cout << x << " ";cout << "\n";
// }

// signed main()
// {
// #ifdef FC
//     freopen("G.A.in","r",stdin);
//     freopen("G.A.ptc","w",stdout);
// #endif
// #ifndef FC
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cout.tie(0);
// #endif
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();
//     return 0;
// }
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
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> cnj(n+1);
    lop(_,0,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w});
        cnj[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    vector<int> LOCK(n+1);
    vector<int> path;
    vector<int> dis(n+1,INF);
    vector<int> CRT(n+1);
    dis[1] = 0;
    while(q.size())
    {
        auto [cur,u] = q.top();
        q.pop();
        if(!LOCK[u]) LOCK[u] = 1;
        else continue;
        for(auto [v,w]:cnj[u])
        {
            if(LOCK[v]) continue;
            if(dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
                CRT[v] = u;
            }
        }
    }
    // using itf = function<int(int,int)>;
    // itf dfs = [&](int p,int f) -> int {
    //     if(p == 1) return 1;
    //     for(auto x:CRT[p])
    // };
    // for(auto x:CRT) cout << x << " ";
    if(dis[n] == INF) {
        cout << "-1\n";
        return;
    }
    int ptr = n;
    while(ptr != 1) path.pb(ptr),ptr = CRT[ptr];
    path.pb(1);
    reverse(all(path));
    for(auto x:path) cout << x << " ";cout << "\n";
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
