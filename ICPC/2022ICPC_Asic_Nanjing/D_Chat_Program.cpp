#define _USE_IOSTREAM_
// #define _PRIV_TEST_

// #define _WITH_T_

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
//HACK:
class SS
{
public:
    vector<ll> arr;
    vector<ll int> cnt;
    ll int sum;
    // ll int NO_CMP, ALL_CMP;
    ll maxLim;
    ll minLim;
    ll int n, k, m, c, d;
    int prm(ll int i)
    {
        return min((ll)max(i, 0LL), n);
    }
    void fill()
    {
        for (int i = 0; i < cnt.size(); i++)
            cnt[i] = 0;
    }
    SS(ll _n)
    {
        n = _n;
        arr.resize(n + 1);
        cnt.resize(n + 2);
    }
    bool check(ll t)
    {
        fill();
        for (int i = 1; i <= n; i++)
        {
            if(arr[i] > t)
            {
                cnt[1] ++;
                cnt[n+1]--;
            }else if (!d)
            {
                if((arr[i] + c) > t)
                {
                    cnt[prm(i-m)] ++;
                    cnt[prm(i)] --;
                }
            }
            else
            {
                ll int tc = (t - arr[i] - c) / d + 1; //  5-1:2*2;
                tc = min(tc,m);
                cnt[prm(i-m+1)] ++;
                cnt[prm(i-tc +1)] --;
            }
        }
        sum = 0;
        ll int maxn;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] += sum;
            sum = cnt[i];
            maxn = max(sum, maxn);
        }
        return maxn > k;
    }

    void init()
    {
        ll int tm = 0;
        for(int i = 0;i < arr.size(); i++) tm = max(arr[i],tm);
        maxLim = tm + m*d+c;
        minLim = 0;
    }

    ll getAns()
    {
        ll l = minLim,
           r = maxLim + 1;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

void solve()
{
    ll int n;
    cin >> n;
    SS ss = SS(n);
    cin >> ss.k >> ss.m >> ss.c >> ss.d;
    for (int i = 0; i < n; i++)
        cin >> ss.arr[i + 1];
    ss.init();
    cout << ss.getAns() << "\n";
}

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