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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    ll int n,k,x;
    cin >> n >> k >> x;
    if(n < k) {
        cout << "No\n";
    } else {
        ll int mik = k*(k+1)/2;
        ll int mxk = (n-(n-k+1)+1) * (n+(n-k+1)) /2;
        // cout << "mik = " << mik << " mxk = " << mxk << endl;
        if(x >= mik && x <= mxk) cout << "Yes\n";
            else cout << "No\n";
    }
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