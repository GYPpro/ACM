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

void solve()
{
    ll int n;
    cin >> n;
    vector<ll int> cntarr(n+1,0);
    for(int i = 0;i < n;i ++)
    {
        ll int tmp;
        cin >> tmp;
        if(tmp <= n) cntarr[tmp] ++;
    }
    vector<ll int> ans(n+1,0);
    for(int i = 1;i <= n;i ++)
    {
        ll int tmp = i;
        for(;tmp <= n;tmp += i)
        {
            ans[tmp] += cntarr[i];
        }
    }
    int maxans = 0;
    for(int i = 1;i <= n;i ++)
    {
        maxans = max(maxans,(int)ans[i]);
    }
    cout << maxans << endl;
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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}