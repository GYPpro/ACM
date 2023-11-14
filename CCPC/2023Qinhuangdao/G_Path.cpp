#define _USE_IOSTREAM_
// #define _PRIV_TEST_

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
#include <map>
#include <set>

#define int long long
#define mod1 998244353

using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    int sum = 0;
    int tmpr = 0;
    cin >> tmpr;
    for(int i = 1;i < n;i ++){
        int tmp;
        cin >> tmp;
        sum += abs(tmp-tmpr);
        tmpr = tmp;
    }
    cin >> tmpr;
    for(int i = 1;i < m;i ++){
        int tmp;
        cin >> tmp;
        sum += abs(tmp-tmpr);
        tmpr = tmp;
    }
    cout << sum;
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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}