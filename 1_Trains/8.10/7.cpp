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

int parent[maxn];

int getparent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getparent(parent[x]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + 10; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        parent[getparent(x)] = getparent(y);
    }
    int k;
    cin >> k;
    int t1;
    cin >> t1;
    t1 = getparent(t1);
    for (int i = 1; i < k; i++)
    {
        int t2;
        cin >> t2;
        if (getparent(t2) != t1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    // for(int i = 1;i <= n;i ++)
    //     cout << getparent(i) << " ";
    // cout << endl;
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