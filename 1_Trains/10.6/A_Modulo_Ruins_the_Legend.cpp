#define _USE_IOSTREAM_
#define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define u unsigned long long
#define int ll

using namespace std;

int upperDiv(int a, int b)
{
    int ans = a / b;
    if (ans * b != a)
        return ans + 1;
    else
        return ans;
}

int Exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve()
{
    int n1, m;
    cin >> n1 >> m;
    int n2 = n1 * (n1 + 1) >> 1;
    // int gd = gcd(n1, n2);
    int sum = 0;
    for (int i = 0; i < n1; i++)
    {
        int t;
        cin >> t;
        sum += t;
        sum %= m;
    }
    int gd1 = gcd(n1, n2);
    int gd2 = gcd(gd1, m);
    int a1 = sum + n1;
    int kp = a1 / gd2;
    // int kp = upperDiv(a1,gd2);
    int x = kp * gd2 - a1;
    x = -x;
    int k, y;
    Exgcd(gd1, m, k, y);
    k *= -kp;
    y *= -kp;
    // if (k < 0)
    // {
    //     int t = upperDiv(-k, n2);
    //     k += t * n2;
    //     d -= t * n1;
    // }
    // else if (d < 0)
    // {
    //     int t = upperDiv(-d, n1);
    //     k -= d * n2;
    //     d += d * n1;
    // }
    // if (k < 0)
    // {
    //     int t = upperDiv(t, m);
    //     k += t * m;
    //     y -= t * gd1;
    // }
    cout << x << endl;
    int s, d;
    Exgcd(n1, n2, s, d);

    for (;;)
    {
        int t = 1;
        y -= t * gd1;
        k += t * m;
        s *= k;
        d *= k;
        if (s < 0)
        {
            int t = upperDiv(-s, n2);
            s += t * n2;
            d -= t * n1;
        }
        else if (d < 0)
        {
            int t = upperDiv(-d, n1);
            d += t * n1;
            s -= t * n2;
        }
        if(s >= 0 && d >= 0) break;
    }
    cout << (s + 1 )%m<< " " << d%m;
    // int mt = m * m - sum - n1;
    // // mt = upperDiv(mt, gd);
    // int firstIdx = sum+n1;
    // int ans = 0;
    // if (sum != 0)
    //     ans = (n1 + sum + gd * mt) % m;
    // else
    // {
    //     cout << "0\n0 0" << endl;
    //     return;
    // }

    // cout << ans << endl;
    // int s = 0, d = 0;
    // Exgcd(n1, n2, s, d);

    // s *= mt;
    // d *= mt;
    // if (s < 0)
    // {
    //     int t = upperDiv(-s, n2);
    //     s += t * n2;
    //     d -= t * n1;
    // }
    // else if (d < 0)
    // {
    //     int t = upperDiv(-d, n1);
    //     s -= d * n2;
    //     d += d * n1;
    // }
    // cout << s + 1 << " " << d << endl;
}

// #define _WITH_T_

signed main()
{
#ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}