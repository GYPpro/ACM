#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353LL
#define pb push_back

using namespace std;



class solution{
private:
    vector<vector<int>> t;
    vector<vector<int>> at;
    // vector<vector<int>> tp;
    vector<vector<int>> dp;

    void adg(int u,int v)
    {
        at[u].push_back(v);
        at[v].push_back(u);
    }

    void gcSon(int p,int f)
    {
        for(auto x:at[p]) if(x != f) (t[p].pb(x),gcSon(x,p));
    }

    void dfs(int p)
    {
        for(auto x:t[p]) dfs(x);
        dp[p][0] = max(1LL,dp[p][0]);
        for(auto x:t[p]){
            dp[p][0] *= dp[x][0]+1;
            dp[p][0] %= mod1;
            dp[p][1] += dp[x][0] + dp[x][1];
            dp[p][1] %= mod1;
        }
        // cout << "gc:" << p << " dp[p][0]:" << dp[p][0] << " dp[p][1]" << dp[p][1] << "\n";
    } 

    &int rttst()
    {
        return null;
    }

public:
    void solve()
    {
        int n;
        cin >> n;
        t.resize(n+1);
        at.resize(n+1);
        dp.resize(n+1);
        for(int i = 0;i < n-1;i ++)
        {
            int u,v;
            cin >> u >> v;
            adg(u,v);
        }
        for(auto &x:dp) 
            x.resize(2);
        gcSon(1,0);
        // set<int> rtm;
        // for(int i = 1;i <= n;i ++) rtm.insert(i);
        // for(auto &x:t) for(auto y:x) rtm.erase(y);
        // int root = *(rtm.begin());
        for(int i = 1;i <= n;i ++)
            if(!t[i].size()) dp[i][0] = 1;
        // auto dfs = [&](auto self,int p)
        // {
        //     for(auto x:t[p])
        // };
        dfs(1);
        cout <<( dp[1][0] + dp[1][1] +1 )%mod1 << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
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