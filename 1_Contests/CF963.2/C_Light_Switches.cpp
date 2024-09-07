// #define D

#include <bits/stdc++.h>
// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    auto merge = [&](pii a,pii b) -> pair<pii,int>{
        // if(a.fi == b.fi) return 
        pii rt = {max(a.fi,b.fi),min(a.se,b.se)};
        if(rt.fi >= rt.se ) return {rt,0};
        else return {rt,1};
    };  
    sort(all(a));
    pii range = {a.back(),a.back()+k};
    // cout << "---\n";
    for(auto x:a)
    {
        pii newrange;
        if(((a.back()-x)/k )%2 == 0) newrange = {a.back(),a.back()+k-(a.back()-x)%k};
        else newrange = {a.back()+k-(a.back()-x)%k,a.back()+k+1};
        // cout << newrange.fi << " " << newrange.se << "\n";
        auto [_,flag] = merge(range,newrange);
        if(!flag) {
            cout << "-1\n";return;
        } else range = _;
    }
    cout << range.fi << "\n";
}

/*


f(x) x \in [-1e10,1e10] 
dev = 1e-10

[1,-1,4,-3,9,7]
dp[n]

dp[i] 前i位 中 包含第i个元素 的区间最大和

for(0->n)
    dp[i] = max(dp[i-1]+a[i],a[i]);


1e20
log(range/dev)
*/

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
