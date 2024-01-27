// #define _USE_IOSTREAM_
#define _PRIV_TEST_
#pragma GCC optimize(3)
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
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define int int
#define mod1 998244353

using namespace std;
// #define _WITH_T_
// #define DEBUG 1  // 调试开关
struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}

    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    char gc()
    {
#if DEBUG // 调试，可显示字符
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template <class T>
    void read(T &x)
    {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }

    void read(char *s)
    {
        char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }

    void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }

    void push(const char &c)
    {
#if DEBUG // 调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }

    template <class T>
    void write(T x)
    {
        if (x < 0)
            x = -x, push('-'); // 负数输出
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }

    template <class T>
    void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;
// int getdp(const vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> dp(n);
//     dp[0] = arr[0];
//     int cnt = (arr[0] == -1);
//     int maxa = dp[0];
//     for(int i = 1;i < n;i ++){
//         maxa = max(dp[i] = max(dp[i-1]+arr[i],arr[i]),maxa);
//         cnt += (arr[i] == -1);
//         }
//     return maxa + cnt;
// }

void solve()
{
    int n, k;
    // cin >> n >> k;
    io.read<int>(n);
    io.read<int>(k);
    vector<int> arr(n);
    for (int &x : arr)
        io.read<int>(x);
    unordered_map<int, vector<short>> cnt;
    unordered_set<int> comp;
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]].push_back(1);
        if (k != 0)
            cnt[arr[i] - k].push_back(-1);
        comp.insert(arr[i]);
    }
    int maxa = -INT_MAX;
    for (auto x = cnt.begin(); x != cnt.end(); x++)
        if (comp.find((*x).first) != comp.end())
        {
            (*x).second;
            int pv = (*x).second[0];
            int mt = (*x).second[0];
            int cnt = ((*x).second[0] == -1);
            for (int i = 1; i < (*x).second.size(); i++)
            {
                mt = max(pv = max(pv + (*x).second[i], (int)(*x).second[i]), mt);
                cnt += ((*x).second[i] == -1);
            }
            maxa = max(mt + cnt, maxa);
        }
    // cout << maxa << "\n";
    io.write<int>(maxa);
}

signed main()
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

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}