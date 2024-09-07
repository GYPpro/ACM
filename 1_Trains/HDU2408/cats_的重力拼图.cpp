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
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int ans = 0;

    if(n == 1) ans = m;
    else if(m == 1) ans = n;
    else ans = 2LL*m+2LL*n -4;

    if((a != 1 && a != n) && (b != 1 && b != m)) ans += max((n-2),(m-2));
    else if(a != 1 && a != n && m != 1) ans += (m-2);
    else if(b != 1 && b != m && n != 1) ans += (n-2);
    cout << ans << "\n";
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
