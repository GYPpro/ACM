// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

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
    int n,m,hs;
    cin >> n >> m >> hs;
    vector<int> h(n+1);
    while(hs--)
    {
        int t;
        cin >> t;
        h[t] = 1; 
    }
    vector<vector<pii>> cnj(n+1);
    lop(i,0,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        cnj[u].pb({v,w});
        cnj[v].pb({u,w});
        // int u,v,w;
    }

    int ans = INF;
    vector<int> dis,dis2,LOCK;
    auto dij = [&](int ini) -> vector<int> {
        dis.clear(),dis2.clear(),LOCK.clear();
        dis.resize(n+1,INF),dis2.resize(n+1,INF);
        LOCK.resize(n+1,0);
        set<array<int,3>> q,q2;
        q.insert({0,ini,h[ini]});
        dis[ini] = 0;
        while(q.size())
        {
            auto [_,u,f] = *q.begin();
            q.erase(q.begin());
            f |= h[u];
            if(f) q2.insert({_,u,f});
            for(auto [v,w]:cnj[u])
            {
                if(dis[v] > dis[u] + (w/(1+f)))
                {
                    q.erase({dis[v],v,f});
                    dis[v] = dis[u] + (w/(1+f));
                    q.insert({dis[v],v,f});
                }
            }
        }
        while(q2.size())
        {
            auto [_,u,f] = *q2.begin();
            q2.erase(q2.begin());
            f |= h[u];
            if(dis2[u] == INF) dis2[u] = _;
            if(LOCK[u]) continue;
            LOCK[u] = 1;
            // if(f) q2.push({_,u,f});
            for(auto [v,w]:cnj[u])
            {
                // if(LOCK[v]) continue;
                if(dis2[v] > dis2[u] + (w/(1+f)))
                {
                    q2.erase({dis2[v],v,f});
                    dis2[v] = dis2[u] + (w/(1+f));
                    q2.insert({dis2[v],v,f});
                }
            }
        }
        vector<int> rt(n+1);
        lop(i,1,n+1) rt[i] = min(dis[i],dis2[i]);
        return rt;
    };
    auto rt1 = dij(1),rt2 = dij(n);
    lop(i,1,n+1) ans = min(max(rt1[i],rt2[i]),ans);
    cout << (ans == INF ? -1:ans) << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(3)

// #include <bits/stdc++.h>
// #define int long long
// #define pii pair<int,int>
// #define pb push_back
// #define fi first
// #define se second
// const int INF = 1145141919810LL;
// #define lop(i, a, b) for(int i = a; i < b ; i++) 
// #define all(x) x .begin(), x .end()
// #define ord(u, v) {min(u ,v ),max(u ,v )}
// using namespace std;

// void solve()
// {
//     int n,m,hs;
//     cin >> n >> m >> hs;
//     vector<int> h(n+1);
//     while(hs--)
//     {
//         int t;
//         cin >> t;
//         h[t] = 1; 
//     }
//     vector<vector<pii>> cnj(n+1);
//     lop(i,0,m)
//     {
//         int u,v,w;
//         cin >> u >> v >> w;
//         cnj[u].pb({v,w});
//         cnj[v].pb({u,w});
//         // int u,v,w;
//     }

//     int ans = INF;
//     vector<int> dis(n+1,INF),dis2(n+1,INF);
//     auto dij = [&](int ini) -> vector<int> {
//         dis.clear()
//         dis.resize(n+1,INF),dis2.resize(n+1,INF);
//         priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q,q2;
//         q.push({0,ini,h[ini]});
//         dis[ini] = 0;
//         vector<int> LOCK(n+1);
//         while(q.size())
//         {
//             auto [_,u,f] = q.top();
//             q.pop();
//             f |= h[u];
//             if(f) q2.push({_,u,f});
//             for(auto [v,w]:cnj[u])
//             {
//                 if(LOCK[v]) continue;
//                 if(dis[v] > dis[u] + (w/(1+f)))
//                 {
//                     dis[v] = dis[u] + (w/(1+f));
//                     q.push({dis[v],v,f});
//                 }
//             }
//         }
//         while(q2.size())
//         {
//             auto [_,u,f] = q2.top();
//             q2.pop();
//             f |= h[u];
//             if(dis2[u] == INF) dis2[u] = _;
//             // if(f) q2.push({_,u,f});
//             for(auto [v,w]:cnj[u])
//             {
//                 if(LOCK[v]) continue;
//                 if(dis2[v] > dis2[u] + (w/(1+f)))
//                 {
//                     dis2[v] = dis2[u] + (w/(1+f));
//                     q2.push({dis2[v],v,f});
//                 }
//             }
//         }
//         vector<int> rt(n+1);
//         lop(i,1,n+1) rt[i] = min(dis[i],dis2[i]);
//         return rt;
//     };
//     auto rt1 = dij(1),rt2 = dij(n);
//     lop(i,1,n+1) ans = min(max(rt1[i],rt2[i]),ans);
//     cout << (ans == INF ? -1:ans) << "\n";
// }

// signed main()
// {
// #ifndef D
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cout.tie(0);
// #endif
//     int T = 1;
//     cin >> T;

//     for (int i = 0; i < T; i++) solve();

//     // system("pause");

//     return 0;
// }
