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
    int n;
    cin >> n;
    n *= 2;
    vector<pair<int,int>> cnt;
    vector<int> arr(n);
    for(int i = 0;i < n;i ++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    for(int i = 0;i < n/2;i ++) 
        cnt.push_back(pair<int,int>(arr[i],arr[n-1-i]));       
    cout << cnt[cnt.size()-1].first - cnt[0].first - cnt[cnt.size()-1].second + cnt[0].second << "\n";
    for(int i = 0;i < cnt.size();i ++)
        cout << cnt[i].first << " " << cnt[i].second << "\n";
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