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
#define endl "\n"

using namespace std;

bool isPri(int n)
{
    for(int i = 2;i < sqrt(n)+1;i ++) if(n%i == 0)return 0;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    int t;
    int cnt = 0;
    vector<int> arr(n);
    for(int i = 0;i < n;i ++) cin >> arr[i];
    for(int i = 0;i < arr.size()-1;i ++)
    {
        if(!isPri(arr[i]+arr[i+1])){
            cnt ++;
            i ++;
        }
    }
    cout << cnt << endl;
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