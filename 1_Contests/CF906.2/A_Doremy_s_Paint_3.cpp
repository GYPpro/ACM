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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int,int> cnt;
    for(int i = 0;i < n;i ++){
        int tmp;
        cin >> tmp;
        cnt[tmp] ++;
    }
    if(cnt.size() >= 3) cout << "No\n";
    else if(cnt.size() == 2) {
        auto x1 = cnt.begin();
        auto x2 = x1++;
        // cout << (*x1).second << " " <<  (*x2).second << endl;
        if(abs((*x1).second - (*x2).second) > 1) cout << "No\n";
        else cout << "Yes\n";
    } else cout << "Yes\n";
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