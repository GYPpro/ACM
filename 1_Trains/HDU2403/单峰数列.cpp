// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

// AC 带懒惰标记线段树 
// template <class TYPE_NAME>
// class lazyTree
// {
//     /*
//      *  TYPE_NAME需要支持：+ += != 和自定义的合并运算符
//      *  实现了懒惰标记，仅支持区间批量增加
//      *  区间批量减需要TYPE_NAME支持-，且有-a = 0 - a
//      *  额外处理了一个单点修改为对应值的函数，非原生实现，其复杂度为 4logn
//      *  不提供在线
//      *  不提供持久化
//      */
// public:
//     vector<TYPE_NAME> d;
//     vector<TYPE_NAME> a;
//     vector<TYPE_NAME> b;
//     int n;
//     const TYPE_NAME INI = 0; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

//     void subbuild(int s, int t, int p)
//     {
//         if (s == t)
//         {
//             d[p] = a[s];
//             return;
//         }
//         int m = s + ((t - s) >> 1); //  (s+t)/2
//         subbuild(s, m, p * 2);
//         subbuild(m + 1, t, p * 2 + 1);
//         d[p] = d[p * 2] + d[p * 2 + 1];
//         //    合并运算符 ↑
//     }

//     TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
//     {
//         if (l <= s && t <= r)
//             return d[p];
//         int m = s + ((t - s) >> 1);
//         if (b[p] != 0)
//         {
//             d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
//             d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
//             b[p * 2] += b[p];               // 下传标记，无需修改
//             b[p * 2 + 1] += b[p];           // 下传标记，无需修改
//             b[p] = 0;
//         }
//         TYPE_NAME ansl = INI;
//         TYPE_NAME ansr = INI;
//         if (l <= m)
//             ansl = subGetSum(l, r, s, m, p * 2);
//         if (r > m)
//             ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
//         return ansl + ansr;
//         // 合并运算符↑
//     }

//     void subUpdate(int l, int r, TYPE_NAME c, int s, int t, int p)
//     {
//         if (l <= s && t <= r)
//         {
//             d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
//             b[p] += c;               // 记录懒惰标记，无需修改
//             return;
//         }
//         int m = s + ((t - s) >> 1);
//         if (b[p] != 0 && s != t)
//         {
//             d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
//             d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
//             b[p * 2] += b[p];               // 下传标记，无需修改
//             b[p * 2 + 1] += b[p];           // 下传标记，无需修改
//             b[p] = 0;
//         }
//         if (l <= m)
//             subUpdate(l, r, c, s, m, p * 2);
//         if (r > m)
//             subUpdate(l, r, c, m + 1, t, p * 2 + 1);
//         d[p] = d[p * 2] + d[p * 2 + 1];
//         //    合并运算符 ↑
//     }

// public:
//     lazyTree(TYPE_NAME _n)
//     {
//         n = _n;
//         d.resize(4 * n + 5);
//         a.resize(4 * n + 5);
//         b.resize(4 * n + 5);
//     }

//     void build(vector<TYPE_NAME> _a)
//     {
//         a = _a;
//         subbuild(1, n, 1);
//     }

//     TYPE_NAME getsum(int l, int r)
//     {
//         return subGetSum(l, r, 1, n, 1);
//     }

//     void update(int l, int r, TYPE_NAME c) // 修改区间
//     {
//         subUpdate(l, r, c, 1, n, 1);
//     }

//     void update(int idx, TYPE_NAME tar)
//     { // 修改单点，未测试
//         TYPE_NAME tmp = getsum(idx, idx);
//         tar -= tmp;
//         subUpdate(idx, idx, tar, 1, n, 1);
//     }
// };



// AC 带懒惰标记线段树 
template <class TYPE_NAME>
class allZer
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
    vector<TYPE_NAME> d;
    vector<TYPE_NAME> a;
    vector<TYPE_NAME> b;
    int n;
    const TYPE_NAME INI = 1; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = (a[s] == 0);
            return;
        }
        int m = s + ((t - s) >> 1); //  (s+t)/2
        subbuild(s, m, p * 2);
        subbuild(m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }

    TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        TYPE_NAME ansl = INI;
        TYPE_NAME ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return ansl && ansr;
        // 合并运算符↑
    }

    void subUpdate(int l, int r, TYPE_NAME c, int s, int t, int p)
    {
        // if (l <= s && t <= r)
        // {
        //     d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
        //     b[p] += c;               // 记录懒惰标记，无需修改
        //     return;
        // }
        int m = s + ((t - s) >> 1);
        // if (b[p] != 0 && s != t)
        // {
        //     d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
        //     d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
        //     b[p * 2] += b[p];               // 下传标记，无需修改
        //     b[p * 2 + 1] += b[p];           // 下传标记，无需修改
        //     b[p] = 0;
        // }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }


    void update(int s,int t,TYPE_NAME c,int v,int p)
    {
        if(s == t)
        {
            d[p] = c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if(v <= m)
            update(s,m,c,v,p*2);
        else
            update(m+1,t,c,v,p*2+1);
        d[p] = d[p*2] && d[p*2+1];
    }

public:
    allZer(TYPE_NAME _n)
    {
        n = _n;
        d.resize(4 * n + 5);
        a.resize(4 * n + 5);
        b.resize(4 * n + 5);
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

    void update(int l, int r, TYPE_NAME c) // 修改区间
    {
        subUpdate(l, r, c, 1, n, 1);
    }

    void update(int idx, TYPE_NAME tar,vector<TYPE_NAME> &t)
    { 
        
        TYPE_NAME mvt = (t[idx] + tar == 0);
        update(1,n,mvt,idx,1);
    }
};


// AC 带懒惰标记线段树 
template <class TYPE_NAME>
class allU
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
    vector<TYPE_NAME> d;
    vector<TYPE_NAME> a;
    vector<TYPE_NAME> b;
    int n;
    const TYPE_NAME INI = 1; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = (a[s] > 0);
            return;
        }
        int m = s + ((t - s) >> 1); //  (s+t)/2
        subbuild(s, m, p * 2);
        subbuild(m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }

    TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        TYPE_NAME ansl = INI;
        TYPE_NAME ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return ansl && ansr;
        // 合并运算符↑
    }

    void update(int s,int t,TYPE_NAME c,int v,int p)
    {
        if(s == t)
        {
            d[p] = c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if(v <= m)
            update(s,m,c,v,p*2);
        else
            update(m+1,t,c,v,p*2+1);
        d[p] = d[p*2] && d[p*2+1];
    }

    void subUpdate(int l, int r, TYPE_NAME c, int s, int t, int p)
    {
        // if (l <= s && t <= r)
        // {
        //     d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
        //     b[p] += c;               // 记录懒惰标记，无需修改
        //     return;
        // }
        int m = s + ((t - s) >> 1);
        // if (b[p] != 0 && s != t)
        // {
        //     d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
        //     d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
        //     b[p * 2] += b[p];               // 下传标记，无需修改
        //     b[p * 2 + 1] += b[p];           // 下传标记，无需修改
        //     b[p] = 0;
        // }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }

public:
    allU(TYPE_NAME _n)
    {
        n = _n;
        d.resize(4 * n + 5);
        a.resize(4 * n + 5);
        b.resize(4 * n + 5);
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

    void update(int l, int r, TYPE_NAME c) // 修改区间
    {
        subUpdate(l, r, c, 1, n, 1);
    }

    void update(int idx, TYPE_NAME tar,vector<TYPE_NAME> &t)
    { // 修改单点，未测试 

        TYPE_NAME mvt = (t[idx] + tar > 0);
        // if(tmp == 1) mvt = (idx >= 0);
        // else if(tar > abs(t[idx])) mvt = 1;
        // else mvt = 0;
        // else if(t[idx] == -tar) mvt = 1;
        // else mvt = 0;
        update(1,n,mvt,idx,1);
    }
};


// AC 带懒惰标记线段树 
template <class TYPE_NAME>
class allD
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
    vector<TYPE_NAME> d;
    vector<TYPE_NAME> a;
    vector<TYPE_NAME> b;
    int n;
    const TYPE_NAME INI = 1; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = (a[s] < 0);
            return;
        }
        int m = s + ((t - s) >> 1); //  (s+t)/2
        subbuild(s, m, p * 2);
        subbuild(m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }

    TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        TYPE_NAME ansl = INI;
        TYPE_NAME ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return ansl && ansr;
        // 合并运算符↑
    }

    void subUpdate(int l, int r, TYPE_NAME c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            b[p] += c;               // 记录懒惰标记，无需修改
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] != 0 && s != t)
        {
            d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] += b[p];               // 下传标记，无需修改
            b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p] = 0;
        }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] && d[p * 2 + 1];
        //    合并运算符 ↑
    }


    void update(int s,int t,TYPE_NAME c,int v,int p)
    {
        if(s == t)
        {
            d[p] = c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if(v <= m)
            update(s,m,c,v,p*2);
        else
            update(m+1,t,c,v,p*2+1);
        d[p] = d[p*2] && d[p*2+1];
    }

public:
    allD(TYPE_NAME _n)
    {
        n = _n;
        d.resize(4 * n + 5);
        a.resize(4 * n + 5);
        b.resize(4 * n + 5);
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

    void update(int l, int r, TYPE_NAME c) // 修改区间
    {
        subUpdate(l, r, c, 1, n, 1);
    }

    void update(int idx, TYPE_NAME tar,vector<TYPE_NAME> &t)
    { // 修改单点，未测试 
    
        TYPE_NAME mvt = (t[idx] + tar < 0);
        // else if(t[idx] == -tar) mvt = 1;
        // else mvt = 0;
        update(1,n,mvt,idx,1);
    }
};


bool comp(int a,int b) {return a < b;}
class solution
{
public:


public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        lop(i,1,n+1) cin >> a[i];
        vector<int> t(n+1);
        for(int i = 1;i <= n;i++)
        {
            t[i] = a[i] - a[i-1];
        }
        allZer<int> zer(n);
        zer.build(t);
        allU<int> u(n);
        u.build(t);
        allD<int> d(n);
        d.build(t);
        int q;
        cin >> q;
        while(q--)
        {
            #ifdef D
            lop(i,1,n+1) cout << t[i] << " ";cout << "\n";
            lop(i,1,n+1) cout << zer.getsum(i,i) << " ";cout << "\n";
            lop(i,1,n+1) cout << u.getsum(i,i) << " ";cout << "\n";
            lop(i,1,n+1) cout << d.getsum(i,i) << " ";cout << "\n";
            #endif
            int opt;
            cin >> opt;
            switch (opt)
            {
            case 1:
                {
                    int l,r,x;
                    cin >> l >> r >> x;
                    zer.update(l,x,t);
                    zer.update(r+1,-x,t);
                    u.update(l,x,t);
                    u.update(r+1,-x,t);
                    d.update(l,x,t);
                    d.update(r+1,-x,t);
                    t[l] += x;
                    t[r+1] -= x;
                }
                break;
            case 2:
                {
                    int l,r;
                    cin >> l >> r;
                    if(l == r) cout << 1 << "\n";
                    else cout << zer.getsum(l+1,r) << "\n"; 
                }
                break;
            case 3:
                {
                    int l,r;
                    cin >> l >> r;
                    cout << (u.getsum(l+1,r)) << "\n";
                }
                break;
            case 4:
                {
                    int l,r;
                    cin >> l >> r;
                    cout << (d.getsum(l+1,r)) << "\n";
                }
                break;
            case 5:
                {
                    int l,r;
                    cin >> l >> r;
                    // l ++;
                    int ll = l,rr = r;
                    while(ll < rr)
                    {
                        int m = ll + ((rr - ll) >> 1)+1;
                        // cout << m << " ";
                        if(u.getsum(l+1,m) == 1) ll = m; 
                        else rr = m - 1;
                    } //找到最小的rr使得d[l,rr] == 1
                    // cout << ll << " " << rr << "\n";
                    cout << ((ll-l > 0 && r - (ll) > 0) && d.getsum(ll+1,r)) << "\n";
                }
                break;
            
            default:
                break;
            }
        }
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}