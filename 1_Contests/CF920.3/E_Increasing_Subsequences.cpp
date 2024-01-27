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
    ll k;
    cin >> k;
    ll lwc = -1e9 +2;
    ll upc = 1e9 -2;
    vector<int> rans;
    while(k>1)
    {
        if(k%2 == 0){
            rans.push_back(upc);
            k /= 2;
            upc --;
        } else {
            rans.push_back(lwc);
            k --;
            lwc ++;
        }
    }
    cout << rans.size() << "\n";
    for(int i = rans.size()-1;i >= 0;i --) cout << rans[i] << " ";
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