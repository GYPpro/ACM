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
    int n,m;
    cin >> n >> m;
    map<int,vector<int>> xa,ya;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        xa[x].pb(y);
        ya[y].pb(x);
    }
    int maxn = 0;
    for(auto [_,dl]:xa) {
        sort(all(dl));
        maxn = max(maxn,abs(dl.front()-dl.back()));
    }
    for(auto [_,dl]:ya) {
        sort(all(dl));
        maxn = max(maxn,abs(dl.front()-dl.back()));
    }
    cout << maxn << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
