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
    // map<int,int> cntl;
    // map<int,int> cntr;
    // vector<int> arr(n+1);
    // for(int i = 0;i < n;i ++)
    // {
    //     cin >> arr[i];
    //     if(i) cntr[arr[i]] = 0;
    //     else cntr[arr[i]] ++;
    //     cntl[arr[i]] = 0;
    // }
    // ll int ans = 0;
    // for(int i = 0;i < n;i ++)
    // {
    //     bool cmpl = (cntl[arr[i]] == 0);
    //     bool cmpr = (cntr[arr[i]] == 0);
    //     if(cmpl) ans += i;
    //     if(cmpr) ans += n-1-i;
    //     if(cmpr && cmpl) ans += 1;
    //     cntl[arr[i]] ++;
    //     cntr[arr[i]] --;
    // }
    // cout << ans << "\n";
    map<int,pair<int,int>> mtr;
    vector<int> cmp(n+1,0);
    vector<int> arr(n+1);
    vector<int> elc(n+1,0);
    for(int i = 1;i <= n;i ++)
    {
        cin >> arr[i];
        if(mtr.find(arr[i]) == mtr.end()){
            mtr[arr[i]] = pair<int,int>(0,i);
            continue;
        }
        cmp[i] = 1;
        mtr[arr[i]].first = mtr[arr[i]].second;
        mtr[arr[i]].second = i;
    }
    int mx = 0;
    for(auto x = mtr.begin();x != mtr.end();x ++) mx = max((*x).second.first,mx);
    for(auto x = mtr.begin();x != mtr.end();x ++) elc[(*x).second.second] = 1;
    for(int i = n;i > 0;i --) elc[i-1] += elc[i]; 
    ll int ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(cmp[i]) continue;
        ans += min(n-i+1,elc[i]);
    }
    cout << ans << "\n";
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