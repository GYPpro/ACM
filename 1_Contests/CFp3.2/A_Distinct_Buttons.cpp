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

int sign(int n)
{
    if (n>0) return 1;
    else if (n == 0) return 0;
    else return -1;
}

void solve()
{
    int n;
    cin >> n;
    map<int,int> cnt;
    for(int i = 0;i < n;i ++)
    {
        int tp1,tp2;
        cin >> tp1 >> tp2;

        cnt[sign(tp1)] ++;
        cnt[sign(tp2) +3] ++;
    }
    cnt.erase(0);
    cnt.erase(3);
    if(cnt.size() > 3) cout << "no\n";
    else cout << "yes\n";
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