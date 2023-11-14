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

int dfs(map<int, int> prv, int mx, int w)
{
    // cout << prv.size() << " " << n << " " << w << "\n";z
    if (prv.size() == 0)
        return 0;
    // int mincs = 114514;
    int maxit = 0;
    int maxid = 0;
    for (int i = 1; i < (1 << prv.size()); i++)
    {
        // map<int, int> cnt = prv;
        auto x = prv.begin();
        int tmp = i;
        int sum = 0;
        while (tmp)
        {
            if (tmp % 2)
            {
                sum += (*x).second;
                // auto y = x;
                // y++;
                // cnt.erase(x);
                // x = y;
            }
            tmp /= 2;
            x ++;
        }
        if (sum > w)
            continue;
        if (sum > maxid)
        {
            maxid = sum;
            maxit = i;
        }
        // mincs = min(mincs, dfs(cnt, mx, w) + 1);
    }       // map<int, int> cnt = prv;
    map<int, int> cnt = prv;
    auto x = cnt.begin();
    while (maxit)
    {
        if (maxit % 2)
        {
            auto y = x;
            y++;
            cnt.erase(x);
            x = y;
        } else x++;
        maxit /= 2;
        // x ++;
    }
    return dfs(cnt,mx,w)+1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    cout << dfs(cnt, 1 << cnt.size(), k);
    // int mx = 1<<cnt.size();
    // for(int i = 0;i < 13;i ++)
    // {
    //     for(int i = 0;i < mx;i ++)
    //     {

    //     }
    // }
    // multiset<int> art;
    // for (auto x = cnt.begin(); x != cnt.end(); x++)
    // {
    //     art.insert(k-(*x).second);
    // }
    // int sum = 1;
    // int dw = 0;
    // for (int i = 0; i < 13; i++)
    // {
    //     if (art.size() == 0)
    //         break;
    //     auto x = art.lower_bound(dw);
    //     if (x == art.end())
    //     {
    //         dw = 0;
    //         sum++;
    //     }
    //     else
    //     {
    //         art.erase(x);
    //         dw += k-(*x);
    //     }
    // }
    // cout << sum << "\n";
}

// #define _WITH_T_.

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