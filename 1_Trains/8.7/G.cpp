#include <iostream>
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define ll long long
#define mod1 998244353
#define maxn 1000
#define ull unsigned long long

using namespace std;

int getidx(int i, int n)
{
    if (i < 0)
        return i + n;
    else if (i >= n)
        return i - n;
    else
        return i;
}

void solve()
{
    int A[maxn] = {0};
    int A2[maxn] = {0};
    int sum0 = 0;
    ll SUM = 0;
    int maxnum = -1;
    int maxidx = 0;
    int minnum = 1000000000;
    int minidx = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        SUM += A[i];
        if (A[i] == 0)
            sum0++;
        if (A[i] > maxnum)
        {
            maxnum = A[i];
            maxidx = i;
        }
        if ((A[i] < minnum) && (A[i] != 0))
        {
            minnum = A[i];
            minidx = i;
        }
    }
    for (int i = 0; i < n; i++)
        A2[i] = A[i];

    if (SUM == 0)
        cout << "YES" << endl;
    else if (SUM % 2 == 1)
        cout << "NO" << endl;
    else if (k > n / 2)
        cout << "NO" << endl;
    else if ((k == n / 2) && (n % 2 == 0))
    {
        for (int i = 0; i < n; i++)
        {
            if (A[getidx(i, n)] != A[getidx(i - k, n)])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        int sum0tmp = sum0;
        for (int i = getidx(minidx,n);; i = getidx(i + 1, n))
        {            
            if (!sum0tmp)
            {
                cout << "YES" << endl;
                return;
            }
            if (A2[i] == 0)
                continue;
            if (!(A2[getidx(i + k, n)] || A2[getidx(i - k, n)]))
                break;

            if (A2[getidx(i + k, n)] != 0)
            {
                int divtmp = min(A2[i], A2[getidx(i + k, n)]);
                A2[getidx(i + k, n)] -= divtmp;
                A2[i] -= divtmp;
            }
            if (A2[i] == 0)
                sum0tmp--;
        }
        sum0tmp = sum0;
        // for (int i = getidx(minidx,n);; i = getidx(i - 1, n))
        // {            
        //     if (!sum0tmp)
        //     {
        //         cout << "YES" << endl;
        //         return;
        //     }
        //     if (A[i] == 0)
        //         continue;
        //     if (!(A[getidx(i + k, n)] || A[getidx(i - k, n)]))
        //         break;

        //     if (A[getidx(i - k, n)] != 0)
        //     {
        //         int divtmp = min(A[i], A[getidx(i - k, n)]);
        //         A[getidx(i - k, n)] -= divtmp;
        //         A[i] -= divtmp;
        //     }
        //     if (A[i] == 0)
        //         sum0tmp--;
        // }
        cout << "NO" << endl;
    }
    return;
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;

    // scanf("%d",&T);
    cin >> T;
    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");
    return 0;
}