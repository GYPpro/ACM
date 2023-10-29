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
    string arr;
    cin >> n >> arr;
    // int tr = 0;
    // for(int i = arr.size();i >= 0;i --){
    //     if(arr[i] == '1') tr ++;
    //     ans[i] = ans[i+1]+tr;
    // }
    // for(int i = 0;i < n-tr;i ++) cout << ans[n-1-i] << " ";
    // for(int i = n-tr;i < n;i ++) cout << -1 << " ";
    // cout << "\n";
    ll int l,r,tr;
    l = arr.size()-1;
    r = arr.size()-1;
    tr = 0;
    vector<ll int> ans(n+1,0);
    for(;l >= 0;)
    {
        if(arr[l] == '1'){ tr ++;l --;}
        else {
            ans[r] = ans[r+1]+tr;
            l --;
            r --;
        }
    }
    for(int i = n-1;i > r;i --) cout << ans[i] << " ";
    for(int i = r;i >=0 ;i --) cout << -1 << " ";
    cout << "\n";
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