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
    int X,n,k;
    // cin >> x >> n >> k;
    cin >> n >> X >> k;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    // for(auto x:arr) cout << x << " ";cout << "-\n";
    auto check = [&](int _s) -> bool
    {
        _s = min(n,_s);
        vector<int> prfs;
        
        lop(i,0,_s) prfs.pb(arr[i]);
        sort(all(prfs));
        int sum = 0;
        lop(i,0,_s-k) sum += prfs[i];
        // cout << _s << ":" << sum << "\n";
        if(X == 0 && sum == 0) return 1;
        return sum < X;
    };
    int l = 0, r = n+1;   // 因为是左闭右开的，所以 10^9 要加 1
    while (l + 1 < r) {       // 如果两点不相邻
        int mid = (l + r) / 2;  // 取中间值
        if (check(mid))         // 如果可行
        l = mid;              // 升高锯片高度
        else
        r = mid;  // 否则降低锯片高度
    }
    // if(check(r)) l = r;
    cout << l << "\n";
}

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
