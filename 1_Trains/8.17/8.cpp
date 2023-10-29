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

ull binpow(ll int n, ll int m)
{
    ull res = 1;
    ull a = n;
    while (m)
    {
        if (m & 1)
            res = res * a;
        a = a * a;
        m >>= 1;
    }
    return res;
}

bool comp(vector<bool> a, vector<bool> b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return 1;
}

struct stf
{
    int idx;
    int sum;
};

void solve()
{
    ll int rn;
    cin >> rn;
    ll int n = binpow(2, rn) - 1;
    vector<vector<bool>> arr(n);
    vector<ll int> orip;
    ll int maxbin = 0;
    ll int totn = binpow(2, rn - 1);
    for (int i = 0; i < n; i++)
    {
        ll int tmp;
        cin >> tmp;
        orip.push_back(tmp);
        vector<bool> intmp;
        for (;;)
        {
            intmp.push_back(tmp % 2);
            tmp >>= 1;
            if (tmp <= 0)
                break;
        }
        if (intmp.size() > maxbin)
            maxbin = intmp.size();
        for (int j = intmp.size() - 1; j >= 0; j--)
        {
            arr[i].push_back(intmp[j]);
        }
    }
    sort(arr.begin(), arr.end(), comp);
    sort(orip.begin(), orip.end());
    vector<stf> maxarr(maxbin);
    for (int i = 0; i < maxarr.size(); i++)
    {
        maxarr[i].idx = n;
        maxarr[i].sum = 0;
    }
    for (int i = 0; i < maxbin; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = arr[j].size() - 1 - i;
            if (k < 0)
                continue;
            if (arr[j][k] == 1)
            {
                if (j < maxarr[i].idx)
                    maxarr[i].idx = j;
                maxarr[i].sum++;
            }
        }
    }
    for (int i = 0; i < maxbin; i++)
    {
        if ((maxarr[i].sum != totn) && (maxarr[i].sum != 0))
        {
            cout << "-1\n";
            return;
        }
    }
    vector<ll int> outinit;
    outinit.push_back(maxarr[maxarr.size() - 1].idx);
    for (int i = maxarr.size() - 2; i >= 0; i--)
    {
        if (maxarr[i].idx < outinit[outinit.size() - 1])
            outinit.push_back(maxarr[i].idx);
    }
    vector<ll int> outputarr;
    if (outinit.size() < rn)
    {
        for (int i = outinit.size(); i < rn; i++)
            outputarr.push_back(0);
    }
    for (int i = outinit.size() - 1; i >= 0; i--)
    {
        ll int tmpout = 0;
        ll int pow2 = 1;
        for (int j = arr[outinit[i]].size() - 1; j >= 0; j--)
        {
            if (arr[outinit[i]][j])
                tmpout += pow2;
            pow2 *= 2;
        }
        outputarr.push_back(tmpout);
    }
    sort(outputarr.begin(),outputarr.end());
    vector<ll int> topair;
    for (int k = 1; k <= n; k++)
    {
        ll int tmp = k;
        ll int tpidx = outputarr.size() - 1;
        ll int xorans = 0;
        for (;;)
        {
            if (tmp % 2)
                xorans ^= outputarr[tpidx];
            tmp >>= 1;
            if (tmp <= 0)
                break;
            tpidx--;
        }
        topair.push_back(xorans);
    }

    sort(topair.begin(), topair.end());

    for (int i = 0; i < n; i++)
    {
        if (topair[i] != orip[i])
        {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < outputarr.size(); i++)
    {
        if (i != n - 1)
            cout << outputarr[i] << " ";
        else
            cout << outputarr[i];
    }
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
