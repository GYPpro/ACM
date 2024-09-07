// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<double,double>
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
    double l,x,y;
    cin >> l >> x >> y;
    pii rotl = {0,0},rotr = {l,0};
    auto distance = [&](pii a,pii b) -> double{
        return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
    };
    if(distance(rotl,{x,y}) <= l) {
        cout << "Yes\n";
        cout << 0 << "\n";
    } else {
        if(distance(rotr,{x,y}) <= l) {
            cout << "Yes\n" << l << "\n";
        } else cout << "No\n";
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
