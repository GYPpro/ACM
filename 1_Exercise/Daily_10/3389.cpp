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
using ld = long double;
vector<ld> GaussianELI(vector<vector<ld>> a,vector<ld> b) {
    assert(a.size()),assert(a.size() == a[0].size()),assert(a.size() == b.size());
    int n = a.size();
    vector<int> p(n);
    iota(all(p),0);
    for(int i = 0;i < n;i ++){
        sort(all(p),[&](int x,int y) -> bool {return a[x][i] < a[y][i]; });
        for(auto x:p) cout << x <<" ";cout <<"\n";
    }
    return {1,1};
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ld>> a(n,vector<ld>(n));
    vector<ld> b(n);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j <= n;j ++) if(j == n) cin >> b[i];
        else cin >> a[i][j];
    GaussianELI(a,b);
    // vector<
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
