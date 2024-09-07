// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
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
    vector<int> arr(n);
    for(auto &x:arr) cin >>  x;
    // int mx = ((n-k)%k);
    // int mx = min(n,k-(n%k));
    int mx = n;
    while(mx > k) mx -= k;
    // cout << mx << "\n";
    auto check = [&](int tar)
    { 
        vector<int> dp(mx,-1);dp[0] = 0;
        for(int i = 0;i < n;i ++)
        {
            int j = i%k;
            if(j >= mx) continue;
            dp[j] = max(dp[j],(j == 0?0:dp[j-1])+(arr[i] >= tar));
        }
        // cout << tar << ":";
        // for(auto x:dp) cout << x << " ";cout << "\n";
        return dp[mx-1] * 2 > mx;
    };

    int l = 1, r = 1e9 + 1;   // 因为是左闭右开的，所以 10^9 要加 1
    while (l + 1 < r) {       // 如果两点不相邻
        int mid = (l + r) / 2;  // 取中间值
        if (check(mid))         // 如果可行
        l = mid;              // 升高锯片高度
        else
        r = mid;  // 否则降低锯片高度
    }
    cout << l << "\n";
//   return l;  // 返回左边值

}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
