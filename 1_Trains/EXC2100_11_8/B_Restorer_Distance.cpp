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
    int n,a,r,m;
    cin >> n >> a >> r >> m;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    auto check = [&](int mid) -> int {
        int low = 0,upper = 0;
        for(auto x:arr) if(x > mid)  upper += abs(mid-x);
        else if(x < mid) low += abs(x-mid);
        // cout << low << " " << upper << "\n";
        // int t = min(low,upper);
        // int ans1=upper*r +low*a;
        // int ans2;
        // if(upper>low){
        //     ans2=(upper-low)*r+low*m;
        // }
        // else{
        //     ans2=(low-upper)*a+upper*m;
        // }
        // return  min(ans1,ans2);
        // return min(m*t + a*(low-t) + r * (upper-t))
        return min(
            m*(min(low,upper))+a*(low-min(low,upper))+r*(upper-min(low,upper)),
            low*a+upper*r
        );
    };
    int l = 0,rr = 1e9+1;
    while(l < rr) {
        int mid = l + rr >> 1;
        if(check(mid) <= check(mid+1)) rr = mid;
        else l = mid + 1;
    }
    // for(int i = 0;i < 8;i ++) cout << check(i) << " ";cout << "\n";
    // cout << l << " ";
    cout << check(l) << "\n";
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
