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
    string s;
    cin >> s;
    vector<pii> spr;
    auto mxrg = [&](int i) -> int {
        int l = i-1,r = i+1;
        while( 
            l >= 0 && r < s.size() &&
            s[l] == 'A' && s[r] == 'C'
        ) l --,r ++;
        return i-l-1;
    };
    lop(i,0,s.size()) if(s[i] == 'B') spr.pb({i+1,mxrg(i)});
    // for(auto [i,v]:spr) cout << i << " " << v << "\n";
    int freedp = 0;
    int ans = 0;
    for(auto [i,v]:spr)
    {
        int basic = 0;
        // [v]i[v]
        if(i%2 != 0) //首个就会删B
        {
            basic = min(1LL+freedp,v);
            freedp ++;
            ans += basic;
        } else { //首个删A
            basic = min(2LL+freedp,v);
            //最后会不会删B
            if(v != 1) freedp ++; 
            // if(v > basic) freedp ++;
            ans += basic;
        }
        // cout << basic << " " << freedp << " | ";
    }
    cout << ans << "\n";
}
 /*
ABACAAACCC
10101010101010101
  */
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
