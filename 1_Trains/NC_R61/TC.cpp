// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

const int N = 1e6;
const int mod = 1e9+7;

int binpow(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans % mod;
}

vector<int> fac(N), inv(N);

void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = binpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

int C(int x, int y){
    return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
};

// int binpow(int x, int y)
// {
//     int res = 1;
//     while (y > 0)
//     {
//         if (y & 1)
//             res = res * x % mod;
//         x = x * x % mod;
//         y >>= 1;
//     }
//     return res;
// }

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    auto gnc = [](int tr,int c0,int c1) -> int{ //
        if(tr > 0 && c1 < tr) return 0;
        if(tr < 0 && c0 < abs(tr)) return 0;
        int basic = C(tr>=0?c1:c0,abs(tr));
        if(tr >= 0) c1 -= tr;
        else c0 -= tr;
        int free = binpow(2,min(c1,c0));
        return free % mod * basic % mod;
    };
    
    int cU = 0,cD = 0,cL = 0,cR = 0;
    for(auto x:s)
        if(x == 'U') cU ++;
        else if(x == 'D') cD ++;
        else if(x == 'L') cL ++;
        else if(x == 'R') cR ++;
    int ans = 1;
    // bool flag = 1;
    ans *= gnc(y,cL,cR);
    ans *= gnc(x,cD,cU);
    if(ans  == 0) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES ";
        int tx = 0,ty = 0;
        for(auto c:s)
        {
            if(tx == x && ty == y) break;
            if(c == 'U' && abs(x) > abs(tx) && x > 0) cout << c,tx ++;
            if(c == 'D' && abs(x) > abs(tx) && x < 0) cout << c,tx --;
            if(c == 'R' && abs(y) > abs(ty) && y > 0) cout << c,ty ++;
            if(c == 'L' && abs(y) > abs(ty) && y < 0) cout << c,ty --;
        }
        cout << " " << ans << "\n";
    }
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
