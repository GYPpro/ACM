#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// #define map unordered_map
// #define set unordered_set

#include <queue>
#include <map>
#include <set>
#include <unordered_set>
// #include <queue>
#include <stack>
#include <math.h>

#pragma GCC optimize(2)

using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define lop(i, a, b) for (int i = a; i < b; i++)
#define rlop(i, a, b) for (int i = a; i >= b; i--)
#define all(x) x.begin(), x.end()

//min
class lazyTree_MIN
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
    vector<int> d;
    vector<int> a;
    vector<int> b;
    int n;
    const int INI = 1e9; // 不会影响合并运算的初始值，如min取INF，min取0，mti取1

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
        d[p] = min(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

    int subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2] = min(d[p*2],b[p]);
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2+1] = min(d[p*2+1],b[p]);
            // b[p * 2] += b[p];               // 下传标记，无需修改
            b[p*2] = min(b[p*2],b[p]);
            // b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p*2+1] = min(b[p*2+1],b[p]);
            b[p] = INI;
        }
        int ansl = INI;
        int ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return min(ansl , ansr);
        // 合并运算符↑
    }

    void subUpdate(int l, int r, int c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            // d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            d[p] = min(d[p],c);
            // b[p] += c;               // 记录懒惰标记，无需修改
            b[p] = min(b[p],c);
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] != 0 && s != t)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2] = min(d[p*2],b[p]);
            d[p*2+1] = min(d[p*2+1],b[p]);
            // b[p * 2] += b[p];               // 下传标记，无需修改
            b[p*2] = min(b[p*2],b[p]);
            // b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p*2+1] = min(b[p*2+1],b[p]);
            b[p] = INI;
        }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = min(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

public:
    lazyTree_MIN(int _n)
    {
        n = _n;
        d.resize(4 * n + 5);
        for(auto &x:d) x = 1e9;
        // a.resize(4 * n + 5);
        for(auto &x:a) x = 1e9;
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

//max
class lazyTree_MAX{
    /*
     *  TYPE_NAME需要支持：+ += != 和自定义的合并运算符
     *  实现了懒惰标记，仅支持区间批量增加
     *  区间批量减需要TYPE_NAME支持-，且有-a = 0 - a
     *  额外处理了一个单点修改为对应值的函数，非原生实现，其复杂度为 4logn
     *  不提供在线
     *  不提供持久化
     */
private:
    vector<int> d;
    vector<int> a;
    vector<int> b;
    int n;
    const int INI = 0; // 不会影响合并运算的初始值，如min取INF，min取0，mti取1

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
        d[p] = max(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

    int subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2] = max(d[p*2],b[p]);
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2+1] = max(d[p*2+1],b[p]);
            // b[p * 2] += b[p];               // 下传标记，无需修改
            b[p*2] = max(b[p*2],b[p]);
            // b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p*2+1] = max(b[p*2+1],b[p]);
            b[p] = 0;
        }
        int ansl = INI;
        int ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        return max(ansl , ansr);
        // 合并运算符↑
    }

    void subUpdate(int l, int r, int c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            // d[p] += (t - s + 1) * c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            d[p] = max(d[p],c);
            // b[p] += c;               // 记录懒惰标记，无需修改
            b[p] = max(b[p],c);
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] != 0 && s != t)
        {
            // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            // d[p * 2 + 1] += b[p] * (t - m); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p*2] = max(d[p*2],b[p]);
            d[p*2+1] = max(d[p*2+1],b[p]);
            // b[p * 2] += b[p];               // 下传标记，无需修改
            b[p*2] = max(b[p*2],b[p]);
            // b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            b[p*2+1] = max(b[p*2+1],b[p]);
            b[p] = 0;
        }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = max(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

public:
    lazyTree_MAX(int _n)
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


signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    lazyTree_MAX sgMax(3001);
    vector<int> MaxInit(3002,0);
    sgMax.build(MaxInit);
    lazyTree_MIN sgMin(3001);
    vector<int> MinInit(3002,1e9);
    sgMin.build(MinInit);

    for(int i = 0;i < 10;i ++) cout << sgMax.getsum(i,i+1) << " " << sgMin.getsum(i,i+1) << "\n";
    cout << "---\n";
    int n,m;
    cin >> n >> m;
    lop(i,0,n)
    {
        int l,r;
        cin >> l >> r;
        int val;
        cin >> val;
        sgMax.update(l,r+1,val);
        sgMin.update(l,r+1,val);
    }

    for(int i = 0;i < 10;i ++) cout << sgMax.getsum(i,i+1) << " " << sgMin.getsum(i,i+1) << "\n";

    lop(i,0,m)
    {
        int op = 0;
        cin >> op;
        if(op == 1)
        {
            int l,r,val;
            cin >> l >> r >> val;
            sgMax.update(l,r+1,val);
            sgMin.update(l,r+1,val);
        } else {
            int l,r;
            cin >> l >> r;
            cout << sgMax.getsum(l,r+1) - sgMin.getsum(l,r+1) << "\n";
        }
    }
}