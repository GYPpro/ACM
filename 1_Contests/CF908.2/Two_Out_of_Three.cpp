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
    map<int,vector<int>> cnt;
    for(int i = 0;i < n;i ++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp].push_back(i);
    }
    int sup = 0;
    for(auto i = cnt.begin();i != cnt.end();i ++) if((*i).second.size() >= 2) sup ++;
    if(sup < 2){
        cout << -1 << "\n";
        return;
    }
    vector<int> ans(n,1);
    int rq = 2;
    for(auto x = cnt.begin();rq;x ++)
    {
        if((*x).second.size() >= 2)
        {
            ans[(*x).second[0]] = rq+1;
            rq --;
        }
    }
    for(int i = 0;i < n;i ++) cout << ans[i] << " ";
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