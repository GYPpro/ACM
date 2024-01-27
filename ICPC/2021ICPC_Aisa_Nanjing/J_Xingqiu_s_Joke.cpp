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

vector<ll int> init(ll int n)
{
    vector<ll int> pri;
    vector<bool> vis(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    return pri;
}

vector<ll int> pri;

bool ifpri(int n)
{
    int l = 0;
    int r = pri.size();
    int ans = -1;
    while (r >= l)
    {
        int m = l + ((r - l) >> 1);
        if (pri[m] >= n)
        {
            if (pri[m] == n)
                ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int getdiv(int n)
{
    int cnt = 0;
    while(n>1)
    {
        for(int i = 0;pri[i] <= n;i ++) if(n%pri[i] == 0){
            cnt ++;
            n /= pri[i];
            break;
        }
    }
    return cnt;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a != 1 && b != 1)
    {
        int gd = gcd(a, b);
        if (gd != 1)
        {
            a /= gd;
            b /= gd;
            int cp = getdiv(gd);
            cnt += cp;
            continue;
        }
        int div = abs(a - b);
        int cp = getdiv(div);
        if (div == 0)
            div = a;
        int cq = a % div;
        int aq = cq - div;
        if (-aq < cq)
        {
            a += -aq;
            b += -aq;
            cnt += -aq;
        }
        else
        {
            a -= cq;
            b -= cq;
            cnt += cq;
        }
        a /= div;
        b /= div;

        if (div == 1)
        {
            cnt += min(a - 1, b - 1);
            a = 1;
        }
        else
            cnt += cp;
    }
    cout << cnt << "\n";
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
    pri = init(1e6);
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