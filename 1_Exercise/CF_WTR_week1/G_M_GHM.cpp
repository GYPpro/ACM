#include <iostream>

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define pb push_back
#define ll long long
#define mod1 998244353

using namespace std;

// V2可以考虑类封装差分查询

int solMtx(const vector<vector<int>> mtx, int k) // V1
{
    int n = mtx[0].size();
    int m = mtx.size();
    // vector<vector<int>> mtx(m,vector<int>(n));//mtx2'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx[j][i] = _mtx[i][j];
    // swap(n,m);
    //[n][m]
    k++;
    vector<vector<int>> sumX(n);
    vector<vector<int>> sumD(m + n);

    for (int i = 0; i < n; i++)
    {
        sumX[i].pb(0);
        for (int j = 0; j < m; j++)
            sumX[i].pb(sumX[i][j] + mtx[j][i]);
    }

    for (int i = 0; i < m; i++)
    {
        sumD[i].pb(0);
        for (int j = 0; j < min(i, n); j++)
            sumD[i].pb(sumD[i][j] + mtx[i - j - 1][j]);
    }
    for (int i = 0; i < n; i++)
    {
        sumD[i + m].pb(0);
        for (int j = 0; j < min(n - i, m); j++)
            sumD[i + m].pb(sumD[i + m][j] + mtx[m - 1 - j][i + j]);
    }

    int maxAns = 0;
    int tsSum = 0;
    for (int i = 0; i < m; i++)
    {
        tsSum = 0;
        for (int j = 0; j < n; j++)
        {
            tsSum += sumX[j][i + 1] - sumX[j][max(0, i - k + 1)];
            if (i + j - k + 1 >= 0)
                if (i + j - k + 1 < m)
                    tsSum -= sumD[i + j - k + 1][min(j, (int)sumD[i + j - k + 1].size() - 1)] - sumD[i + j - k + 1][max(0, j - k)];
                // else tsSum -= sumD[max(0,m+(j-k-1))][min(m-i-1+k,(int)sumD[max(0,m+(j-k-1))].size()-1)] - sumD[max(0,m+(j-k-1))][max(0,m-i-1)];
                else
                    tsSum -= sumD[i + j - k + 1][min(m - i + k, (int)sumD[i + j - k + 1].size() - 1)] - sumD[i + j - k + 1][max(0, m - i - 1)];
            maxAns = max(tsSum, maxAns);
        }
    }
    return maxAns;
}

int solve(int n, int m, int k, vector<vector<int>> mtx1)
{
    // int n,m,k;
    // cin >> n >> m >> k;
    // vector<vector<int>> mtx1(n,vector<int>(m));//[n][m]

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //     {
    //         char c;
    //         cin >> c;
    //         if (c == '.')
    //             mtx1[i][j] = 0;
    //         else
    //             mtx1[i][j] = 1;
    //     }

    vector<vector<int>> mtx2(m, vector<int>(n)); // 90
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mtx2[j][n - 1 - i] = mtx1[i][j];

    vector<vector<int>> mtx3(n, vector<int>(m)); // +90
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mtx3[j][m - 1 - i] = mtx2[i][j];

    vector<vector<int>> mtx4(m, vector<int>(n)); // +90
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mtx4[j][n - 1 - i] = mtx3[i][j];

    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx2[n-i-1][m-j-1] = mtx1[i][j];

    // vector<vector<int>> mtx1p(m,vector<int>(n));//mtx1'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx1p[j][i] = mtx1[i][j];

    // vector<vector<int>> mtx2p(m,vector<int>(n));//mtx2'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx2p[j][i] = mtx2[i][j];

    return max(max(solMtx(mtx1, k), solMtx(mtx2, k)), max(solMtx(mtx3, k), solMtx(mtx4, k)));
}

class ot
{
public:
    int n, m, k;
    vector<vector<int>> a;

    bool prov(int i, int j)
    {
        return 0 <= i && i < n && 0 <= j && j < m;
    }

    int ans()
    {
        int cnt = 0;
        int dp[n][m];
        int pref[n][m];
        int pref_up[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pref_up[i][j] = a[i][j];
                if (prov(i - 1, j))
                    pref_up[i][j] += pref_up[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                pref[i][j] = a[i][j];
                if (prov(i - 1, j + 1))
                    pref[i][j] += pref[i - 1][j + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = pref_up[i][j];
                if (prov(i - k, j))
                    dp[i][j] -= pref_up[i - k][j];
                if (prov(i, j - 1))
                    dp[i][j] += dp[i][j - 1];
                if (j < k)
                {
                    int i1 = j - k + i;
                    if (i1 >= 0)
                        dp[i][j] -= pref[i1][0];
                }
                else
                    dp[i][j] -= pref[i][j - k];
                if (prov(i - k, j))
                    dp[i][j] += pref[i - k][j];
                cnt = max(cnt, dp[i][j]);
            }
        }

        return cnt;
    }

    int solve()
    {
        k++;
        char c;
        bool st[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                st[i][j] = a[i][j];

        int mx = ans();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = st[n - i - 1][j];
            }
        }
        mx = max(mx, ans());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = st[i][m - j - 1];
            }
        }
        mx = max(mx, ans());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = st[n - i - 1][m - j - 1];
            }
        }
        mx = max(mx, ans());

        return mx;
    }
};

int main()
{
    for (;;)
    {
        int n = rand() % 5+1;
        int m = rand() % 5+1;
        int k = rand() % 10;
        vector<vector<int>> atc(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int r = rand() % 4;
                if (r < 2)
                    atc[i][j] = 1;
            }

        int ans1 = solve(m, n, k, atc);
        ot OT;
        OT.m = n;
        OT.n = m;
        OT.k = k;
        OT.a = atc;
        int ans2 = OT.solve();
        if (ans1 != ans2)
        {
            cout << "war at :\n";
            cout << "n: " << n << " m:" << m << " k:" << k << "\n";
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << atc[i][j];
                cout << "\n";
            }
            cout << "with ans1:" << ans1 << " ans2:" << ans2 << "\n";
            system("pause");
        } else cout << "accept: " << n << '\n';
    }
}