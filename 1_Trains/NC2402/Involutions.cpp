#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second
const int mod = 998244353;
const int p = 998244353;

using namespace std;

class solution
{
private:

    void exgcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1, y = 0;
            return;
        }
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
public:
    void solve()
    {
        int nt,a;
        cin >> nt >> a;
        int n = nt % mod;
        int gnd1 = 1,gnd2 = a,gnd3 = 1; 
        if(n<2){ cout << gnd2 << "\n";return;}
        int gn;
        int i = 0;
        for(i = 1;i+1 < n;i += 2)
        {
            gn = (((a * a + i + 1)%mod) * gnd2 + (i * a %mod) * gnd3)%mod;
            gnd1 =  (gnd3 * i + gnd2 * a) % mod;
            // cout <<i << ":" << gn << "\n";
            // gnd2 = gnd1;
            // gnd1 = gn;
            gnd3 = gnd1;
            gnd2 = gn;
        }
        for(;i < n;i ++){
            gnd1 = (gnd3 * i + gnd2 * a) % mod;
            gnd3 = gnd2;
            gnd2 = gnd1;
        }
        while(n < nt) {gnd2 = gnd2 * a % mod;
        nt -= mod;}
        cout << gnd2 << "\n";
        // vector<int> det(n+1); det[0] = 1;
        // vector<int> inv(n+1); inv[0] = 1;
        // for (int i = 1; i <= n; ++i) {
        //     int tmp = 0;
        //     exgcd(det[i],mod,inv[i],tmp);
        //     inv[i] = (inv[i]%mod + mod)%mod;
        // }
        // for(int i = 1;i <= n;i ++) det[i] = det[i-1] * i % mod;
        // vector<int> pw(n+1);pw[0] = 1;
        // for(int i = 1;i <= n;i ++) pw[i] = pw[i-1] * a % mod;

        // auto C = [&](int n,int m) -> int{
        //     return( (det[n] * inv[n-m]) % p) * inv[m] % p;
        // };

        // int ans = 0;

        // vector<int> preCsum(1,1);

        // int presum = 1;

        // for(int i = 1;i*2 <= n;i ++){
        //     // cout << "add C" << n-(i-1)*2 << " " << i*2 << " " << C(n-(i-1)*2,i*2)<< "\n";
        //     preCsum.pb(preCsum[i-1] * C(n-(i-1)*2,2) % mod);
        // }
        // int pws = 1,invs = 1;
        // for(int i = 0;2 * i <= n;i ++)
        // {
        //     // cout << i << " " << preCsum[i] << " " << preCsum[i] * pw[n-i*2] / det[i] % mod <<  "\n";
        //     ans += preCsum[i] * pw[n-i*2] % mod * inv[i] % mod;
        //     ans += presum * pws % mod * invs;
        //     ans %= mod;
        // }
        // cout << ans % mod << "\n";

    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}