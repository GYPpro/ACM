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
    int n,s,r1,r2;
    cin >> n >> s >> r1 >> r2;
    vector<vector<int>> cnj(n+1);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    if(r2 <= 2*r1) {
        cout << "Kangaroo_Splay\n";
    } else{

        int f1;
        // vector<int> dep(n+1);

        int tmp, mx=0;
        auto dfs = [&](auto self,int id,int fa,int dep) -> void {
            // if(cnj[p].size() == 1){ dep[p] = 1;return;}
            for(auto x:cnj[id]) 
            {
                if(x==fa) continue;
                self(self,x,id,dep+1);
            }
            if(mx<dep){
                mx=dep;
                tmp=id;
            }
        };

        dfs(dfs,s,0,0);
        int d1=tmp;
        mx=0;
        dfs(dfs,d1,0,0);
        // int d2 = tmp;
        // cout << mx << " ";
        if(mx <= 2*r1) cout << "Kangaroo_Splay\n";
        else cout << "General_Kangaroo\n";
    }
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
