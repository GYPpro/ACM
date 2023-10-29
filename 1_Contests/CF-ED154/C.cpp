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

// bool getlr(int l, int r, vector<int> &arr)
// {
//     int l0 = l, r0 = l + 1;
//     int l1 = r - 1, r1 = r;
//     for (; r0 <= r; r0++)
//     {
//         if (arr[r0] == arr[l0])
//             break;
//     }
//     for (; l1 >= l; l1--)
//     {
//         if (arr[l1] == arr[r1])
//             break;
//     }
//     if (r0 > l1)
//     {
//         bool l2 = false, r2 = false;
//         for (int i = l; i <= l1; i++)
//             if (arr[i] == 2)
//             {
//                 l2 = true;
//                 break;
//             }
//         for (int i = r; i >= r0; i--)
//             if (arr[i] == 2)
//             {
//                 r2 = true;
//                 break;
//             }
//         if (l2 && r2)
//             return false;
//         else
//             return true;
//     }
//     else
//     {
//         return getlr(r0, l1, arr);
//     }
// }



void solve()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    
    string s;
    cin >> s;
    int nv = 0;
    int p1 = 0;
    int p0 = maxn;
    for(int i = 0;i < s.length();i ++)
    {
        switch(s[i]) {
            case '+':{
                nv ++;
                break;
            };
            case '-':{
                nv --;
                if(nv < p1) p1 = nv; 
                if(nv < p0) p0 = maxn;
                break;
            };
            case '0':{
                if(nv == 1) {
                    cout << "No" << endl;
                    return;
                }
                if(nv <= p1) {
                    cout << "No" << endl;
                    return;
                }
                if(nv < p0) p0 = nv;
                break;
            };
            case '1':{
                if(nv >= p0) {
                    cout << "No" << endl;
                    return;
                }
                if(nv > p1) p1 = nv;
                break;
            }
        }
    }
    cout << "Yes" << endl;
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