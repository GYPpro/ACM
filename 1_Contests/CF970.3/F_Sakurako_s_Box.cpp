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

const int mod = 1e9+7;

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int c) {
    int k;
    int rt;
    exgcd(c,mod,rt,k);
    rt += mod;
    rt %= mod;
    return rt;
}

void solve()
{
    int n;
    cin >> n;
    int sef = 0;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    for(int i = n -1;i >= 0;i --) sef += arr[i],sef %= mod;
    int sum = 0;
    lop(i,0,n)
    {
        sef -= arr[i];
        sef += mod;
        sef %= mod;
        sum +=( arr[i] * sef )% mod;
        sum %= mod;
    }
    // cout << sum << " " << ((n)*(n-1)/2) << "\n";
    cout << (sum * inv((n)*(n-1)/2)) % mod << "\n";
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
