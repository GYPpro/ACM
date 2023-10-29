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
    int m;
    cin >> m;
    vector<int> s1(m + 1);
    vector<int> s2(m + 1);
    for (int i = 0; i < m; i++)
        cin >> s1[i];
    for (int i = 0; i < m; i++)
        cin >> s2[i];
    for (int i = 0; i < m; i++)
    {
        if (s2[i] > s1[i] * 3)
        {
            cout << i +1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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