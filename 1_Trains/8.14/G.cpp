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

int subsearch(int l, int r, int tar, vector<int> &arr) // 找不到返回-1
{
    if (l == r)
    {
        if (arr[l] == tar)
            return l;
        else
            return -1;
    }
    int mid = (l + r) >> 1;
    if (arr[mid] == tar)
        return mid;
    else if (arr[mid] > tar)
        return subsearch(l, mid, tar, arr);
    else
        return subsearch(mid + 1, r, tar, arr);
}

void solve()
{
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    if (n == 1)
    {
        cout << "Bob" << endl;
        return;
    }

    if (n == 2)
    {
        if ((arr[0] ^ arr[1]) == k)
        {
            cout << "Alice" << endl;
        }
        else
        {
            if ((k == arr[0]) || (k == arr[1]))
                cout << "Bob" << endl;

            else if (k == 0)
            {
                cout << "Alice" << endl;
                return;
            }
        }
        return;
    }

    if((n == 3))
    {
        if((((arr[0]) ^ (arr[1])) == k) || (((arr[0]) ^ (arr[2])) == k) || (((arr[1]) ^ (arr[2])) == k))
        {
            cout << "Alice" << endl;
            return;
        } else {
            if(k == 0) {
                cout << "Bob" << endl;
            } else {
                cout << "Draw" << endl;
            }
            return;
        }
    }

    sort(arr.begin(), arr.end());

    // if(k == 0)
    // {
    //     for(int i = 0;i < n-1;i ++)
    //     {
    //         if(arr[i] == arr[i+1])
    //         {
    //             cout << "Alice" << endl;
    //             return;
    //         } else {
    //             cout << "Draw" << endl;
    //             return;
    //         }
    //     }
    // }

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        int tar = k ^ arr[i];
        int tmp = subsearch(0, n - 1, tar, arr);
        if (tmp != -1 && tmp != i)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
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