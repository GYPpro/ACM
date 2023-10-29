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
#include <set>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

void solve()
{
    ll int n,p;
    cin >> n >> p;
    vector<pair<int,int>> at(n);
    for(int i = 0;i < n;i ++) cin >> at[i].first;
    for(int i = 0;i < n;i ++) cin >> at[i].second;
    ll int spd = 0;
    ll int ct = 0;
    sort(at.begin(),at.end(),comp);

    for(int i = 0;i < n;i ++)
    {
        if(i >= spd){
            spd ++;
            ct += p;
        }
        if(spd >= n || at[i].second > p) break;
        ll thp = min(n-spd,(ll)at[i].first);
        ct += thp*at[i].second;
        spd += thp;
    }
    ct += max((ll)0,n-spd) * p;
    cout << ct << endl;
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