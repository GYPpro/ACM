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
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    ll int n;
    cin >> n;
    ll int cnt = 0;
    ll int ans = 0;
    vector<ll int> arr(n);
    for(int i = 0;i < n;i ++) cin >> arr[i];
    for(int i = 1;i < n;i ++)
    {
        if(arr[i-1] > arr[i]){
            ll int pw = 0;
            ll int tmp = arr[i];
            do{
                tmp *= 2;
                pw ++;
            }while(arr[i-1] > tmp);
            cnt += pw;
            ans += cnt;
        } else {//arr[i-1] < arr[i]
            ll int pw = 0;
            ll int tmp = arr[i-1];
            do{
                tmp *= 2;
                pw ++;
            }while(tmp <= arr[i]);
            pw --;
            cnt -= pw;
            cnt = max(0LL,cnt);
            ans += cnt;
        }
    }
    cout << ans << "\n";
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