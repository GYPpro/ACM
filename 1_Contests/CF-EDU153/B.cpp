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
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void stolve()
{
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll ck, c1, ans, min = 100000008;
    ck = m / k;
    if (ak >= ck)
    {
        if (a1 >= m - ck * k)
            ans = 0;
        else
            ans = m - ck * k - a1;
    }
    else
    {
        for (ll i = 0; i <= ck; i++)
        {
            if (a1 >= m - i * k)
            {
                if (i <= ak)
                    ans = 0;
                else
                    ans = i - ak;
            }
            else
            {
                ans = m - k * i - a1;
                if (i > ak)
                    ans += i - ak;
            }
            if (ans < min)
                min = ans;
        }
        ans = min;
    }
    cout << ans << endl;
}

void solve()
{
    ll int m, k, a1, ak;

    cin >> m >> k >> a1 >> ak;
    if ((k * ak + a1) >= m)
    {
        if (a1 < k)
        {
            if ((m % k - a1) < 0)
                cout << 0 << endl;
            else
                cout << m % k - a1 << endl;
        }
        else
            cout << 0 << endl;
    }
    else
    {
        ll int ans = 0;
        if (a1 < k)
        {
            ll int tmp = ((m - k * ak) % k - a1);
            if (tmp < 0)
                tmp = 0;
            ans = (m - k * ak) / k + tmp;
        }
        else
        {
            ak += a1 / k;
            m -= ak * k;
            ans += m / k + !(m % k == 0);
        }
        cout << ans << endl;
    }
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
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
        stolve();

    // system("pause");

    return 0;
}