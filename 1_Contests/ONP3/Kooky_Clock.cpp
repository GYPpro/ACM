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
using ld = long double;
ld PI = acosl(-1);
void solve()
{
    int t;
    cin >> t;
    int l1,l2,l3;
    cin >> l1 >> l2 >> l3;
    int t1,t2,t3;
    cin >> t1 >> t2 >> t3;
    ld dps1 = (ld)(2.0*PI)/t1;
    ld dps2 = (ld)(2.0*PI)/t2;
    ld dps3 = (ld)(2.0*PI)/t3;   
    using pld = pair<ld,ld>;
    dps1 *= t;
    dps2 *= t;
    dps3 *= t;
    pld p1 = { 0 + l1*cosl(dps1) , 0 + l1 * sinl(dps1) };
    pld p2 = {p1.fi + l2 * cosl(dps2),p1.se + l2 * sinl(dps2)};
    pld p3 = {p2.fi + l3 * cosl(dps3),p2.se + l3 * sinl(dps3)};
    cout << fixed << setprecision(10) << p3.se << " " << p3.fi << "\n";
};

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
