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

bool comp(int a,int b)
{
    return a > b;
}

void solve()
{
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for(auto &y:arr) cin >> y;
    

    if(n == 1){
        cout << 0 << "\n";
        return;
    }

    sort(arr.begin(),arr.end(),comp);
    ll int sa = 0;
    ll int sb = 0;
    for(int i = 0;i < x;i ++) sa += arr[i];
    for(int i = x;i < n;i ++) sb += arr[i];
    ll maxans = -100000000000000LL;
    for(int i = 0;i <= k;i ++)
    {
        maxans = max(maxans,sb-sa);
        sa -= arr[i];
        if(i+x < n) sa += arr[i+x];
        if(i+x < n) sb -= arr[i+x];
    } 
    cout << maxans << "\n";
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