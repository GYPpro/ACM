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

bool comp(int a,int b)
{
    return a > b;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a1(n);
    vector<int> a2(m);
    for(auto &x:a1) cin >> x;
    for(auto &x:a2) cin >> x;
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end(),comp);
    int sf = 0;
    int se = 0;
    int ans = 0;
    for(int i = 0;i < n;i ++) sf += abs(a1[i]-a2[i]);
    for(int i = n-1;i >= 0;i --)
    {
        ans = max(ans,sf+se);
        sf -= abs(a1[i]-a2[i]);
        se += abs(a1[i]-a2[i+(m-n)]);
    }
    ans = max(ans,sf+se);
    cout << ans << "\n";
}

#define _WITH_T_

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