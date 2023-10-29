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
    ll int n,c1,c2;
    cin >> n >> c1 >> c2;
    ll int ans = 0;
    for(int i = 0;i < n;i ++)
    {
        char s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        // cout << s << endl;
        if((s1 == s2) || (s1 == s3) || (s2 == s3))
        {
            // if(c2 <= 2*c1) ans += c1+c2;
            // else ans += 3*c1;
            ans += min(min(c1*3,c1+c2),c2*2);
        } else {
            ans += 3*min(c1,c2);
        }
    }
    cout << ans << endl;
}

// #define _WITH_T_

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