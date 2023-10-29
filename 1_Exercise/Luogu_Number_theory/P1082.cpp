// #define _USE_IOSTREAM_
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

// ll int exgcd(ll int a,ll int b,ll int &x,ll int &y)
// {
//     if(!b){
//         x = 1;
//         y = 0;
//         return a;
//     }
//     ll int d = exgcd(b,a%b,x,y);
//     ll int t = x;
//     x = y;
//     y = t-(a/b)*y;
//     return d;
// }

void solve()
{

}

// #define _WITH_T_

int main()
{
    // #ifndef _PRIV_TEST_
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    // #endif
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    scanf("%d", &T);
#endif
#endif
    ll int n, p;
    // cin >> n >> p;
    scanf("%d %d",&n,&p);
    int inv[3000010];
    inv[1] = 1;
    printf("1\n");
    for (int i = 2; i <= n; i++){
        inv[i] = (p - p / i) * inv[p % i] % p;
        printf("%d\n",inv[i]);
    }
    
    // for(;;) test();

    // system("pause");

    return 0;
}