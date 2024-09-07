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
#define ld long double
using namespace std;

void solve()
{
    int n,m,u,v,q,t;
    cin >> n >> m >> u >> v >> q >> t;
    long double p = (long double) u/(long double)v;
    function<pii(int)> cut = [&](int n) -> pii {
        return {(int)(p*(ld)n),n-(int)(p*(ld)n)};
    };
    queue<int> ori,l,r;
    lop(i,0,n)
    {
        int t;
        cin >> t;
        ori.push(t);
    }
    int inv = 0;
    while(m--)
    {
        
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
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
