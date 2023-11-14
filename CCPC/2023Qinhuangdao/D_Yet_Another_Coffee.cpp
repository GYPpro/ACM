#define _USE_IOSTREAM_
// #define _PRIV_TEST_

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

#define ll long long
#define mod1 998244353

using namespace std;

class lazyTree
{
    /*
     *  TYPE_NAME需要支持：+ += != 和自定义的合并运算符
     *  实现了懒惰标记，仅支持区间批量增加
     *  区间批量减需要TYPE_NAME支持-，且有-a = 0 - a
     *  额外处理了一个单点修改为对应值的函数，非原生实现，其复杂度为 4logn
     *  不提供在线
     *  不提供持久化
     */
public:
    vector<int> d;
    vector<int> a;
    vector<int> b;
    int n;
    const int INI = 0; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = s;
            return;
        }
        int m = s + ((t - s) >> 1); //  (s+t)/2
        subbuild(s, m, p * 2);
        subbuild(m + 1, t, p * 2 + 1);
        // d[p] = min(d[p * 2] , d[p * 2 + 1]);
        if(a[d[p*2]] <= a[d[p*2+1]]) d[p] = d[p*2];
        else d[p] = d[p*2+1]; 
        //    合并运算符 ↑
    }

    int subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            d[p * 2] += b[p]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] ; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        int ansl = INI;
        int ansr = INI;
        if (l <= m)
            return ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            return ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        // 合并运算符↑
        return 0;
    }

    public:void subUpdate(int l, int r, int c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            d[p] +=c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            b[p] += c;               // 记录懒惰标记，无需修改
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] != 0 && s != t)
        {
            d[p * 2] += b[p]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        if(a[d[p*2]] <= a[d[p*2+1]]) d[p] = d[p*2];
        else d[p] = d[p*2+1]; 
        //    合并运算符 ↑
    }

    void updatest(int f,int c,int s,int t,int p)
    {
        if(t == s) {
            a[f] += c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if (f <= m)
            updatest(f, c, s, m, p * 2);
        if (t > m)
            updatest(f,c, m + 1, t, p * 2 + 1);
        if(a[d[p*2]] <= a[d[p*2+1]]) d[p] = d[p*2];
        else d[p] = d[p*2+1]; 
    }
public:
    lazyTree(int _n)
    {
        n = _n;
        d.resize(4 * n + 5);
        a.resize(4 * n + 5);
        b.resize(4 * n + 5);
    }

    void build(vector<int> _a)
    {
        a = _a;
        subbuild(1, n, 1);
    }

    int getsum(int l, int r)
    {
        return subGetSum(l, r, 1, n, 1);
    }

    void update(int l, int r, int c) // 修改区间
    {
        subUpdate(l, r, c, 1, n, 1);
    }

    void update(int idx, int tar)
    { // 修改单点，未测试
        int tmp = getsum(idx, idx);
        tar -= tmp;
        subUpdate(idx, idx, tar, 1, n, 1);
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr(n+1);
    for(int i = 0;i < n;i ++) cin >> arr[i+1];
    lazyTree lz = lazyTree(n);
    lz.build(arr);
    vector<pair<int,int>> opt;
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        opt.push_back(pair<int,int>(a,b));
    }
    sort(opt.begin(),opt.end());
    for(int i = 0;i < opt.size();i ++)
    {
        int it = lz.getsum(1,opt[i].first);
        lz.updatest(it,-opt[i].second,1,n,1);
    }
    arr = lz.a;
    sort(arr.begin(),arr.end());
    int t = 0;
    for(int i = 0;i < n;i ++) cout << (t += arr[i]) << " ";
    cout << "\n";
}

#define _WITH_T_

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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}