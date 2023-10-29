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

struct sumtar
{
    int s[3];
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n + 1);
    vector<vector<int>> cnj(m);
    for (int i = 0; i < k; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        t1--;
        t2--;
        cnj[t2].push_back(t1);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m - (i == n); j++)
        {
            int tmp;
            cin >> tmp;
            arr[i].push_back(tmp);
        }
    }

    vector<vector<sumtar>> A(m);
    for (int i = 0; i < m; i++)
    {
        A[i].resize(250);
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            tmp = 0;
            for (int k = 0; k < cnj[i].size(); k++)
            {
                tmp += arr[j][cnj[i][k]] * pow(3, k);
            }
            A[i][tmp].s[arr[j][i]]++;
        }
    }

    long double p[3] = {1, 1, 1};
    for (int i = 0; i < m - 1; i++)
    {
        int tmp = 0;
        for (int k = 0; k < cnj[i].size(); k++)
        {
            tmp += arr[n][cnj[i][k]] * pow(3, k);
        }
        ll int sum = A[i][tmp].s[0] + A[i][tmp].s[1] + A[i][tmp].s[2];
        for (int r = 0; r < 3; r++)
        {
            p[r] *= (long double)A[i][tmp].s[arr[n][i]] / (long double)sum;
        }
    }

    int tmp = 0;
    for (int k = 0; k < cnj[m-1].size(); k++)
    {
        tmp += arr[n][cnj[m - 1][k]] * pow(3, k);
    }
    ll int sum = A[m - 1][tmp].s[0] + A[m - 1][tmp].s[1] + A[m - 1][tmp].s[2];
    for (int r = 0; r < 3; r++)
    {
        p[r] *= (long double)A[m - 1][tmp].s[r] / (long double)sum;
    }

    if (p[0] >= p[1]) // 0>1
    {
        if (p[2] >= p[0]) // 2>0
        {
            cout << "2\n";
        } // 2<0
        else
        {
            cout << "0\n";
        }
    }
    else
    { // 1>0
        if (p[2] > p[1])
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
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