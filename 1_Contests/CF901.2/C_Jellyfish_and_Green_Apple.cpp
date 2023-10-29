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
#define ull unsigned long long

using namespace std;

ll int gcd(ll int a,ll int b){return b == 0 ? a : gcd(b,a%b);}



bool ifPow2(ll int n)
{
    return (n & (n-1)) == 0;
}

void solve()
{
    ll int n,m;
    cin >> n >> m;
    n = n%m;
    if((n == m) || (n == 0)) {
        cout << 0 << endl;
        return;
    } else {
        ll int mgcd = gcd(n,m);
        n /= mgcd;
        m /= mgcd;
        if(ifPow2(m)) {
            ll int sum = n*(m-1);
            ll int modt = n;
            ll int sup = 0;
            while(modt)
            {
                sup += modt%2;
                modt >>= 1;
            }
            sup --;
            modt = n-1-sup;
            sum -= modt*m;
            cout << sum*mgcd << endl;
        } else {
            cout << -1 << endl;
            return;
        }
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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}