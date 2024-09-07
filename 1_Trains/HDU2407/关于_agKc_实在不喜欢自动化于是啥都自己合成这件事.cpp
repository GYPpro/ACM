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
const int INF = 10000000000LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<vector<pii>> cnj(n+1) ;// [x_i 个,a_i 物品]
    vector<int> costs(n+1);
    vector<bool> flag(n+1);
    vector<int> sumc(n+1);
    lop(i,1,n+1)
    {
        int f;
        cin >> f;
        flag[i] = f;
        if(f)
        {
            int t;
            cin >> t;
            while(t--)
            {
                pii u;
                cin >> u.fi >> u.se;
                cnj[i].pb(u);
            }
        } else {
            int t;
            cin >> t;
            costs[i] = t;
        }
    }

    if(flag[k] == 0) {
        cout << costs[k] << "\n";
        return;
    }

    auto dfs = [&](auto self,int p,int f) -> int {
        // if(sumc[])
        // cout << "dfs:" << p << "\n";
        if(cnj[p].size() == 0) return sumc[p] = costs[p];
        int sum = 0;
        for(auto x:cnj[p]) {
            if(x.se == f) continue;
            int t =  self(self,x.se,p);
            if(t == -1) t = INF;
            t *= x.fi;
            sumc[x.se] = t >= INF?-1:t;
            sum += t;
            if(sum > 1e9) {sum = INF;}
        }
        if(sum >= INF) sum = -1;
        return sumc[p] = sum;
    };
    dfs(dfs,k,0);
    vector<int> fes;
    // for(auto x:sumc) cout << x << " ";cout << "\n";
    for(auto x:cnj[k]) fes.pb(sumc[x.se] == -1?INF:sumc[x.se]);
    sort(all(fes));
    // for(auto x:fes) cout << x << " ";cout << "\n";
    int sum = 0;
    lop(i,0,(int)fes.size()-1) sum += fes[i];
    if(sum > (int)1e9) cout << "Impossible\n";
    else cout << sum << "\n";
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
