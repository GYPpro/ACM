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
#define maxn 1000100
#define ull unsigned long long

using namespace std;

bool getlr(int l, int r, vector<int> &arr)
{
    int l0 = l, r0 = l + 1;
    int l1 = r - 1, r1 = r;
    for (; r0 <= r; r0++)
    {
        if (arr[r0] == arr[l0])
            break;
    }
    for (; l1 >= l; l1--)
    {
        if (arr[l1] == arr[r1])
            break;
    }
    if (r0 > l1)
    {
        bool l2 = false, r2 = false;
        for (int i = l; i <= l1; i++)
            if (arr[i] == 2)
            {
                l2 = true;
                break;
            }
        for (int i = r; i >= r0; i--)
            if (arr[i] == 2)
            {
                r2 = true;
                break;
            }
        if (l2 && r2)
            return false;
        else
            return true;
    }
    else
    {
        return getlr(r0, l1, arr);
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;
    vector<int> arr(a.size()+10);
    bool if1 = 0, if2 = 0;
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '0')
                arr[i] = 0;
            else
                arr[i] = 1;
        }
        else
        {
            arr[i] = 2;
            if2 = 1;
        }
    }
    if (if2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if2 = 0;
    for (ll i = 0; i < a.size(); i++)
    {
        if (arr[i] == 1)
        {
            cout << "YES" << endl;
            return;
        }
        if (arr[i] == 2)
        {
            break;
        }
    }
    for (ll i = a.size() - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            cout << "YES" << endl;
            return;
        }
        if (arr[i] == 2)
            break;
    }
    ll cg = 0, j;
    for (ll i = 1; i < a.size(); i++)
    {
        if (arr[i] == 0 && arr[i + 1] == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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