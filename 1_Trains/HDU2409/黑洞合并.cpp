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
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    int l = 0,r = n-1;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    while(l != r)
    {
        int t = arr[r] * arr[l] % mod;
        sum +=  t * ((arr[l] + arr[r]) % mod);
        arr[r] += arr[l];
        arr[r] %= mod;
        sum %= mod;
        l ++;
    }
    cout << sum << "\n";
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
