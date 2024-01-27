// #define _USE_IOSTREAM_
// // #define _PRIV_TEST_

// #ifndef _USE_IOSTREAM_
// #define _USE_STDIO_
// #endif

// #ifdef _USE_IOSTREAM_
// #include <iostream>
// #endif
// #ifdef _USE_STDIO_
// #include <stdio.h>
// #endif

// #include <stdlib.h>
// #include <math.h>
// #include <algorithm>
// #include <string>
// #include <string.h>
// #include <vector>

// #define ll long long
// #define mod1 998244353
// #define maxn 1000100
// #define ull unsigned long long

// using namespace std;

// int getInvIdx(int idx, int l, int r)
// {
//     return l + r - idx;
// }

// class distc
// {
// public:
//     int l;
//     int r;

// public:
//     distc(int _l, int _r)
//     {
//         l = _l;
//         r = _r;
//     }
//     distc()
//     {
//         l = 0;
//         r = 0;
//     }
// };

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;
//     s.push_back('a');
//     for (int i = n; i > 0; i--)
//         s[i] = s[i - 1];
//     vector<int> l1(n + 1);
//     vector<int> l2(n + 1);
//     for (int i = 0; i < k; i++)
//         cin >> l1[i];
//     for (int i = 0; i < k; i++)
//         cin >> l2[i];
//     vector<distc> arr(n + 1);
//     for (int i = 0; i < k; i++)
//     {
//         for (int j = l1[i]; j <= l2[i]; j++)
//         {
//             arr[j].l = l1[i];
//             arr[j].r = l2[i];
//         }
//     }
//     vector<bool> rev(n + 2, 0);
//     int S;
//     cin >> S;
//     for (int i = 0; i < S; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         tmp = min(tmp, getInvIdx(tmp, arr[tmp].l, arr[tmp].r));
//         rev[tmp] = !rev[tmp];
//         rev[getInvIdx(tmp, arr[tmp].l, arr[tmp].r) + 1] = !rev[getInvIdx(tmp, arr[tmp].l, arr[tmp].r) + 1];
//     }
//     bool otflag = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (rev[i])
//             otflag = !otflag;
//         if (otflag)
//             cout << s[getInvIdx(i, arr[i].l, arr[i].r)];
//         else
//             cout << " ";
//     }
//     cout << endl;
// }

// #define _WITH_T_

// int main()
// {
// #ifndef _PRIV_TEST_
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cout.tie(0);
// #endif
//     int T = 1;

// #ifdef _WITH_T_
// #ifdef _USE_IOSTREAM_
//     cin >> T;
// #endif
// #ifdef _USE_STDIO_
//     scanf("%d", &T);
// #endif
// #endif

//     // for(;;) test();
//     for (int i = 0; i < T; i++)
//         solve();

//     // system("pause");

//     return 0;
// }
#include<string>
#include<iostream>
using namespace std;

void solve()
{
    string s,t;
    cin >> s >> t;
    bool flag = true;
    for(int i = 0;i < s.size();i ++)
        for(int j = 0;j < min((int)(s.size()-i),(int)t.size());j ++)
            if(s[i+j] != t[j]) {flag = false;break;}
    if(flag) cout << "yes\n";
    else cout << "no\n";
}