#include <iostream>
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 1001000

#define ull unsigned long long
using namespace std;

ll int fastpow(int m, int n)
{
    ll int ans = 1;
    ll int base = m;
    while (n != 0)
    {
        if (n % 2 == 1)
            ans = (ans * base) % mod1;
        base = (base * base) % mod1;
        n /= 2;
    }
    return ans;
}

ll int binpow(ll int a, ll int b) {
  a %= mod1;
  ll int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod1;
    a = a * a % mod1;
    b >>= 1;
  }
  return res;
}


ll int ex_gcd(ll int a, ll int b, ll int &x, ll int &y) 
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll int r = ex_gcd(b, a % b, x, y);
    ll int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

ll int getAns(int a, int b) 
{
    ll int x, y;
    ll int gcd = ex_gcd(b, mod1, x, y);
    if (a % gcd != 0)
        return -1;
    ll int ans = (x * (a / gcd)) % mod1;
    ans = (ans + mod1) % mod1;
    return ans;
}

ll int summ[maxn] = {0};

ll int fm(int m, int n)
{
    if (summ[n] != 0)
        return summ[n];
    ll int ans = 0;
    ans = summ[n - 1] + binpow(n, m);
    summ[n] = ans % mod1;
    return ans;
}

int inv(int a)
{
    return a == 1 ? 1 : (long long)(mod1 - mod1 / a) * inv(mod1 % a) % mod1;
}

//----
ll int fac[maxn] = {0};
ll int facp[maxn] = {0};

ll int Ct(int n, int m)
{
    int p = mod1;
   // return  fac[n] * binpow(fac[m], p - 2) % p * binpow(fac[n - m], p - 2) % p;
    return fac[n] * facp[m] % p * facp[n - m] % p;
}
//----

void solve()
{
    int a, b, m, n;
    cin >> n >> m >> a >> b;
    summ[0] = 0;
    memset(summ, 0, sizeof(summ));
    summ[1] = 1;
    summ[2] = binpow(2, m) + 1;
    ll int ans = 0;
    ll int bn = binpow(b, n);
    for (int i = 1; i <= n; i++)
    {
        ll int tmpans = Ct(n, i)%mod1;
        tmpans *= binpow(a,i)%mod1;
        tmpans %= mod1;
        tmpans *= binpow(b-a,n-i)%mod1;
        tmpans %= mod1;
        tmpans *= fm(m,i)%mod1;
        ans += tmpans;
        ans %= mod1;
    }
    cout << getAns(ans, bn) << endl;
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // test();
    int T;

    //---
    ll int p = mod1;
    fac[0] = 1;
    for (int i = 1; i <= maxn-10; i++) {fac[i] = fac[i - 1] * i % p;}
    for(int i = 0;i <= maxn-11;i ++) facp[i] = binpow(fac[i],p-2)%p;
    //---

    // scanf("%d",&T);
    cin >> T;
    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");
    return 0;
} 