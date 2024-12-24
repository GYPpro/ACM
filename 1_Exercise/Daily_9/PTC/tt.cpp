#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2][1000010];
int n, k;
bool cnt = 0;
int lcm(int a, int b)
{
    int g = a / __gcd(a, b) * b;
    if (g < n)
        return g;
    else
    {
        cnt = 1;
        return n;
    }
}
int ggg = 0;
void solve()
{
    cin >> n >> k;
    // f[i][j] = max(lcm(f[i-1][j-1],i),f[i-1][j]);
    // ans = k (k满足：f[n][k]>=n)
    // 序列是k ,k-1 , ... , 1
    int mxj = 1;
    for (int i = 1; i <= k; i++)
    {
        f[i&1][1] = k;
        for (int j = 2; j <= mxj; j++)
        {
            f[i&1][j] = max(lcm(f[(i + 1)&1][j - 1], k - i + 1), f[(i + 1)&1][j]);
            ggg++;
            if (cnt)
            {
                mxj = j - 1;
                cnt = 0;
                break;
            }
            //  cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
        }
        if (mxj == i)
            mxj++;
    }
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << mxj + 1 << "\n";
    // cout << "cishu:: "<<ggg << "\n";
}
signed main()
{
    // freopen("s.in", "r", stdin);
    int st = clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int T;
    // cin >> T;
    // while (T--)
        solve();

    int et = clock();
    // cout << "time::" << (double)(et - st) / CLOCKS_PER_SEC << "\n";
}