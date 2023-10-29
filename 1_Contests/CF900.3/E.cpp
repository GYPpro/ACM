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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void build(int s, int t, int p, vector<int> &d, vector<int> &a)
{
    if (s == t)
    {
        d[p] = a[s];
        return;
    }
    int m = s + ((t - s) >> 1);
    build(s, m, p * 2, d, a);
    build(m + 1, t, p * 2 + 1, d, a);
    d[p] = d[p * 2] & d[(p * 2) + 1];
}

int getsum(int l, int r, int s, int t, int p, vector<int> &d)
{
    if (l <= s && t <= r)
        return d[p];
    int m = s + ((t - s) >> 1);
    int sum = INT_MAX;
    if (l <= m)
        sum &= getsum(l, r, s, m, p * 2, d);
    if (r > m)
        sum &= getsum(l, r, m + 1, t, p * 2 + 1, d);
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> d(4 * (n + 1), 0);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, n, 1, d, a);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int st, k;
        cin >> st >> k;
        if (a[st] < k)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            int r = n + 1;
            int l = st;
            while (l + 1 < r)
            {
                int mid = (l + r) / 2;
                if (getsum(st, mid, 1, n, 1, d) >= k)
                    l = mid;
                else
                    r = mid;
            }
            cout << l << endl;
        }
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