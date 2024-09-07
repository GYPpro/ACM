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

int m = 998244353LL;

long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2) % m;
  if (b % 2)
    return res * res * a % m;
  else
    return res * res % m;
}

void solve()
{
    int n;
    cin >> n;
    if(n <= 4) {
        if(n == 1) cout << 2 << "\n";
        else if(n == 2)cout << 2 << "\n";
        else if(n == 3)cout << 8 << "\n";
        else if(n == 4)cout << 16 << "\n";
        else if(n == 5)cout << 16 << "\n";
    } else {
        // cout << binpow(2,(n-1)/3) % m << "\n";
        cout << binpow(2,n-((n-2)%3 == 0)) % m;
        // cout << binpow(2,n)%m << "\n";
    }
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
