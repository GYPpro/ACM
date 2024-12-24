// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less_equal<int>, rb_tree_tag,
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
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    ord_set ord;
    for(auto x:a) ord.insert(x);
    int SUM = 0;
    for(auto x:a) SUM += x;
    int ans = 0;
    // cout << SUM << "\n";

    for(auto x:a){
        // cout << "----\n";
        int rst = -1;
        if(ord.order_of_key(x+1) > ord.order_of_key(x)) {
            rst = x;
            // for(auto x:ord) cout << x << "  ";cout <<  "\n";
            ord.erase(ord.find_by_order(ord.order_of_key(x)));
            // for(auto x:ord) cout << x << "  ";cout <<  "\n";
        }

        // cout << x << ":" << SUM-l-x +1 << " " << SUM-r-x <<  "\n";
        ans += ord.order_of_key(SUM-l-x +1) - ord.order_of_key(SUM-r-x);  
        // cout << "Res:" << ord.order_of_key(SUM-l-x  +1) << " " << ord.order_of_key(SUM-r-x) << "\n";
        if(rst != -1) ord.insert(rst);
    }
    cout << ans/2 << "\n";
    // vector<int> vis(n)
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
