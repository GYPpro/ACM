#define _USE_IOSTREAM_
// #define _USE_STDIO_

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
#define maxn (__int128)(1e18 + 100)
#define ull unsigned long long

using namespace std;

inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

__int128 msqrt(__int128 a)
{
    __int128 l = 1, r = maxn;
    while (l + 1 < r)
    {
        __int128 mid = (l + r) / 2;
        if (mid * (mid - 1) / 2 >= a)
            r = mid;
        else
            l = mid;
    }
    return l;
}

void solve()
{
    ll n;
    n = read();
    ll k1 = sqrt(2 * (ll)n);
    if (k1 * (k1 + 1) / 2 <= n)
        k1 = k1 + 1;
    ll k2 = k1 * (k1 - 1) / 2;
    cout <<(ll) k1 + n - k2;
    cout << endl;
}

#define _WITH_T_

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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