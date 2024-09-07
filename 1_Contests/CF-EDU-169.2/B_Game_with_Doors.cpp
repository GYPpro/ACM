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
    pii a,b;
    cin >> a.fi >> a.se;
    // a.fi --,a.se ++;
    cin >> b.fi >> b.se;
    // b.fi --,b.se ++;
    if(b < a) swap(a,b);
    //b > a
    if(a.se < b.fi) cout << 1 << "\n";
    if(a.se == b.fi) cout << 2 << "\n";
    if(a.se > b.fi)
    {
        int t = 0;
        if(a.fi == b.fi) t --;
        if(a.se == b.se) t --;
        cout << min(b.se - b.fi + 2,a.se - b.fi + t + 2) << "\n";
    }
    // cout << max(1LL,a.se - b.fi) << "\n";
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
