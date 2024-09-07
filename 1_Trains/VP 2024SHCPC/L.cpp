#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define lop(i,a,b) for(int i = a;i < b;i ++)
#define fi first
#define se second
#define pb push_back

const int INF = 1000000;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> cnj(n+1);
    vector<multiset<int>> sel(n+1);
    lop(i,0,n)
    {
        int tkk;
        cin >> tkk;
        while(tkk--)
        {
            int t;
            cin >> t;
            cnj[i+1].pb(t);
            cnj[t].pb(i+1);
        }
    }
    lop(i,0,m)
    {
        int u,v;
        cin >> u >> v;
        sel[u].insert(v);
    }
    vector<int> dp(n+1,INF);
    // int k = 0;
    lop(i,0,k)
    {
        int tmp;
        cin >> tmp;
        dp[tmp] = 0;
    }
    vector<int> costs;
    map<int,int> cnt;
    function<void(int,int)> dfs = [&](int p,int f) {
        // if(dp[p] != INF) return;
        costs.clear();
        cnt.clear();
        // if(cnj[p].size() == 1 && f != 0) return;
        bool ifleaf = 0;
        for(auto x:cnj[p]) if(x == f) continue;
            else dfs(x,p),ifleaf = 1;
        if(!ifleaf) return;
        int opt1 = 0;
        for(auto x:cnj[p]) if(x == f) continue;
           else opt1 += dp[x];
        int opt2 = INF;
        for(auto x:cnj[p]) if(x == f) continue;
            else if(sel[p].find(x) != sel[p].end()) opt2 = min(opt2,dp[x]+1);

        dp[p] = min(INF,min(opt1,opt2));

        // int minCost = INF;
        // int subMaxC = 0;

        // minCost = min(minCost,subMaxC);
        // for(auto x:cnj[p])if(x == f) continue;
        //    else if(sel[p].find(x) != sel[p].end()) minCost = min(minCost,dp[x]+1);
        // dp[p] = minCost;
        // cout << p << " : " << minCost << "\n";
        return;
            // else minCost = max(minCost,)
        // for(auto x:cnj[p]) if(x == f) continue;
        //     else costs.emplace_back(dp[x]);
        // bool ALLCMP = 1;
        // for(auto x:costs) cnt[x] ++;
        // int maxn = 0;
        // int minn = INF;
        // for(auto x:costs) maxn = max(maxn,x);
        // if(cnt.size() <= 1) dp[p] = max(maxn,dp[p]);
    };
    dfs(1,0);
    cout << (dp[1] >= INF?-1:dp[1]) << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    //system("pause");
}