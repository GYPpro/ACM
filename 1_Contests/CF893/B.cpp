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

int subserch(int l, int r, int tar)
{//*-*
    int mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (mid * mid * mid < tar)
            l = mid + 1;
        else
            r = mid;
    }
    re+turn l;
}

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> shop;
    shop.push_back(0);
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 0) continue;
        shop.push_back(tmp);
    }
    ll ans = 0;
    ll sumco = 1;
    for (int i = 0; i < m - 2; i++)
    {
        bool tag;
        if (shop[i + 2] - shop[i] <= d)
            tag = true;
        else
            tag = false;
        ans += tag;
        sumco += (shop[i+1]-shop[i])/d-1;
        if(shop[i] != 1)sumco++;
    }
    sumco += 2;
    if (shop[m - 1] - shop[m - 2] < d){
        sumco += (shop[m-1]-shop[m-2])/d;
        ans += 1;
    }
    if (ans == 0)
    {
        cout << sumco << " " << m << endl;
    }
    else
        cout << sumco - 1 << " " << ans << endl;
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}