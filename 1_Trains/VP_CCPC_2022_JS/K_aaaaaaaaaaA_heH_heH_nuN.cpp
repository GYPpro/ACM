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
    // bitset<32> bits(n);
    string asb;
    int i = 0;
    if(n == 1){
        cout << "nunhehheha\n";
        return;
    }
    // n ++;
    i = 32;
    while(i)
    {
        if(n >= 2LL*((1LL << i)-1)) asb = "hh" + asb,n -= 2LL*((1LL << i)-1);
        else if(n >= ((1LL << i)-1)) asb = "h" + asb,n -= ((1LL << i)-1);
        asb = "a"+asb;
        // n >>= 1;
        i --;
    }
    reverse(all(asb));
    cout << "nunhehhe"+asb << "\n";
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
