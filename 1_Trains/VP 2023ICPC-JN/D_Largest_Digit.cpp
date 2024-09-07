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
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    auto f = [&](int a,int b) -> int {
        int t = a+b;
        int rt = 0;
        // cout << "-";
        while(t)
        {
            rt = max(rt,t%10);
            t /= 10;
        }
        // cout << "-";
        return rt;
    };

    if(b-a >= 10 || d-c >= 10) cout << 9 << "\n";
    else {
        int maxn = 0;
        lop(i,a,b+1)
            lop(j,c,d+1)
                maxn = max(f(i,j),maxn);
        cout << maxn << "\n";
    }
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
