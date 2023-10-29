#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>

#define ll long long
#define N 100005

using namespace std;

void solve()
{
    ll a, b, ans = 0;
    cin >> a >> b;
    ll tmp, stmp, i, j, k;
    tmp = abs(a - b);
    if (tmp % 2 == 1)
    {
        if ((ll)sqrt(tmp) * (ll)sqrt(tmp) == tmp)
            ans = 1;
        else
            ans = 2;
    }
    else
    {
        if ((ll)sqrt(tmp) * (ll)sqrt(tmp) == tmp)
            ans = 1;
        else
        {
            if (tmp % 4 == 0)
                ans = 2;
            else if ((tmp - 2) % 8 == 0)
                ans = 2;
            else if ((tmp - 6) % 8 == 0)
                ans = 3;
        }
    }
    cout << ans << endl;
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