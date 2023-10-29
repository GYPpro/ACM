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

bool ifAP(vector<ll int> &arr)
{
    ll int cp = arr[0];
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != cp)
            return 0;
    return 1;
}

void solve()
{
    vector<ll int> arr(3);
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    for (int i = 0; i < 3; i++)
    {
        if (ifAP(arr))
            break;
        sort(arr.begin(), arr.end());
        arr.push_back(arr[0]);
        arr[arr.size() - 2] -= arr[0];
    }
    if (ifAP(arr))
        cout << "YES\n";
    else
        cout << "NO\n";
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