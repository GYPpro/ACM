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
    int h,w,y1,x1,y2,x2;
    cin >> h >> w >> x1 >> y1 >> x2 >> y2;
    int flag = 0;
    int l1 = y1,r1 = y1,l2 = y2,r2 = y2;
    for(int i = 1;i <= x2-x1;i ++)
    {
        r1 = min(w,r1+1);
        l1 = max(1,l1-1);
        if(i * 2 > x2-x1 ){
            if(l1 <= l2 && r1 >= r2) flag = 1;
            break;
        }
        r2 = min(w,r2+1);
        l2 = max(1,l2-1);
        if(i * 2 >= x2-x1 ){
            if(l1 >= l2 && r1 <= r2) flag = 2;
            break;
        }
    }
    if(flag == 0) cout  << "Draw\n";
    else if(flag == 1) cout << "Alice\n";
    else cout << "Bob\n";
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