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

// vector<ll int> init(ll int n)
// {
//     vector<ll int> pri;
//     vector<bool> vis(n, 0);
//     for (int i = 2; i <= n; i++)
//     {
//         if (!vis[i])
//             pri.push_back(i);
//         for (int j = 0; j < pri.size(); j++)
//         {
//             if (i * pri[j] > n)
//                 break;
//             vis[pri[j] * i] = 1;
//             if (i % pri[j] == 0)
//                 break;
//         }
//     }
//     return pri;
// }

// vector<ll int> pri = init(100010);
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    int rt = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
        {
            bool flag = true;
            vector<int> sub1;
            for (int j = 0; j < i; j++)
                sub1.push_back(arr[j]);
            // int ls = abs(sub1[0] - arr[i]);

            bool uf = 0;
            int unp1, unp2, bfidx;
            for (int j = i; j < n; j++)
            {
                if (sub1[j % i] != arr[j])
                {
                    unp1 = abs(sub1[j % i] - arr[j]);
                    bfidx = j;
                    uf = 1;
                    break;
                }
            }
            if (!uf)
            {
                rt++;
                continue;
            }
            uf = 0;

            for (int j = bfidx + 1; j < n; j++)
            {
                if (sub1[j % i] != arr[j])
                {
                    unp2 = abs(sub1[j % i] - arr[j]);
                    bfidx = j;
                    uf = 1;
                    break;
                }
            }
            if (!uf)
            {
                if(unp1 != 1) rt++;
                continue;
            }
            int ls = gcd(unp1, unp2);
            if (ls == 1)
            {
                flag = false;
                continue;
            }
            for (int j = bfidx + 1; j < n; j++)
            {
                if (sub1[j % i] == arr[j])
                    continue;
                if ((ls = gcd(ls, abs(sub1[j % i] - arr[j]))) == 1)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                rt++;
        }

    cout << rt << "\n";
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