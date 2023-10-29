#define _USE_IOSTREAM_
// #define _PRIV_TEST_

#define _WITH_T_

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

#define ll long long
#define mod1 998244353

using namespace std;

class SS{
public:
    vector<ll> arr;
    ll maxLim;
    ll minLim;
    ll int k,m,c,d;
    SS(ll n)
    {
        arr.resize(n);
    }
    bool check(ll t)
    {
        return 0;
    }
    ll getAns()
    {
        ll l = minLim,
           r = maxLim + 1;
        while (l + 1 < r)
        {                          // 如果两点不相邻
            ll mid = (l + r) / 2; // 取中间值
            if (check(mid))        // 如果可行
                l = mid;           // 升高锯片高度
            else
                r = mid; // 否则降低锯片高度
        }
        return l; // 返回左边值
    }
};


void solve()
{
    ll int n;
    cin >> n;
    ll int k,m,c,d;
    cin >> k >> m >> c >> d;
    SS ss = SS(n);
    for(int i = 0;i < n;i ++) cin >> ss.arr[i];
    
}

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