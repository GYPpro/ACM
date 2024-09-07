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
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    pii a =  ord(a1,a2);
    pii b =  ord(b1,b2);
    int  cnt = 0;
    if((a.fi > b.fi && a.se >= b.se) || (a.fi >= b.fi && a.se > b.se)) cnt += 1;
    if((a.fi > b.se && a.se >= b.fi) || (a.fi >= b.se && a.se > b.fi)) cnt += 1;
    // if cnt += 1;
    // if(a.fi > b.se) cnt += 1;
    // if(a.se > b.fi) cnt += 1;
    // if(a.se > b.se) cnt += 1;
    cout << cnt *2<< "\n";
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
