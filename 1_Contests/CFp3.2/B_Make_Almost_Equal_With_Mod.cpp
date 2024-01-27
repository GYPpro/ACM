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
    ll int k = 2;
    int n;
    cin >> n;
    vector<ll int> arr(n);
    for(int i = 0;i < n;i ++) cin >> arr[i];
    for(;k < INT64_MAX;k *= 2)
    {
        bool flag = 1;
        map<ll int,ll int> cnt;
        for(int i = 0;i < n;i ++)
        {
            cnt[arr[i]%k] ++;
            if(cnt.size() > 2){
                flag = 0;
                break;
            }
        }
        if(cnt.size() != 2) flag = 0;
        if(flag) break;
    }
    cout << k << "\n";
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