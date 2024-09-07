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
    int x,y,c;
    cin >> x >> y >> c;
    vector<int> xs(c),ys(c);
    // for(auto )

    lop(i,0,c/2+1) xs[i] = x-((c/2+1)+i),xs[c-i-1] = x+((c/2+1)+i);
    lop(i,0,c/2+1) ys[i] = y-((c/2+1)+i),ys[c-i-1] = y+((c/2+1)+i);
    if(c%2 == 1) xs[c/2] = x, ys[c/2] = y;
    lop(i,0,c) cout << xs[i] << " " << ys[i] << "\n";
    cout << "\n";
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
