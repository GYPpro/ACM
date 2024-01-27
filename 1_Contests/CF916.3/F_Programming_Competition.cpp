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

int dfs(vector<vector<int>> &t,vector<int> &amt,int p)
{
    if(t[p].size() == 0) return amt[p] = 1;
    if(amt[p] != 0) return amt[p];
    int sum = 0;
    for(int i = 0;i < t[p].size();i ++) sum += dfs(t,amt,t[p][i]);
    return amt[p] = sum + 1;
}

int f(vector<vector<int>> &t,vector<int> &amt,int p)
{
    if(t[p].size() == 0) return 0;
    if(t[p].size() == 1) return f(t,amt,t[p][0]);
    vector<int> vrd;
    for(int i = 0;i < t[p].size();i ++) vrd.push_back(f(t,amt,t[p][i]));
    int sum = 0;
    for(int i = 0;i < vrd.size();i ++) sum += vrd[i];
    int pvmx = 0;
    for(int i = 0;i < t[p].size();i ++) pvmx = max(pvmx,min((amt[p]-1)/2,max((int)t[p].size()/2,vrd[i] + min(amt[t[p][i]],amt[p]-1-amt[t[p][i]]))));
    return pvmx;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> t(n+1);
    vector<int> amt(n+1);
    for(int i = 2;i <= n;i ++){
        int tmp;
        cin >> tmp;
        t[tmp].push_back(i);
    }
    dfs(t,amt,1);
    cout << min((n-1)/2,f(t,amt,1)) << "\n";
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