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
#include <set>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void addDiv(ll int x, set<ll int> &privDivofN)
{
    ll t = sqrt(x) + 1;
    for (int i = 1; i <= t; i++)
    {
        if (x % i)
            continue;
        privDivofN.insert(i);
        privDivofN.insert(x / i);
    }
    return;
}

ll int getDiv(ll int x)
{
    ll int t = sqrt(x) +2;
    ll int ans = 0;
    for(int i = 1;i*i <= x;i ++)
    {
        if(i*i == x)ans ++;
        else ans += 2;
    }
    return ans;
}

ll int gcd(ll int a, ll int b) { return b == 0 ? a : gcd(b, a % b); }

bool ifPow2(ll int n)
{
    return !(n & (n - 1));
}

void solve()
{
    ll int n, k;
    cin >> n >> k;
    // set<ll int> divofN;
    // set<ll int> initDivofN;
    // addDiv(n, divofN);
    // initDivofN = divofN;
    // int pvn = n;
    // for (int i = 0; i < k; i++)
    // {
    //     int que = 0;
    //     cin >> que;
    //     if (que == 2)
    //     {
    //         divofN = initDivofN;
    //         n = pvn;
    //         continue;
    //     }
    //     ll int x;
    //     cin >> x;
    //     n *= x;
    //     addDiv(n, divofN);
    //     if (n % divofN.size())
    //         cout << "NO\n";
    //     else
    //         cout << "YES\n";
    // }
    // cout << endl;
    ll int DivN = getDiv(n);
    ll int pvDivN = DivN;
    ll int pvN = n;
    for(int i = 0;i < k;i ++)
    {
        int que;
        cin >> que;
        if(que == 2)
        {
            DivN = pvDivN;
            n = pvN;
            continue;
        }
        ll int x;
        cin >> x;
        ll int btGcd = gcd(x,n);
        ll int divGcd = getDiv(divGcd);
        ll int divX = getDiv(x);
        DivN *= (divX/divGcd);
    }
}

#define _WITH_T_

int main()
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