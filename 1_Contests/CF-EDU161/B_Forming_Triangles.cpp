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

#define int long long
#define mod1 998244353

using namespace std;

int cc(int n)
{
    return (n*(n-1LL))/2LL;
}

int ccc(int n)
{
    return max(0LL,(n*(n-1LL)*(n-2LL))/6LL);
}

void solve()
{
    map<int,int> cnt;
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int t;
        cin >> t;
        cnt[t] ++;
    }
    vector<pair<int,int>> ptc;
    for(auto x:cnt) ptc.push_back(x);
    sort(ptc.begin(),ptc.end());
    int ttc = 0;
    map<int,int> sum;
    for(auto x:ptc) sum[x.first] = (ttc += x.second);
    int ans = ccc(cnt[ptc[0].first]);
    for(int i = ptc.size()-1;i > 0;i --)
        ans += cc(cnt[ptc[i].first]) * sum[ptc[i-1].first] + ccc(cnt[ptc[i].first]);
    cout << ans << "\n";
}

#define _WITH_T_

signed main()
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