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
    vector<int> b(n);
    for(auto &x:b) cin >> x;
    int sumb = 0;
    for(auto x:b) sumb += x;
    // if(sumb)
    int pwc = n*(n+1) >> 1;
    if(sumb % pwc != 0) {
        cout << "NO\n";
        return;
    }
    int suma = sumb/pwc;
    // for(auto x:b)
    bool flag = 1;
    vector<int> anss;
    for(int i = 0;i < n;i ++) {
        int t = (suma - (b[i]-b[(i-1+n)%n]))/n;
        if((suma - (b[i]-b[(i-1+n)%n])) % n != 0 || (t > 1e9 || t <= 0)){
            cout << "NO\n";
            return;
        }
        else anss.pb(t);
    }
    cout << "YES\n";
    // cout << "\n";
    for(auto x:anss) cout << x << " ";cout << "\n";
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
