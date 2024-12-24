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
    int n,k;
    cin >> n >> k;
//     vector<vector<int>> mtx(n,vector<int>(n));
    int mtx[n][n];
    for(int i = 1;i < n;i ++)
        for(int j = 1;j < n;j ++)
            mtx[i][j]=0,mtx[i][j] = mtx[i-1][j] + mtx[i][j-1];
    // vector<int> arr(n);
    // for(auto &x:arr) cin >> x;
    // vector<int> cnt(n+1);
    // int res = 0;
    // // k --;
    // int prvk = k;
    // auto cacu = [&]() {
    //     int ans = 0;
    //     int prvans = 0;
    //     for(auto &x:cnt) x = 0;
    //     k = prvk - 1;
    //     for(auto x:arr) {
    //         // cout << x << " ";
    //         if(cnt[x] && k) {
    //             ans += prvans;
    //             prvans = 0;
    //             // cout << x << " ";
    //             k --;
    //             for(auto &x:cnt) x = 0;
    //             cnt[x]  = 1;
    //             prvans += 1;
    //         } else {
    //             if(!cnt[x]) prvans ++;
    //             cnt[x] = 1;
    //         }
    //     }
    //     ans += prvans;     
    //     res = max(res,ans);   
    // };
    // cacu();
    // reverse(all(arr));
    // cacu();
    // cout << res << "\n";
    
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
