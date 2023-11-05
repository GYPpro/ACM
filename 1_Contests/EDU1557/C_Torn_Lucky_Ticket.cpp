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
    map<pair<int,int>,int> cnt;
    vector<string> arr;
    for(int i = 0;i < n;i ++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
        int len = s.length();
        int sum = 0;
        for(int j = 0;j < s.length();j ++) sum += s[j]-'0';
        cnt[pair<int,int>(len,sum)] ++;
    }

    ll int ans = 0;
    for(int i = 0;i < n;i ++)
    {
        int sumr = 0;
        int suml = 0;
        for(int j = 0;j < arr[i].size();j ++)sumr += arr[i][j]-'0';
        for(int j = 0;j < arr[i].size()-1;j ++)
        {
            suml += arr[i][j]-'0';
            sumr -= arr[i][j]-'0';
            if((j+1)*2 >= arr[i].size()) 
                // ans += (2-(j==(arr[i].size()-1)))*cnt[pair<int,int>(2*(j+1)-arr[i].size(),suml-sumr)];
                ans += cnt[pair<int,int>(2*(j+1)-arr[i].size(),suml-sumr)]
        }
        suml = 0;
        sumr = 0;
        for(int j = 0;j < arr[i].size();j ++)suml += arr[i][j]-'0';
        for(int j = arr[i].size()-1;j > 0;j --)
        {
            suml -= arr[i][j]-'0';
            sumr += arr[i][j]-'0';
            if((arr[i].size()-(j)) *2 >= arr[i].size())
                ans += cnt[pair<int,int>(2*(arr[i].size()-(j))-arr[i].size(),sumr-suml)];
        }
        ans += cnt[pair<int,int>(arr[i].size(),suml+sumr)];
    }
    cout << ans << "\n";

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