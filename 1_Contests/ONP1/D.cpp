// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
// #define int long long
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
    vector<vector<int>> rev(n+1);
    vector<vector<int>> prf(n+1);
    vector<int> fx(n+1);
    vector<int> a(n+1),b(n+1);
    lop(i,1,n+1) cin >> a[i];
    lop(i,1,n+1) cin >> b[i];
    lop(i,1,n+1) fx[i] += fx[i-1] + a[i]*b[i];
    lop(i,1,n+1) cout << fx[i] << " ";cout << "\n";
    vector<int> idx(n+1);
    iota(all(idx),0);
    vector<int> tmp = idx;
    reverse(tmp.begin()+1,tmp.end());
    lop(i,0,n)
    {
        lop(k,0,n+1) prf[i].pb(a[tmp[k]]*b[k]);
        lop(k,1,n+1) prf[i][k] += prf[i][k-1];
        tmp[0] = tmp[n];
        for(int i = n;i >= 0;i --) tmp[i+1] = tmp[i];
        tmp[1] = tmp[0];
        tmp[0] = 0;
        cout << "------\n";
        for(auto x:tmp) cout << x << " ";cout << "\n";
        for(auto x:tmp) cout << a[x] << " ";cout << "\n";
        for(auto x:prf[i]) cout << x << " ";cout << "\n";
    }
    auto getrev = [&](int l,int r) -> int {
        // int cur = fx[n]-fx[r-1] + fx[l]-fx[0];
        int ldx = (r+l-2) %(n);
        int rt = prf[ldx][r]-prf[ldx][l-1];
        cout << "que:" << l << " " << r << " : " << rt << "\n";
        return rt;
    };
    vector<int> dp(n+1,0);
    lop(i,1,n+1)
    {
        dp[i] = fx[i]-fx[0];
        lop(k,1,i) dp[i] = max(dp[i], max(fx[i]-fx[k-1], getrev(k,i) ) + dp[k-1] );
        cout << i << " " << dp[i] << "\n";
    }
    cout << dp[n] << "\n";

}
/*
0|1 2 3 4 5 6 7 8
---
0 1 8 7 6 5 4 3 2 
1 2 1 8 7 6 5 4 3 
2 3 2 1 8 7 6 5 4 
3 4 3 2 1 8 7 6 5 
4 5 4 3 2 1 8 7 6 
5 6 5 4 3 2 1 8 7 
6 7 6 5 4 3 2 1 8 
7 8 7 6 5 4 3 2 1 
8---------5
9---------6
0---------7
 */
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
