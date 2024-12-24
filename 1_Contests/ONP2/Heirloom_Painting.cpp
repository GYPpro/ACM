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
    int n,__,k;
    cin >> n >> __ >> k;
    int cur = 0,mx = 0;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    // for(auto x:a) 
    int prv = a[0];
    int fidx = 0;
    lop(i,1,n*2){
        if(a[i%n] == prv ) cur ++;
        else cur = 1,prv = a[i%n];
        if(cur > mx) fidx = i%n;
        mx = max(mx,cur);
    }
    // cout << mx << " " << fidx << "\n";
    mx = min(n,mx);
    if(mx < k) {
        cout << "-1\n";
        return ;
    }
    vector<int> newly;
    auto gt = [&](int x) -> int {
        return x / k + (x%k != 0);
    };
    if(mx == n) 
    {
        cout << gt(mx) << "\n";
        return;
    }
    lop(i,1,n-mx+1)
        newly.pb(a[(i+fidx)%n]);
    int ans = gt(mx);
    newly.pb(INF);
    cur = 0;
    prv = newly[0];
    // for(auto x:newly) cout << x << " ";cout << "\n";
    lop(i,0,newly.size())
    {
        if(newly[i] != prv)ans += gt(cur),cur = 1,prv = newly[i];// cout << cur << " " << gt(cur) << "\n",
        else cur ++;
    }
    cout << ans << "\n";
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
