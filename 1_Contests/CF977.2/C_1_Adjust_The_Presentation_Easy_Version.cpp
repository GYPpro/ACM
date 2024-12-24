// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_pii = tree<int, null_type, less<int>, rb_tree_tag,
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
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> b(m);
    for(auto &x:b) cin >> x;
    set<int> occr;
    vector<int> nb;
    for(auto x:b) if(occr.find(x) != occr.end()) continue;
    else occr.insert(x),nb.pb(x);
    lop(i,0,nb.size()) if(a[i] == nb[i]) continue;
    else {cout << "TIDAK\n";return;}
    cout << "YA\n";
    return;
    // b.erase(unique(all(b)));
    // for(auto x:b) cout << x << " ";cout << "\n";
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
