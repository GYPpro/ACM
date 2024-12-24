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
const int N = 5e6+1;
pii rec[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    int mx = 0;
    for(auto x:a) mx = max(x,mx);
    // if(mx*2 < n*(n-1)) 
    for(int i = 0 ;i < n;i ++)
    {
        for(int j = i+1;j < n; j ++)
        {
            if(rec[a[j]+a[i]] != pii({0,0}) ) {
                if(i == rec[a[j]+a[i]].fi || i == rec[a[j]+a[i]].se || j == rec[a[j]+a[i]].fi || j == rec[a[j]+a[i]].se) continue;
                cout << "YES\n";
                cout << i+1 << " " << j+1 << " " << rec[a[j]+a[i]].fi+1 << " " << rec[a[j]+a[i]].se+1 << "\n";
                return;
            }
            rec[a[i]+a[j]] = {i,j};
        }
    }
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
