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
#define maxn 300100
#define ull unsigned long long

using namespace std;

void solve()
{
    ll int n;
    cin >> n;
    vector<ll int> Aa(n);
    for (int i = 0; i < n; i++)
        cin >> Aa[i];
    ll int sr = 0;
    ll int pv = maxn;
    ll int uo = 0, dn = maxn;
    for (int i = 0; i < n; i++)
    {
        if (Aa[i] > pv)
        {
            if (Aa[i] < dn)
            {
                sr++;
                dn = Aa[i];
            }
        }
        else
        {
            pv = Aa[i];
        }
    }
    cout << sr << endl;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#define ll long long
#define N 300010
using namespace std;
void solve()
{
    
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