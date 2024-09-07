// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define double long double
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
    int n;
    cin >> n;
    vector<pii> ast(n);
    for(auto &x:ast) cin >> x.fi >> x.se;
    // double x0,y0;
    double xa,xb,ya,yb;
    cin >> xa >> ya >> xb >> yb;
    double minT = 1e30;

    auto rg = [&](pii a,pii b) -> double {
        return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
    };

    for(auto x:ast)
    {
        // auto [x0,y0] = x;
        // double k = (ya-yb)/(xa-xb);
        // double b = -xa * (ya-yb)/(xa-xb) + ya;
        // double mtx = (x0+y0*k-k*b)/(k*k+1.0);
        // double mty = k * mtx + b;
        // pii px = ord(xa,xb);

        // if(mtx > px.fi && mtx < px.se) {
        //     cout << rg({mtx,mty},x) << " ";
        //     minT = min(minT,rg({mtx,mty},x));
        // } else {
            // cout << max( rg({x},{xa,ya}) ,rg({x},{xb,yb}) ) << " ";
            minT = min(minT,rg(x,{xb,yb}));
            // minT = min(minT, max( rg({x},{xa,ya}) ,rg({x},{xb,yb}) ) );
        // }
    }
    if(minT > rg({xa,ya},{xb,yb})) cout << "YES\n";
    else cout << "NO\n";

    // lop(i)
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
