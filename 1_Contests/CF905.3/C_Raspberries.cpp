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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 4)
    {
        vector<int> arr(n);
        int mindiv = INT_MAX;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int sup = 0;
        for(int i = 0;i < n;i ++){
            if((arr[i] % 2) == 0) sup ++;
            if((arr[i] % 4) == 0) sup ++;
            
            mindiv = min((k - arr[i] % k) % k, mindiv);
        }
        cout << min(mindiv,max(0,2-sup)) << "\n";
    }
    else
    {
        int mindiv = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int tmpl;
            cin >> tmpl;
            mindiv = min((k - tmpl % k) % k, mindiv);
        }
        cout << mindiv << "\n";
    }
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}