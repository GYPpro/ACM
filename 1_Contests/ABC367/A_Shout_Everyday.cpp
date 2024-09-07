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
    int a,b,c;
    cin >> a >> b >> c;
    if(c < b) c += 24;
    auto in = [](int a,int b,int c) -> bool {
        return (c >= b && b >= a);
    };
    if(in(b,a,c) || in(b,a+24,c)) cout << "No\n";
    else cout << "Yes\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
