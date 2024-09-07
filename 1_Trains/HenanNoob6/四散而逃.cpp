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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    int sumt  = 0;
    int times = 0;
    int ans = 0;
    if(n == 3 && arr[1] %2 != 0) {
        cout << "-1\n";
        return;
    }
    bool f = 0;
    lop(i,1,n-1)
    {
        if(arr[i] >= 2) {
            f = 1; 
            ans += (arr[i]+1)/2;
        }
    }
    if(f) cout << ans << "\n";
    else cout << "-1\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
