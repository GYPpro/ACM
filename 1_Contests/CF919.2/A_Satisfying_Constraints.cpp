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

#define ll long long
#define mod1 998244353

using namespace std;

void solve()
{
    ll int n;
    cin >> n;
    ll minn = 0;
    ll maxn = 10000000000;
    vector<ll> uneq;
    for(int i = 0;i <n;i ++)
    {
        int f;
        cin >> f;
        ll int t;
        switch (f)
        {
        case 1:
        {
            cin >> t;
            minn = max(t,minn);
        }
            break;
        case 2:
        {
            cin >> t;
            maxn = min(t,maxn);
        }
            break;
        case 3:
        {
            cin >> t;
            uneq.push_back(t);
        }
            break;
        
        default:
            break;
        }
    }
    int ans = maxn - minn +1;
    for(auto x:uneq){
        if(x <= maxn && x >= minn) ans --;
    }
    cout << max(0,ans) << "\n";
    return;
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