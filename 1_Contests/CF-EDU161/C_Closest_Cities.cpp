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

#define int long long
#define mod1 998244353

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    vector<int> div(n);
    for(int i = 1;i < n;i ++) div[i] = arr[i] - arr[i-1];
    vector<int> cnj(n);
    cnj[0] = 1;
    cnj[n-1] = -1;
    for(int i = 1;i < n-1;i ++)
    {
        if(div[i+1] == div[i]) cnj[i] = 0;
        else if(div[i+1] > div[i]) cnj[i] = -1;
        else cnj[i] = 1;
    }
    vector<int> f(n);
    vector<int> b(n);
    for(int i = 0;i < n-1;i ++)
    {
        if(cnj[i] != -1) f[i+1] = f[i]+1;
        else f[i+1] = f[i] + div[i+1];
    }
    for(int i = n-1;i > 0;i --)
    {
        if(cnj[i] != 1) b[i-1] = b[i]+1;
        else b[i-1] = b[i] + div[i];
    }
    int q;
    cin >> q;
    for(int i = 0;i < q;i ++)
    {
        int tf,tb;
        cin >> tf >> tb;
        tf --;tb --;
        if(tf > tb) cout << b[tb]-b[tf];
        else cout << f[tb] - f[tf];
        cout << "\n";
    }
}

#define _WITH_T_

signed main()
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