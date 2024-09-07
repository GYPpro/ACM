// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

#define set unordered_set
#define map unordered_map

#include <map>
#include <set>
#pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<int>> cnj(n+1);
        map<pii,int> wei;
        lop(i,0,m)
        {
            int u,v;
            cin >> u >> v;
            cnj[u].pb(v);
            cnj[v].pb(u);
            int w;
            cin >> w;
            wei[{min(u,v),max(u,v)}] = w;
        }
        lop(i,2,n+1)
        {
            cnj[1].pb(i);
            if(wei[{1,i}] == 0)wei[{1,i}] = k*(1|i);
            m ++;
        }
        vector<int> dis(n+1);
        lop(i,1,n+1) dis[i] = k*(1|i);
        // vector<int> vst(n+1);
        // auto dfs = [&](auto self,int p) -> void {
        //     vst[p] = 1;
        //     for(auto v:cnj[p])
        //     {
        //         if(vst[v]) continue;
        //         self(self,v);
        //     }
        // };
        // vector<int> 
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        while(pq.size()) pq.pop();
        pq.push({0,1});
        lop(i,2,n+1)
        {
            pq.push({dis[i],i});
        }
        dis[1] = 0;
        while(pq.size())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dis[u]) continue;
            for(auto v:cnj[u])
            {
                if(dis[v] > dis[u] + wei[{min(u,v),max(u,v)}])
                {
                    dis[v] = dis[u] + wei[{min(u,v),max(u,v)}];
                    pq.push({dis[v],v});
                }
            }
        }
        while(pq.size()) pq.pop();
        pq.push({0,1});
        lop(i,2,n+1)
        {
            pq.push({dis[i],i});
        }
        dis[1] = 0;
        while(pq.size())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dis[u]) continue;
            for(auto v:cnj[u])
            {
                if(dis[v] > dis[u] + wei[{min(u,v),max(u,v)}])
                {
                    dis[v] = dis[u] + wei[{min(u,v),max(u,v)}];
                    pq.push({dis[v],v});
                }
            }
        }
        while(pq.size()) pq.pop();
        pq.push({0,1});
        lop(i,2,n+1)
        {
            pq.push({dis[i],i});
        }
        dis[1] = 0;
        while(pq.size())
        {
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dis[u]) continue;
            for(auto v:cnj[u])
            {
                if(dis[v] > dis[u] + wei[{min(u,v),max(u,v)}])
                {
                    dis[v] = dis[u] + wei[{min(u,v),max(u,v)}];
                    pq.push({dis[v],v});
                }
            }
        }
        lop(i,2,n+1)
        {
            cout << min(dis[i],k*(1|i)) << " ";
        }
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}