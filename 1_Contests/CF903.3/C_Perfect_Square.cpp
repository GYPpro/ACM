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
#include <map>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

pair<int, char> getas(string s1)
{
    sort(s1.begin(), s1.end());
    int ans = 0;
    for (int i = 0; i < s1.size() - 1; i++)
        ans += s1[s1.size() - 1] - s1[i];
    return pair<int, char>(ans, s1[s1.size() - 1]);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    ll int ans = 0;

    for (int i = 0; i <= min(n / 2 + 1, n - 1); i++)
        for (int j = 0; j <= min(n / 2 + 1, n - 1); j++)
        {
            string s;
            s.push_back(arr[i][j]);
            s.push_back(arr[n - 1 - j][i]);
            s.push_back(arr[j][n - 1 - i]);
            s.push_back(arr[n - 1 - i][n - 1 - j]);
            pair<int, char> rt = getas(s);
            arr[i][j] = rt.second;
            arr[n - 1 - j][i] = rt.second;
            arr[j][n - 1 - i] = rt.second;
            arr[n - 1 - i][n - 1 - j] = rt.second;
            ans += rt.first;
        }

    cout << ans << endl;
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