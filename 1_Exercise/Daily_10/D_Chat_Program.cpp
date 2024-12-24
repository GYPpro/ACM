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
    int n,tar,m,c,d;
    // [c,c+d,...,c+d*(m-1)] for m items
    cin >> n >> tar >> m >> c >> d;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> rg;
    auto getGrRG = [&](int k,int x) -> int {
        if(d == 0) return x + c >= k ? m : 0;
        int need = (k-x+(d-1)-c)/d;;
        if(need > m) return 0;
        else if(need < 0) return m;
        else return m - need;
    };
    vector<int> prfx;
    // 3 1 2
    // 1 3 5
    // 3 5 7
    //  3 its need 2d c c+d c+2d
    //           |    rt   |
    //         -> add
    //  - |- - [ok] - - [-]| - - 
    //         i-3  .... i
    auto check = [&](int k) -> int {
        prfx.clear(),prfx.resize(n+m+1,0);
        // cout << k << ":";
        lop(i,0,n){
            if(a[i] >= k) {
                prfx[0] ++;
                continue;
            } 
            int disc = getGrRG(k,a[i]);
            prfx[min(n-m+1,max(0LL,i-m+1))] ++,prfx[min(n-m+1,max(0LL,i-m+disc+1))]--;
        }
        int cur1cnt = 0;
        for(int i = 0;i < n ;i++) {
            cur1cnt += prfx[i];
            if(cur1cnt >= tar) return 1;
        }
        return 0;
    };
    int l = 0,r = 1e18;
    //111111[1]0000000
    //1 3 5 7 9 11
    while(l < r) {
        int mid = l + ( r - l + 1 >> 1);
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l<< "\n";
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
