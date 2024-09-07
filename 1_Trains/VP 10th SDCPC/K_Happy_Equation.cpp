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

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve()
{
    int a,p;
    cin >> a >> p;
    if(a%2 == 1) {
        cout << 1 << "\n";
        return;
    }
    int sum = 0;
    int t = 1 << p;
    for(int x = 1;x <= p;x ++)
    {
        if(binpow(a,x,t) == binpow(x,a,t)) sum ++;
    }
    if(p/a == 0) sum += ( t >> 1 ) - ( p >> 1 ); 
    else sum += (t / (p / a) >> 1) - (p / (p/a) >> 1);
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
