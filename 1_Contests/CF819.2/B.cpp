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
#define maxn 110
#define ull unsigned long long

#define N 50100

using namespace std;

struct _value
{
    ll a, b;
};

bool compare(_value a, _value b)
{
    return a.b < b.b;
}

bool compare2(_value a, _value b)
{
    return a.a < b.a;
}

_value value[N];

void solve()
{
    ll n, m, flag = 0, a, ans = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> m;
        ll min1 = N, min2 = N;
        if (m == 1)
        {
            cin >> a;
            value[flag].a = a;
            flag++;
        }
        else
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a;
                if (a < min1)
                {
                    min2 = min1;
                    min1 = a;
                }
                else if (a == min1 && min2 != min1)
                {
                    min2 = a;
                }
                else if (a > min1 && a < min2)
                {
                    min2 = a;
                }
            }
            // cout<<min1<<" "<<min2;
            value[flag].a = min1;
            value[flag].b = min2;
            flag += 1;
        }
    }
    // for(ll i=0;value[i]!=0;i++)
    // {
    //     cout<<value[i]<<" ";
    // }
    // cout<<flag;

    sort(value, value + flag, compare);

    for (ll j = flag-1; j > 0; j--)
    {
        ans += value[j].b;
    }
    ll int minia = value[0].a;
    for(int i = 0;i < n;i ++)
    {
        if(value[i].a < minia)
        {
            minia = value[i].a;
        }
    }
    ans += minia;
    cout << ans << endl;
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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}