#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>

#define ll long long
#define N 500

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll a[N], max_num_min = 1, max_num = 0, num = 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (ll i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            max_num_min++;
        else
            break;
        if (i == n - 1 && a[i] == a[i - 1])
        {
            cout << "YES" << endl;
            return;
        }
    }
    for (ll i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            num++;
        else
        {
            if (num > max_num)
                max_num = num;
            num = 1;
        }
        if (i == n - 1 && a[i] == a[i - 1])
        {
            // num++;
            if (num > max_num)
                max_num = num;
        }
    }
    if (max_num > max_num_min)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();
    // system("pause");
}