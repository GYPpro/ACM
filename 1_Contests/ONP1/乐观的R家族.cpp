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
    int n,m;
    cin >> n >> m;
    vector<map<int,int>> cnts(m+1);
    lop(i,0,n)
    {
        string s;
        cin >> s;
        lop(j,0,s.size()) cnts[j][s[j]] ++;
    }
    vector<int> a(m+1);
    lop(i,0,m) cin >> a[i];
    int ans = 0;
    lop(i,0,m)
    {
        auto &x = cnts[i];
        int mx = 0;
        for(auto [k,v]:x) mx = max(mx,v);
        ans += mx * a[i];
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
