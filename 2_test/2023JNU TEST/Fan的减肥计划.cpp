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

int subsearch_2(int tar, vector<int> &arr) // 第二类二分：取小于或等于tar的最大的元素
{
    int l = 0;
    int r = arr.size();
    int m = 0;
    while (r > l + 1)
    {
        int m = l + ((r - l) >> 1);
        if (arr[m] > tar)
            r = m;
        else
            l = m;
    }
    return l;
}

int f(int x,vector<int> &arr,vector<int> &rec)
{
    if(x < 0) return -1;
    if(x == 0) return 0;
    if(rec[x]) return rec[x];
    else {
        int maxr = subsearch_2(x,arr);
        int minn = 1145141;
        for(int i = 0;i <= maxr;i ++)
        {
            int k = f(x-arr[i],arr,rec);
            if(k != -1) minn = min(minn,k +1);
        }
        if(minn == 1145141) minn = -1;
        return rec[x] = minn;
    }
}

void solve()
{
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0;i < n;i ++) cin >> arr[i];
    // cout << "1\n";
    sort(arr.begin(),arr.end());
    vector<int> rec(x+1);
    rec[0] = 1;
    cout << f(x,arr,rec) << endl;
}

// #define _WITH_T_

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