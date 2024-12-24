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
    int n,k;
    cin >> n >> k;

    // int n;
    // cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    // map<int,int> cnt;
    for(int i = 0;i < n;i ++){
        int t = arr[i];
        for(int j = 0;j < n;j ++)  {
            if(i  == j) continue;
            if(abs(arr[j]-arr[i]) %k == 0) goto FORCECONTINUE;
        }

        cout << "YES\n";
        cout << i+1 << "\n";
        return;
        FORCECONTINUE:;
    }
     // for(auto x:arr) cnt[x] ++;
    // int t = arr.front();
    // for(auto x:arr) t =  __gcd(x,t);7
    cout << "NO\n";
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
