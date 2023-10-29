#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
long long ans;
int a[55], b[55];
void sovle()
{
    cin >> n >> m >> k;
    int aa, bb;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    if (a[1] <= b[1])
    {
        if (a[n] >= b[m]) // 有最小有最大
        {
            if (k % 2)
                ans += b[m] - a[1];
            else
                ans -= a[n] - b[m];
            // k奇数输出
            // 无最小有最大
            cout << ans << "\n";
        }
        else // 有最小无最大
        {
            if (k % 2)
                ans += b[m] - a[1]; // k奇数输出
            // k偶数输出ans+b[m]-a[1]
            cout << ans << "\n";
        }
    }
    else
    {
        if (a[n] <= b[m]) // 无最小无最大
        {
            if (k % 2)
                ans += b[m] - a[1];
            else
                ans -= a[1] - b[1];
            // k奇数输出
            // 无最小有最大
            cout << ans << "\n";
        }
        else // 无最小有最大
        {
            if (a[1] < b[m])
            {
                if (k % 2)
                    ans += b[m] - a[1];
            }
            else
            {
                if (k % 2 == 0)
                    ans -= a[n] - b[1];
            }
            // k为偶数输出
            // k为奇数输出ans+max(b[m]-a[1],0)
            cout << ans << "\n";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sovle();
    }
    return 0;
}