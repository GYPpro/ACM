#define _USE_IOSTREAM_
#define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

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
#include <math.h>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

ll int arrtoInt(vector<int> &arr)
{
    ll int pw = 1;
    ll int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans += arr[i] * pw;
        pw *= 3;
    }
    return ans;
}

ll int  solve(ll int r,ll int l)
{
    // ull l, r;
    // cin >> r >> l;
    ull tr, tl;
    tr = r;
    tl = l;
    vector<int> thl;
    vector<int> thr;
    do
    {
        thl.push_back(tl % (ll)3);
        tl /= (ll)3;
    } while (tl);
    do
    {
        thr.push_back(tr % (ll)3);
        tr /= (ll)3;
    } while (tr);

    for (int i = thr.size(); i < thl.size(); i++)
        thr.push_back(0);

    int ans = 0;
    for(int i = 0;i < thl.size();i ++) ans += thl[i] +1;
    for (int i = 0; i < thl.size(); i++)
    {
        if (thl[i] == 0)
            continue;
        vector<int> pvArr;
        int j = 0;
        for (j = 0; j < i; j++)
            pvArr.push_back(2);
        if (j < thl.size())
        {
            pvArr.push_back(thl[i] - 1);
            j ++;
        }
        for (; j < thl.size(); j++)
            pvArr.push_back(thl[j]);

        // for(int j = 0;j < pvArr.size();j ++) cout << pvArr[i] << " ";

        ll int pv = arrtoInt(pvArr);
        if (pv > l || pv < r)
            continue;
        int anst = 0;
        for (int j = 0; j < pvArr.size(); j++)
            anst += pvArr[j] + 1;
        for(int j = pvArr.size()-1;j >= 0;j --)
        {
            if(pvArr[i] != 0) break;
            anst --;
        }
        ans = max(ans, anst);
        // cout << i << " " << ans << endl;
    }

    return ans;
    // return;
    // // ull l, r;
    // // cin >> r >> l;
    // vector<int> thl;
    // vector<int> thr;
    // do
    // {
    //     thl.push_back(l % (ll)3);
    //     l /= (ll)3;
    // } while (l);
    // do
    // {
    //     thr.push_back(r % (ll)3);
    //     r /= (ll)3;
    // } while (r);
    // for (int i = thr.size(); i < thl.size(); i++)
    //     thr.push_back(0);
    // ll int anst = 0;
    // ll int fhi = -1;
    // for (int i = thl.size() - 1; i >= 0; i--)
    // {
    //     // fhi = i;
    //     if (thl[i] != thr[i])
    //     {
    //         fhi = i;
    //         break;
    //     }
    //     else
    //         anst += thl[i] + 1;
    // }
    // if (fhi == -1)
    // {
    //     // cout << anst << endl;
    //     return anst;
    // }

    // if (thl[fhi] == 2) // 若分界点为2：
    // {
    //     if (fhi == 0) // 分界点处于末尾，取xxxx2
    //         anst += 3;
    //     else
    //     {
    //         bool all2 = 1;
    //         for (int j = fhi; j >= 0; j--) // 是否都2
    //         {
    //             if (thl[j] != 2)
    //             {
    //                 all2 = 0;
    //                 break;
    //             }
    //         }
    //         if (all2) // 若全为2，取xxxx2..2
    //             anst += 3 * (fhi + 1);
    //         else // 若不全为2，取xxxx12..2
    //             anst += 3 * (fhi + 1) - 1;
    //     }
    // }
    // else if (thl[fhi] == 1) // 若分界点为1：
    // {
    //     bool all2 = 1;
    //     for (int j = fhi - 1; j >= 0; j--) // 以后是否都2
    //     {
    //         if (thl[j] != 2)
    //         {
    //             all2 = 0;
    //             break;
    //         }
    //     }
    //     if (fhi == thl.size() - 1) // 分界点前没有前缀
    //     {
    //         if (all2) // 全2，选12..2
    //             anst += 3 * (fhi + 1) - 1;
    //         else
    //         {
    //             if (fhi == 0) // 分界点处于末尾 取1
    //             {
    //                 anst += 2;
    //             }
    //             else if (thl[fhi - 1] == 1) // 若为11xxx
    //             {
    //                 if (fhi == 1)
    //                     anst += 4; // 若为倒数第二个，取11而非02
    //                 else if (thl[fhi - 2] == 1)
    //                 { // 若不是倒数第二个，且为111xxx，选02..2一定比1102..2好，但是111222呢？
    //                     // 先判断是不是1112222
    //                     // 是就选，否则选022222
    //                     //  anst += 3 * (fhi + 1) - 3;
    //                     all2 = 1;
    //                     for (int j = fhi - 2; j >= 0; j--) // 以后是否都2
    //                     {
    //                         if (thl[j] != 2)
    //                         {
    //                             all2 = 0;
    //                             break;
    //                         }
    //                     }

    //                     if (all2)
    //                         anst += 3 * (fhi + 1) - 2; // 112222
    //                     else
    //                         anst += 3 * (fhi + 1) - 3; // 022222
    //                 }
    //                 else
    //                 {
    //                     if (thl[fhi - 2] == 2) // 不是倒数第二个，且是112xxxx
    //                     {
    //                         all2 = 1;
    //                         for (int j = fhi - 2; j >= 0; j--) // 以后是否都2
    //                         {
    //                             if (thl[j] != 2)
    //                             {
    //                                 all2 = 0;
    //                                 break;
    //                             }
    //                         }
    //                         if (all2)
    //                             anst += 3 * (fhi + 1) - 2; // 112222
    //                         else
    //                             anst += 3 * (fhi + 1) - 3; // 02xxx2
    //                     }
    //                     else
    //                         anst += 3 * (fhi + 1) - 3; // 02xxx2
    //                 }
    //             }
    //             else
    //                 anst += 3 * (fhi + 1) - 3; // 02xxx2
    //         }
    //     }
    //     else
    //     {
    //         if (all2) // 122.22
    //             anst += 3 * (fhi + 1) - 1;
    //         else // 11222 < 02222
    //         {
    //             anst += 3 * (fhi + 1) - 2;
    //         }
    //     }

    // }
    
    // // cout << anst << endl;
    // return anst;
}
#define _WITH_T_

unsigned long long f(unsigned long long x)
{
    if(x == 0)return 1;
    else if(x%3 == 0) return f(x/3)+1;
    else return f(x-1)+1;
}



int main()
{
#ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    scanf("%d", &T);
#endif
#endif


        srand(114514);
    // for(;;) test();
    for (;;)
    {
        ll int l = rand();
        ll int r = l + rand();
        ll int mx = 0;
        for(int i = l;i <= r;i ++)
        {
            mx = max(mx,(ll)f(i));
        }
        if(mx != solve(l,r)){
            system("pause");
            cout << "---ERROR---\n";
            cout << "in l:" << l << " r:" << r << endl;
            cout << "mx:" << mx << " ans:" << solve(l,r) << endl;
        }
        // cout << solve(13545,32657) << endl;
    }

    system("pause");

    return 0;
}