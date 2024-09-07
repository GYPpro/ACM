#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(3)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> cnj(n+1);
    vector<int> w(n+1);
    FI cin >> w[i+1];
    for(int i = 0;i < m;i ++)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    // map<int,int> cnt;
    // for(int i = 1;i <= n;i ++) cnt[i] ++;
    // vector<int> i2v;
    // vector<int> v2i(101);
    // for(auto x:cnt) i2v.push_back(x.first);
    // for(int i = 0;i < i2v.size();i ++)
    // int MEX = i2v.size();
    vector<vector<int>> cap(101,vector<int>(n+1,INT_MAX));
    vector<vector<int>> strd(101);
    FI {
        // for(int k = 100;k >= w[i+1];k --) strd[k].pb(i+1);
        strd[w[i+1]].pb(i+1);
    }
    set<int> LCK;
    for(int i = 1;i <= 100;i ++) 
    {
        // LCK.clear();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // auto inidt = strd[i];
        // // vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> pql;
        // // for(auto x:inidt){
        // //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqt;
        // //     pqt.push({0,x});
        // //     pql.pb
        // // }
        // if(inidt.size() == 0) continue;
        // for(auto x:inidt) pq.push({0,x});
        // for(auto x:inidt) cap[i][x] = 0;
        // while(LCK.size() < n) {
        //     auto t = pq.top();
        //     pq.pop();
        //     LCK.insert(t.second);
        //     for(auto x:cnj[t.second]) {
        //         if(LCK.find(x) != LCK.end()) continue;
        //         cap[i][x] = min(cap[i][x],cap[i][t.second]+1);
        //         pq.push({cap[i][x],x});
        //     }
        // }
        LCK.clear();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        auto inidt = strd[i];
        // vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> pql;
        // for(auto x:inidt){
        //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqt;
        //     pqt.push({0,x});
        //     pql.pb
        // }
        if(inidt.size() == 0)
            goto ct;
            // continue;
        for(auto x:inidt) pq.push({0,x});
        for(auto x:inidt) cap[i][x] = 0;
        while(LCK.size() < n && pq.size()) {
            auto t = pq.top();
            pq.pop();
            LCK.insert(t.second);
            for(auto x:cnj[t.second]) {
                if(LCK.find(x) != LCK.end()) continue;
                // cap[i][x] = min(cap[i][x],cap[i][t.second]+1);
                if(cap[i][x] == INT_MAX){
                    if(cap[i-1][x] > cap[i][t.second] +1){
                        cap[i][x] = cap[i][t.second] +1;
                        pq.push({cap[i][x],x});}
                } else {
                    if(cap[i][x] > cap[i][t.second] +1){
                        cap[i][x] = cap[i][t.second] +1;
                        pq.push({cap[i][x],x});
                    }
                }
            }
        }
        ct:
        for(int j = 0;j < cap[i].size();j ++) if(cap[i][j] == INT_MAX) cap[i][j] = cap[i-1][j];
    }
    while(q--){
        int f,v;
        cin >> f >> v;
        cout << (cap[v][f] == INT_MAX ? -1:cap[v][f] )<< "\n";
    }

    // system("pause");

    return 0;
}