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
using pid = pair<int,long double>;
using ld = long double;
void solve()
{
    int n;
    cin >> n;
    vector<vector<pid>> cnj(n+1);
    lop(u,1,n)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int v;
            ld p;
            cin >> v >> p;
            cnj[u].pb(pid({v,p}));
        }
    }
    vector<ld> ps(n+1);
    vector<ld> edps(n+1);
    using itf = function<void(int,int)>;
    // itf dfs = [&](int p,int f) -> void {
    //     ld curp = ps[p];
    //     ld nxpcnt = 0;
    //     for(auto [x,tarp]:cnj[p])
    //     {
    //         if(x == f) continue;
    //         else ps[x] += tarp * curp,nxpcnt += tarp * curp;
    //     }
    //     for(auto [x,_]:cnj[p]) if(x == f) continue;
    //     else dfs(x,p);
    //     edps[p] = curp - nxpcnt;
    // };
    ps[1] = 1;
    // dfs(1,0);
    lop(p,1,n+1)
    {
        ld curp = ps[p];
        ld nxpcnt = 0;
        for(auto [x,tarp]:cnj[p])
        {
            // if(x == f) continue;
            ps[x] += tarp * curp,nxpcnt += tarp * curp;
        }
        // for(auto [x,_]:cnj[p]) if(x == f) continue;
        // else dfs(x,p);
        edps[p] = curp - nxpcnt;
    }
    cout << fixed << setprecision(9);
    lop(i,1,n+1)
    {
        cout << edps[i] << " ";
    }cout << "\n";
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
    cin >> T;
    while(T--) solve();
    return 0;
}
