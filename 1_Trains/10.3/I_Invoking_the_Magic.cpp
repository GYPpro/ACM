// #define _USE_IOSTREAM_
// #define _PRIV_TEST_
#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifndef _PRIV_TEST_
#pragma GCC optimize(3)
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
#include <unordered_map>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

// class mypair{
// public:
//     int a,b;
// public:
//     mypair(){
//         a = 0;
//         b = 0;
//     }
//     mypair(int _a,int _b)
//     {
//         a = _a;
//         b = _b;
//     }
//     bool operator>(mypair _b)
//     {
//         if(_b.a != a) return _b.a > a;
//         else return _b.b > b;
//     } 
//     bool operator<(mypair _b)
//     {
//         if(_b.a != a) return _b.a < a;
//         else return _b.b < b;
//     } 
// };

int find(int a,unordered_map<int,int> &pa,unordered_map<int,int> &ttl)
{
    int tpa = pa[a];
    if(tpa == a) return a;
    else return pa[a] = find(tpa,pa,ttl);
}

// void con(int a,int b,map<int,int> &pa,map<int,int>  &ttl)
// {
//     // int pta = find(a,pa,ttl),ptb =
//     if(pa[find(a,pa,ttl)] != find(b,pa,ttl))ttl[find(b,pa,ttl)] += ttl[find(a,pa,ttl)];
//     pa[find(a,pa,ttl)] = find(b,pa,ttl);
// }

void con(int a,int b,unordered_map<int,int> &pa,unordered_map<int,int> &ttl)
{
    int pta = find(a,pa,ttl),ptb = find(b,pa,ttl);
    if(pa[pta] != ptb)ttl[ptb] += ttl[pta];
    pa[pta] = ptb;
}

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
  putchar('\n');
}

void solve()
{
    // int pair = 0;
    // int maxN = 0;
    // int pvMx = 0;
    // int n;
    // cin >> n;
    // map<int, int> farr;
    // vector<mypair> arr;
    // for(int i = 0;i < n;i ++)
    // {
    //     int a,b;
    //     cin >> a >> b;
    //     arr.push_back(mypair(a,b));
    // }
    // sort(arr.begin(),arr.end());
    // for (int i = 0; i < n; i++)
    // {
    //     pvMx++;
    //     int a, b;
    //     a = arr[i].a;
    //     b = arr[i].b;
    //     if (farr.find(a) != farr.end())
    //         farr[a]++;
    //     else
    //         farr[a] = 1;
    //     if (farr.find(b) != farr.end())
    //         farr[b]++;
    //     else
    //         farr[b] = 1;
    //     if (farr[a] == 2)
    //     {
    //         pair--;
    //         farr[a] = 0;
    //     }
    //     else
    //         pair++;
    //     if (farr[b] == 2)
    //     {
    //         pair--;
    //         farr[b] = 0;
    //     }
    //     else
    //         pair++;
    //     if (pair == 0)
    //     {
    //         maxN = max(pvMx, maxN);
    //         pvMx = 0;
    //     }
    // }
    // cout << maxN << endl;

    int n;
    // cin >> n;
    n = read();
    unordered_map<int,int> pa;
    unordered_map<int,int> ttl;
    for(int i = 0;i < n;i ++)
    {
        int a,b;
        // cin >> a >> b;
        // scanf("%d %d",&a,&b);
        a = read();
        b = read();
        if(pa.find(a) == pa.end()) pa[a] = a;
        if(pa.find(b) == pa.end()) pa[b] = b;
        if(ttl.find(a) == ttl.end()) ttl[a] = 1;
        if(ttl.find(b) == ttl.end()) ttl[b] = 1;
        con(a,b,pa,ttl);
        // cout << pa[a] << " " << ttl[a] << " " << ttl[b] << endl;
    }
    int mxn = 0;
    for(auto x = ttl.begin();x!= ttl.end();x ++)
    {
        mxn = max(mxn,(*x).second); 
    }
    // cout << mxn/2 << endl;
    // printf("%d\n",mxn);
    write(mxn);
}

#define _WITH_T_

int main()
{
#ifndef _PRIV_TEST_
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    // scanf("%d", &T);
    T = read();
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}