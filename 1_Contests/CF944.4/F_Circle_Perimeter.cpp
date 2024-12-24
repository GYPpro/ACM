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
    int r;
    cin >> r;
    int ans = 0;
    auto sq = [](int p) -> bool {
        return ((int)sqrt(p)*(int)sqrt(p)) == p;
    };
    
    for(int x = -r;x * x < (r+1)*(r+1);x ++)
    {
        // cout << sqrt(r*r-x*x) << " ";
        int lb = max(0LL,(int)ceil(sqrt(r*r-x*x)));
        int rb = (int)sqrt((r+1)*(r+1) - x*x) - sq((r+1)*(r+1) - x*x);
        // cout << x << " : " << lb << " " << rb << "\n";
        ans += (rb-lb+1)*2 - (lb == 0);
    }
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
