#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>

#define ll long long
#define N 1000005
#define mod1 998244353

using namespace std;

ll int fac[N] = {0};
ll int facp[N] = {0};

ll int binpow(ll int a, ll int b)
{
    a %= mod1;
    ll int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod1;
        a = a * a % mod1;
        b >>= 1;
    }
    return res;
}

ll int C(int n, int m)
{
    int p = mod1;
    // return  fac[n] * binpow(fac[m], p - 2) % p * binpow(fac[n - m], p - 2) % p;
    return fac[n] * facp[m] % p * facp[n - m] % p;
}

ll a[N] = {0}, b[N] = {0};

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll u, v;
    for (ll i = 1; i <= m; i++)
    {
        cin >> u >> v;
        // cout<<u<<" "<<v<<endl;
        a[u]++;
        a[v]++;
    }
    sort(a + 1, a + n + 1);
    // for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
    ll num = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i + 1] == a[i])
            num++;
        else
        {
            b[a[i]] = num;
            num = 1;
        }
    }
    // for(ll i=1;i<=m;i++) cout<<b[i];

    ll ans = 0;
    for (ll k = 2; k <= m; k++)
    {
        ll xo = 0;
        for (ll j = 2; j <= m; j++)
        {
            while (b[j] == 0)
                j++;
            xo += b[j] * C(j, k);
            xo = xo % (ll)(1e9 + 7);
        }
        ans ^= xo;
        ans %= (ll)(1e9 + 7);
    }
    cout << ans << endl;
    memset(a, 0, n);
    memset(b, 0, m);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll int p = mod1;
    fac[0] = 1;
    for (int i = 1; i <= N - 10; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
    for (int i = 0; i <= N - 11; i++)
        facp[i] = binpow(fac[i], p - 2) % p;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}