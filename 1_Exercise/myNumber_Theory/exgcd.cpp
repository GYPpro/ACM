#define _USE_IOSTREAM_
#define _PRIV_TEST_
#define _WITH_T_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <myLib\myLib.h>

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <time.h>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

struct linerExpr{
    ll int x;
    ll int y;
};

pair<ll int,linerExpr> exgcd(ll int a,ll int b)
{
    // cout << "enter exgcd in a:" << a << " b:" << b << endl;
    if(b == 0)
    {
        linerExpr thisLE;
        thisLE.x = 1;
        thisLE.y = 0;
        ll int gcdAns = a;
        return pair<ll int,linerExpr>(a,thisLE);
    }
    pair<ll int,linerExpr> lastans = exgcd(b,a%b);
    pair<ll int,linerExpr> thisans = lastans;
    thisans.second.x = lastans.second.y;
    thisans.second.y = lastans.second.x - (a/b)*lastans.second.y;
    return thisans;
}

void solve()
{
    ll int a,b;
    a = rand();
    b = rand();
    pair<ll int,linerExpr> ans = exgcd(a,b);
    // cout << "the GCD is " << ans.first << " and " << a << " * " << ans.second.x << " + " << b << " * " << ans.second.y << " = " << ans.first << endl;
    bool ifcmp = (a*ans.second.x+b*ans.second.y) == ans.first;
    // if(ifcmp) cout << "------ comparation passed ------" << endl;
    // else cout << "====== comparation  error ======" << endl;
    if(!ifcmp)
    {
        cout << "====== comparation error↓ ======" << endl;
        cout << "the GCD is " << ans.first << " and " << a << " * " << ans.second.x << " + " << b << " * " << ans.second.y << " != " << ans.first << endl;
        system("pause");
    }
}


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
    srand(clock());
    clock_t st = clock();
    // for(;;) test();
    for (int i = 1; i <= T; i++){
        // if(i%(max(T/1000,1)) == 0)UpdatePrc(T,i,40,"caculating......");
        solve();
    }
    cout << T << "times exgcd for rand nums cmpleted caculat and competation in " << (double)(clock()-st)/CLOCKS_PER_SEC << "s" << endl;
    system("pause");

    return 0;
}