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
    int n;
    cin >> n;
    // vector<int> l(n);
    set<ll int> l;
    vector<ll int> r(n);
    vector<ll int> c(n);
    for(int i = 0;i < n;i ++) 
    {
        int tmp;
        cin >> tmp;
        l.insert(-tmp);
    }
    for(int i = 0;i < n;i ++) cin >> r[i];
    for(int i = 0;i < n;i ++) cin >> c[i];
    
    // sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    // sort(c.begin(),c.end());
    for(int i = 0;i < n;i ++){
        auto x = l.upper_bound(-r[i]);
        r[i] += (*x);
        l.erase(x);
    }
    sort(c.begin(),c.end());
    sort(r.begin(),r.end());

    ll int cnt = 0;
    for(int i = 0;i < n;i ++) cnt += (ll)r[i] *(c[n-1-i]);
    cout << cnt << "\n";
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