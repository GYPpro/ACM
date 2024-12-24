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
// const int N = 20;
// int C[N][N];
// void lst(){
//     for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
//         C[n][0] = 1;
//         C[n][n] = 1;
//         for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
//             C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
//     }
//     for(int i = 0;i < N;i ++){
//         for(int j = 0;j < N;j ++)
//             cout << C[i][j] << " ";
//         cout << "\n";    
//     }
// }
const int mod = 1e9+7;
int binpow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y & 1) res = res * x % mod;
        x = x * x%mod;
        y >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    for(auto x:b) cout << binpow(2,x)<<"\n";
    // string s1,s2;
    // cin >> s1 >> s2;
    // int t = 0;
    // lop(i,0,min(s1.size(),s2.size()))
    //     if(s1[i]==s2[i]) t ++;
    //     else break;
    // cout << min(s1.size() + s2.size()-t+1,s1.size()+s2.size() )<< "\n";  
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
    // lst();
    while(T--) solve();
    return 0;
}
