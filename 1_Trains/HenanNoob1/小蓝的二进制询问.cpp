// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int __int128
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

int max(int a ,int b) {
    if(a > b) return a;
    else return b;
}

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
    long long  l,r;
    cin >> l >> r;
    int cnt = 0;
    const int mod = 998244353;
    auto  g = [](int m,int i) -> int 
    {
        // cout << m << " " << i << " : ";
        m ++;
        // cout <<  m/(1<<i+1)*(1<<i)+max(0LL,m%(1<<i+1)-(1<<i)) << "\n";
        // int t1 = (1LL << i+1LL ) % mod;
        int ans = ( (int)m / (int)(1LL << i+1LL )  )% mod;
        ans *= ( 1LL << i );
        ans %= mod;
        ans += max( (int)0 , m% (1LL<< i+1LL ) - (1LL<<i));
        ans %= mod;
        // ans *= m;
        // ans %= m;
        // ans *= 
        return ans;
    };

    lop(i,0,62)
    {
        // cout << (r/(1<<i) - l/(1<<i)) << " ";
        // cnt += (r/(1<<i) - l/(1<<i));
        cnt += g(r,i)-g(l-1,i) ;
        cnt %= mod;
    }    
    long long ans = cnt;
    cout << ans << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    signed T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
