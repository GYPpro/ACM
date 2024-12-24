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
    int n;
    cin >> n;
    vector<vector<int>> cnj(n+1);
    lop(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }   
    using itf = function<void(int,int)>;
    vector<int> wei(n+1),fawei(n+1);
    vector<int> cnt(n+1);
    vector<int> fa(n+1);
    itf cacucnt = [&](int p, int f) -> void {
        cnt[p] = 1;
        fa[p] = f;
        for(auto x:cnj[p]) if(x == f) continue;
        else {
            cacucnt(x,p);
            cnt[p] += cnt[x];
        }
        return;
    };cacucnt(1,0);
    itf cacuwei = [&](int p, int f) -> void {
        wei[p] = cnt[p];
        for(auto x:cnj[p]) if(x == f) continue;
        else {
            cacuwei(x,p);
            wei[p] += wei[x];
        }
        return;
    };cacuwei(1,0);
    itf cacufawei = [&](int p,int f) -> void {
        int curfawei = n-cnt[p];
        if(f != 0)  curfawei += wei[f]-wei[p]-cnt[f];
        // for(auto x:cnj[f]) if(x != fa[f] && x != p) curfawei += wei[x];
        int tmp = wei[f]-wei[p];
        // cout << p << " " << f << "\n";
        // cout << curfawei << " " << n-cnt[p] + wei[f]-wei[p]-cnt[f] << "\n";
        // cout << "-----\n";
        fawei[p] = curfawei + fawei[f];
        for(auto x:cnj[p]) if(x == f) continue;
        else cacufawei(x,p);
        return;
    };cacufawei(1,0);
    // for(auto x:cnt) cout << x << " ";cout << "\n";
    // for(auto x:wei) cout << x << " ";cout << "\n";
    // for(auto x:fawei) cout << x << " ";cout << "\n";
    int maxans = 0;
    for(int i = 1;i <= n;i ++)
    {
        maxans = max(maxans,
            n + wei[i] - cnt[i] + fawei[i]
        );
    }
    cout << maxans << "\n";
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
