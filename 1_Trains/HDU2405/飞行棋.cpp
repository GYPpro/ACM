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
int m = 1e9+7;
using namespace std;

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

void solve()
{
    int k;
    cin >> k;
    int ans = 0;
    int y = 0;
    int x = 0;
    exgcd(k,m,x,y);
    x = (x+m)%m;
    cout << (x + k-1) % m << "\n";
    // double s = 0;
    // for(int i = 1;i <= 114;i ++)
    // {
    //     s += i * ((pow(k-1,i-1)/pow(k,i-1)) * (1.0/k));
    //     // cout << ((1.0-1.0/pow(k,i-1)) * (1.0/k)) << "\n";
    //     // cout << i * ((1.0-1.0/pow(k,i))) << "\n"; 
    // }
    // cout << s << "\n";
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
