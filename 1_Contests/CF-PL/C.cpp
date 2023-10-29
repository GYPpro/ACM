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

// int getque(vector<int> &arr)
// {
//     vector<bool> que(arr.size()+1);
//     for(int i = 0;i < n;i ++) que[i] = false;

//     for(int i = 0;i < arr.size();i ++)
//     {
//         que[arr[i]] = true;
//     }
// for(int i = 0;i < arr.size();i ++)
// {
//     if(!que[i]) return i;
// }
// }

int getidx(int i, int n)
{
    if (i < n)
        return i;
    else
        return i - n;/
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> que(n + 1);
    for (int i = 0; i < n + 1; i++)
        que[i] = 0;
    for (int i = 0; i < n; i++)
        que[arr[i]] = 1;
    int ans;
    for (int i = 0; i <= n; i++)
    {
        if (!que[i])
        {
            ans = i;
            break;
        }
    }
    arr.push_back(ans);
    int cnt = n - k % (n + 1) + 1;
    for (int i = 0; i < n; i++)
    {
        cout << arr[getidx(cnt + i, n + 1)] << " ";
    }
    cout << endl;
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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