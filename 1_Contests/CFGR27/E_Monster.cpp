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
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    // imporve cost,attack cost,hp,limit
    int l = 1,r = k;

    auto check = [&](int mid) -> int {
        return x * mid + ((z+mid-1)/mid) * y;
    };

     while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid) <= check(mid + 1)) r = mid;
        else l = mid + 1;
    }
    for(int i = 0;i < k;i ++) cout << check(i+1) << " ";cout << "\n";
    cout << check(l) << endl;
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
