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
// #define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    ll int n, m, k;
    cin >> n >> m >> k;
    ll int minn = INT_MAX, maxn = INT_MIN;
    ll int mina = INT_MAX, maxa = INT_MIN;
    ll int minb = INT_MAX, maxb = INT_MIN;
    ll int suma = 0;
    ll int sumb = 0;

    for (int i = 0; i < n; i++)
    {
        ll int tmp;
        cin >> tmp;
        suma += tmp;
        minn = min(minn, tmp);
        maxn = max(maxn, tmp);
        mina = min(mina, tmp);
        maxa = max(maxa, tmp);
    }

    for (int i = 0; i < m; i++)
    {
        ll int tmp;
        cin >> tmp;
        sumb += tmp;
        maxn = max(maxn, tmp);
        minn = min(minn, tmp);
        minb = min(minb, tmp);
        maxb = max(maxb, tmp);
    }

    if (mina == minn && maxa == maxn)  //我都有
    {
        k--;
        suma -= mina;
        suma += maxb;
        if (k % 2)
        {
            suma -= maxn;
            suma += minn;
        }
    } else if (minb == minn && maxb == maxn) //我有一个或者没有，对面都有
    {
        k--;
        suma -= mina;
        suma += maxn;
        if (k % 2)
        {
            suma -= maxn;
            suma += minn;
        }
    } else {
        if(mina == minn)//我有最小的
        {
            if(k%2) suma = suma - mina + maxn;
        } else { //我有最大的
            // k --;
            // suma -= mina;
            // suma += maxn;
            // if (!(k % 2)){
            //     suma -= maxn;
            //     suma += minn;
            // }
            if(mina < maxb)
            {
                k --;
                suma -= mina;
                suma += maxb;
                if (k % 2){
                    suma -= maxn;
                    suma += minn;
                }
            } else if (!(k % 2)){
                suma -= maxn;
                suma += minn;
            }
        }
    }
    cout << suma << endl;
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