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

ll int binpow(ll int a, ll int b, ll int m)
{
    ll int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

using namespace std;
template <class TYPE_NAME>
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
private:
    vector<TYPE_NAME> d;
    vector<TYPE_NAME> a;
    vector<TYPE_NAME> b;
    vector<TYPE_NAME> ba;
    int n;
    TYPE_NAME mod;
    const TYPE_NAME INI = 0; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = a[s];
            return;
        }
        int m = s + ((t - s) >> 1); //  (s+t)/2
        subbuild(s, m, p * 2);
        subbuild(m + 1, t, p * 2 + 1);
        d[p] = (d[p * 2] + d[p * 2 + 1]) % mod;
        //    合并运算符 ↑
    }

    TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p] % mod;
        int m = s + ((t - s) >> 1);
        if (ba[p] != 1)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2] *= ba[p] % mod;
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] *= ba[p] % mod;
            ba[p * 2] *= ba[p] % mod; // 下传标记，无需修改
            // b[p * 2] *= ba[p] % mod;
            ba[p * 2 + 1] *= ba[p] % mod; // 下传标记，无需修改
            // b[p * 2 + 1] *= ba[p] % mod;
            ba[p] = 1;
            d[p * 2] %= mod;
            d[p * 2 + 1]  %= mod;
            ba[p * 2]  %= mod;
            b[p * 2]  %= mod;
            ba[p * 2 + 1]  %= mod;
            b[p * 2 + 1]  %= mod;
        }
        if (b[p] != 0)
        {
            d[p * 2] += b[p] * (m - s + 1) % mod; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m) % mod; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p] % mod;               // 下传标记，无需修改
            b[p * 2 + 1] += b[p] % mod;           // 下传标记，无需修改
            b[p] = 0;
            d[p * 2] %= mod;
            d[p * 2 + 1]  %= mod;
            ba[p * 2]  %= mod;
            b[p * 2]  %= mod;
            ba[p * 2 + 1]  %= mod;
            b[p * 2 + 1]  %= mod;
        }
        TYPE_NAME ansl = INI;
        TYPE_NAME ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return (ansl + ansr) % mod;
        // 合并运算符↑
    }

    void subUpdateAD(int l, int r, TYPE_NAME c, int s, int t, int p)
    {

        int m = s + ((t - s) >> 1);
        if (ba[p] != 1 && s != t)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2] *= ba[p] % mod;
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] *= ba[p] % mod;

            ba[p * 2] *= ba[p] % mod; // 下传标记，无需修改
            b[p * 2] *= ba[p] % mod;
            ba[p * 2 + 1] *= ba[p] % mod; // 下传标记，无需修改
            b[p * 2 + 1] *= ba[p] % mod;
            ba[p] = 1;
            d[p * 2] %= mod;
            d[p * 2 + 1]  %= mod;
            ba[p * 2]  %= mod;
            b[p * 2]  %= mod;
            ba[p * 2 + 1]  %= mod;
            b[p * 2 + 1]  %= mod;
        }        
        if (l <= s && t <= r)
        {
            d[p] += (t - s + 1) * c % mod; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            b[p] += c % mod;               // 记录懒惰标记，无需修改]
            return;
        }
        if (b[p] != 0 && s != t)
        {
            d[p * 2] += b[p] * (m - s + 1) % mod; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m) % mod; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p] % mod;               // 下传标记，无需修改
            b[p * 2 + 1] += b[p] % mod;           // 下传标记，无需修改
            b[p] = 0;
            d[p * 2] %= mod;
            d[p * 2 + 1]  %= mod;
            ba[p * 2]  %= mod;
            b[p * 2]  %= mod;
            ba[p * 2 + 1]  %= mod;
            b[p * 2 + 1]  %= mod;
        }
        if (l <= m)
            subUpdateAD(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdateAD(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = (d[p * 2] + d[p * 2 + 1]) % mod;
        //    合并运算符 ↑
    }

    void subUpdateMT(int l, int r, TYPE_NAME c, int s, int t, int p)
    {
        int m = s + ((t - s) >> 1);
        if (l <= s && t <= r)
        {
            // d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            d[p] *= c;
            // b[p] += c;               // 记录懒惰标记，无需修改]
            ba[p] *= c;
            b[p] *= c;
            d[p] %= mod;
            ba[p] %= mod;
            b[p] %= mod;
            return;
        }
        if (ba[p] != 1 && s != t)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2] *= ba[p] ;
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] *= ba[p];

            ba[p * 2] *= ba[p] ; // 下传标记，无需修改
            b[p * 2] *= ba[p];
            ba[p * 2 + 1] *= ba[p]; // 下传标记，无需修改
            b[p * 2 + 1] *= ba[p];
            d[p * 2] %= mod;
            d[p * 2 + 1]  %= mod;
            ba[p * 2]  %= mod;
            b[p * 2]  %= mod;
            ba[p * 2 + 1]  %= mod;
            b[p * 2 + 1]  %= mod;
            ba[p] = 1;
        }
        if (l <= m)
            subUpdateMT(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdateMT(l, r, c, m + 1, t, p * 2 + 1);                                                                   
        d[p] = (d[p * 2] + d[p * 2 + 1]) % mod;
        //    合并运算符 ↑
    }

public:
    lazyTree(int _n, TYPE_NAME _m)
    {
        n = _n;
        mod = _m;
        d.resize(4 * n + 5);
        a.resize(4 * n + 5);
        b.resize(4 * n + 5);
        ba.resize(4 * n + 5);
        for (int i = 0; i < ba.size(); i++)
            ba[i] = 1;
    }

    void build(vector<TYPE_NAME> _a)
    {
        a = _a;
        subbuild(1, n, 1);
    }

    TYPE_NAME getsum(int l, int r)
    {
        return subGetSum(l, r, 1, n, 1);
    }

    void updateAD(int l, int r, TYPE_NAME c) // 修改区间
    {
        subUpdateAD(l, r, c, 1, n, 1);
    }

    void updateMT(int l, int r, TYPE_NAME c) // 修改区间
    {
        subUpdateMT(l, r, c, 1, n, 1);
    }

    void update(int idx, TYPE_NAME tar)
    { // 修改单点
        TYPE_NAME tmp = getsum(idx, idx);
        tar -= tmp;
        subUpdate(idx, idx, tar, 1, n, 1);
    }
};

void solve()
{
    int n, m, mod;
    cin >> n >> m >> mod;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    lazyTree<ll> lz(n, mod);
    lz.build(arr);
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            lz.updateMT(x, y, k %mod);
        }
        else if (op == 2)
        {
            int x, y, k;
            cin >> x >> y >> k;
            lz.updateAD(x, y, k %mod);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << lz.getsum(x, y) % mod << "\n";
        }
    }
}

// #define _WITH_T_

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

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}