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

vector<ll int> Pri;
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

bool ifPri(int n)
{
    int l = 0;
    int r = Pri.size();
    int ans = -1;
    while (r >= l)
    {
        int m = (l + r) >> 1;
        if (Pri[m] >= n)
        {
            if (Pri[m] == n)
                ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (ans == -1)
        return 0;
    else
        return 1;
}

void solve()
{
    int n;
    cin >> n;
    map<int, int> arr;
    // for(int i = 0;(Pri[i] < 1e6+10) && (i < Pri.size());i ++) arr[Pri[i]] = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        // int rt = tmp;
        if (ifPri(tmp))
        {
            auto tg = arr.find(tmp);
            if (tg == arr.end())
                arr[tmp] = 0;
            arr[tmp]++;
        }
        for (int j = 0; (j < Pri.size()) && (Pri[j] < min((int)sqrt(tmp) + 1, tmp)) && tmp; j++)
        {
            if (tmp % Pri[j] == 0)
            {
                do
                {
                    int oth = tmp/Pri[j];
                    if (ifPri(oth))
                    {
                        auto tg = arr.find(oth);
                        if (tg == arr.end())
                            arr[oth] = 0;
                        arr[oth]++;
                    }
                    auto tg = arr.find(Pri[j]);
                    if (tg == arr.end())
                        arr[Pri[j]] = 0;
                    arr[Pri[j]]++;
                    tmp /= Pri[j];
                } while (tmp % Pri[j] == 0 && ((j < Pri.size()) && (Pri[j] < min((int)sqrt(tmp) + 1, tmp)) && tmp));
            }
        }
    }
    // for(int i = 0;i < Pri.size();i ++)
    // {
    //     if((arr[Pri[i]] % n)){
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    for (auto x = arr.begin(); x != arr.end(); x++)
    {
        if ((*x).second % n != 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

    Pri = init(1e6 + 10);

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}