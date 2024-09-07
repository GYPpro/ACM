// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
using namespace std;
const ld pi = acosl(-1);
using pld = pair<ld, ld>;

ld cirIT(pld p1, ld r1, pld p2, ld r2)
{
    auto pw = [](auto a) -> ld
    { return a * a; };
    auto dis = [&](pld a, pld b)
    { return sqrtl(pw(a.fi - b.fi) + pw(a.se - b.se)); };
    auto tracos = [&](ld a, ld tb, ld tc) -> ld
    {return acosl((pw(a) + pw(tb) - pw(tc)) / (2.0 * a * tb)); }; 
    ld x1 = p1.fi, x2 = p2.fi, y1 = p1.se, y2 = p2.se, d = dis(p1, p2);
    if (fabs(r1 - r2) - d >= -1e-13) return pi * min(pw(r1),pw(r2));
    else if (r1 + r2 <= d) return 0;
    return pw(r1) * (tracos(r1, dis(p1, p2), r2) - sinl(tracos(r1, dis(p1, p2), r2) * 2.0) / 2.0) + pw(r2) * (tracos(r2, dis(p1, p2), r1) - sinl(tracos(r2, dis(p1, p2), r1) * 2.0) / 2.0);
}

void solve()
{
    int xt, yt, rt, xt2, yt2, rt2;
    cin >> xt >> yt >> rt >> xt2 >> yt2 >> rt2;
    ld x = xt, y = yt, r = rt, x2 = xt2, y2 = yt2, r2 = rt2;
    cout << setprecision(18) << cirIT({x, y}, r, {x2, y2}, r2) << "\n";
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

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
