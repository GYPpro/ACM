// #pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int unsigned long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
#define map unordered_map

void solve()
{
    int n;
    cin >> n;
    if(n == 0) cout << 1 << "\n";
    else {
        int x = n;
        int a = 1,b = 0,c = 0;
        while(x != 1) {
            if(x % 2) a = 2 * a + b,c = c + b;
            else b = a + 2 * b,c = c + a;
            x >>= 1; 
        }
        cout << (c >= 64 ? 0 : ((unsigned long long)1 << c)) << "\n";
    }
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
