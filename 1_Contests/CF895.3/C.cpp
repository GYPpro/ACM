#define _USE_IOSTREAM_
// #define _USE_STDIO_

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
#define maxn 10000100
#define ull unsigned long long

using namespace std;

int getEX(int n)
{
    if(n <= 2)return -1;
    int mx = sqrt(n);
    for(int i = 2;i <= mx;i ++)
        if(n%i == 0) return i;
    return -1;
}

void solve()
{
    ll int l,r;
    cin >> l >> r;
    if((r-l) < 0)
        cout << -1 << endl;
    else if((r-l) == 0) {
        int ex = getEX(l);
        if(ex == -1) cout << -1 << endl;
        else cout << ex << " " << l-ex << endl;
    } else {
        int tr = r-(r%2 != 0);
        if(tr > 2)cout << 2 << " " << tr-2 << endl;
        else cout << -1 << endl;
    }
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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