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
    vector<int> arr(n);
    lop(i,0,n) cin >> arr[i];
    int t = arr[0];
    for(auto x:arr) t = __gcd(t,x);
    for(auto &x:arr) x /= t;
    // int cur = *min(all(arr)),sum = 0;
    vector<int> vst(n);
    int mi = INF,mii;
    lop(i,0,n) if(arr[i] < mi) mii = i,mi = arr[i];
    int cur = mi,sum = cur;
    vst[mii] = 1;
    // n--;
    lop(_,1,n)
    {
        // cout << cur << " ";
        if(cur == 1) sum += cur;
        else {
            int gmi = INF,gmii = 0;
            lop(i,0,n)
            {
                if(vst[i]) continue;
                if(__gcd(arr[i],cur) < gmi) gmi = __gcd(arr[i],cur),gmii = i;
            }
            vst[gmii] = 1;
            cur = gmi;
            sum += cur;
        }
    }
    cout << sum * t << "\n";
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