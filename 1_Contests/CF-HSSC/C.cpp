#define _USE_IOSTREAM_
// #define _USE_STDIO_

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

ll binpow(int n){
    ll res = 1;
    ll a = 2;
    while(n){
        if(n&1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve()
{
    ll int n;
    cin >> n;
    ll int tmp = n;
    vector<int> binarr;
    while(n)
    {
        binarr.push_back(n%2);
        n >>= 1;
    }
    vector<int> ans;
    ans.push_back(tmp);
    for(int i = 0;i < binarr.size()-1;i ++)
    {
        if(binarr[i]) tmp -= binpow(i);
        else continue;
        ans.push_back(tmp);
    }
    for(int i = binarr.size()-2;i >= 0;i --) ans.push_back(binpow(i));
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i ++) cout << ans[i] << " ";
    cout << endl;
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
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