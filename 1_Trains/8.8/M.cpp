
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
#define maxn 100100
#define ull unsigned long long

using namespace std;

ll cnt = 0;
ll a[maxn];
ll b[maxn];
void merge(ll a[], ll l, ll r)
{
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    merge(a, l, mid);
    merge(a, mid + 1, r);
    ll i = l, j = mid + 1;
    for (ll k = l; k <= r; k++)
    {
        if (j > r || (i <= mid && a[i] <= a[j]))
            b[k] = a[i++];
        else
        {
            cnt += mid - i + 1;
            b[k] = a[j++];
        }
    }
    for (ll k = l; k <= r; k++)
        a[k] = b[k];
}

void solve()
{
    cnt = 0;
    ll int n;
    cin >> n;
    memset(b, 0, n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    merge(a, 1, n);
    cout << (cnt % 2) * 2 << " ";
    ll int fcnt = (n * (n - 1)) / 2 - cnt;
    fcnt %= 2;
    ll int s1, s2;
    s1 = (fcnt * 2) ^ n;
    s2 = ((fcnt * 2) ^ n) ^ 1;
    cout << max(s1, s2) << endl;
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