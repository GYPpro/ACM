// #define _USE_IOSTREAM_
#define _USE_STDIO_

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
#define ull unsigned long long

using namespace std;

bool ifallow(ll int a, ll int b) // tar:b
{
    if (a > b)
        return 0;
    else if (a == b)
        return 1;
    bool flag = 0;
    for (;;)
    {
        if ((a % 10) == (b % 10))
        {
            a /= 10;
            b /= 10;
        }
        else
        {
            if (!flag)
            {
                flag = 1;
                if (a > b)
                    return 0;
                else
                    b /= 10;
            }
            else
                return 0;
        }
        if ((a <= 0) || (b <= 0))
        {
            if (a != b)
            {
                if ((a < 10) && (b < 10))
                    return !flag;
                else return 0;
            }
            else
                return 1;
        }
    }
}

void solve()
{
    ll a, b, c;
    scanf("%lld + %lld = %lld", &a, &b, &c);
    ll tara = c - b,
       tarb = c - a,
       tarc = a + b;

    if (ifallow(a, tara))
    {
        printf("Yes\n%lld + %lld = %lld\n", tara, b, c);
    }
    else if (ifallow(b, tarb))
    {
        printf("Yes\n%lld + %lld = %lld\n", a, tarb, c);
    }
    else if (ifallow(c, tarc))
    {
        printf("Yes\n%lld + %lld = %lld\n", a, b, tarc);
    }
    else
        printf("No\n");
}

// #define _WITH_T_

int main()
{
#ifdef _USE_IOSTREAM_
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
    // {
    //     int t1, t2;
    //     scanf("%d %d", &t1, &t2);
    //     printf("%d\n", ifallow(t1, t2));
    // }

    // system("pause");

    return 0;
}