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
#define maxn 100100
#define ull unsigned long long

using namespace std;

bool A[maxn] = {1};

void solve()
{
    int n;
    cin >> n;
    memset(A, 1, sizeof(A));
    for(int i = 1;i < n/2+1;i ++)
    {
        int tmp = i;
        if(A[tmp] == 0)
            continue;
        for(;tmp <= n;tmp *= 2)
        {
            cout << tmp << " ";
            A[tmp] = 0;
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        if(A[i])
            cout << i << " ";
    }
    cout << endl;
}

#define _WITH_T_

int main()
{
    // std::ios::sync_with_stdio(false);
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