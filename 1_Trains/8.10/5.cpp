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

struct sq
{
    int l;
    int r;
    int s;
};

bool A[maxn];

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            A[i] = 1;
        else
            A[i] = 0;
    }
    vector<sq> s1;
    vector<sq> s0;

    if (A[0] && A[n - 1])
    {
        cout << 1 << endl;
        return;
    }

    bool fs1 = 0;
    bool fs0 = 0;

    int sum0 = 0;
    int sum1 = 0;

    sq tmp1;
    sq tmp0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            sum0++;
            if (fs0)
            {
                tmp0.r = i;
                tmp0.s++;
            }
            else
            {
                tmp0.l = i;
                tmp0.r = i;
                tmp0.s = 1;
                fs0 = 1;
            }
            if (fs1)
            {
                s1.push_back(tmp1);
                fs1 = 0;
            }
        }
        else
        {
            sum1++;
            if (fs1)
            {
                tmp1.r = i;
                tmp1.s++;
            }
            else
            {
                tmp1.l = i;
                tmp1.r = i;
                tmp1.s = 1;
                fs1 = 1;
            }
            if (fs0)
            {
                s0.push_back(tmp0);
                fs0 = 0;
            }
        }
    }
    if (A[n - 1] == 0)
        s0.push_back(tmp0);
    if (A[n - 1] == 1)
        s1.push_back(tmp1);

    int l = 0, r = n - 1;
    for (int i = 0;; i++)
    {
        if ((A[l] == i % 2) && (A[r] != i % 2))
            l++;
        else if ((A[l] != i % 2) && (A[r] == i % 2))
            r--;
        else
            break;
    }
    if (l == r)
    {
        if (sum0 > sum1 + 1)
        {
            cout << 0 << endl;
            return;
        }
        if (sum0 < sum1)
        {
            cout << 1 << endl;
            return;
        }

        cout << -1 << endl;
        return;
    }

    int cl1l = n, cl1r = 0, cl0l = n, cl0r = 0;
    int ct1 = 0, ct0 = 0;
    int ml1 = 0, ml0 = 0;

    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i].r <= l || s1[i].l >= r)
            continue;
        if (s1[i].s <= 1)
            continue;
        ct1++;
        if (s1[i].l < cl1l)
            cl1l = s1[i].l;
        if (s1[i].r > cl1r)
            cl1r = s1[i].r;
        if (s1[i].s > ml1)
            ml1 = s1[i].s;
    }
    for (int i = 0; i < s0.size(); i++)
    {
        if(s0[i].r <= l || s0[i].l >= r)
            continue;
        if (s0[i].s <= 1)
            continue;
        ct0++;
        if (s0[i].l < cl0l)
            cl0l = s0[i].l;
        if (s0[i].r > cl0r)
            cl0r = s0[i].r;
        if (s0[i].s > ml0)
            ml0 = s0[i].s;
    }

    if (A[l] == 0)
    {
        if (((cl1l > cl0l) || (cl1r < cl0r)) && (ct0 > 0))
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            if ((ct0 == 0) && (ct1 <= 1) && (ml1 < 3))
            {
                if (sum0 > sum1 + 1)
                {
                    cout << 0 << endl;
                    return;
                }
                if (sum0 < sum1)
                {
                    cout << 1 << endl;
                    return;
                }

                cout << -1 << endl;
                return;
            }
            else
            {
                cout << 1 << endl;
                return;
            }
        }
    }
    else
    {
        if (((cl0l > cl1l) || (cl0r < cl1r)) && (ct1 > 0))
        {
            cout << 1 << endl;
            return;
        }
        else
        {
            if ((ct1 == 0) && (ct0 <= 1) && (ml0 < 3))
            {
                if (sum0 > sum1 + 1)
                {
                    cout << 0 << endl;
                    return;
                }
                if (sum0 < sum1)
                {
                    cout << 1 << endl;
                    return;
                }

                cout << -1 << endl;
                return;
            }
            else
            {
                cout << 0 << endl;
                return;
            }
        }
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