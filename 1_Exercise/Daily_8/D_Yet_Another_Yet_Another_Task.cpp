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

// template <class int>
class lazyTree{
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
    const int INI = -35; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

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
        d[p] =max( d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

    int subGetSum(int l, int r, int s, int t, int p)
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
        d[p] = max(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
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


bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        lop(i,1,n+1) cin >> arr[i];

        vector<int> dp(n+1);
        int ttlmxans = 0;
        int maxn = -30,minn = 30;
        for(auto x:arr) maxn = max(maxn,x),minn = min(minn,x);
        lop(i,minn,maxn+1)
        {
            for(auto &x:dp) x = 0;
            // dp[0] = arr[0];
            lop(j,1,arr.size()){
                dp[j] = max(dp[j-1]+(arr[j]>i?-INF:arr[j]),arr[j]>i?-INF:arr[j]);
                ttlmxans = max(ttlmxans,dp[j]-i);
            }
            // cout << i << " : ";
            // for(auto x:dp) cout << x << " ";cout << "\n";

        }
        cout << ttlmxans << "\n";

        // lazyTree<int> seg(n);
        // seg.build(arr);
        // vector<pii> dp(n+1);
        // vector<pii> mxlst;
        // vector<int> prefix(n+1);
        // lop(i,1,n+1) prefix[i] = prefix[i-1] + arr[i];
        // dp[1] = {arr[1],1};
        // for(int i = 2;i <= n;i ++)
        // {
        //     // dp[i] = {max(dp[i-1]),dp[i-1].se + 1};
        //     if(dp[i-1].fi + arr[i] > arr[i])
        //     {
        //         dp[i] = {dp[i-1].fi + arr[i],dp[i-1].se};
        //     } else {
        //         dp[i] = {arr[i],i};
        //     }
        //     mxlst.pb({dp[i].se,i});
        // }
        // // for(auto x:dp) cout << x.fi << " " << x.se << "\n";
        // // for(auto x:mxlst) cout << x.fi << " " << x.se << "\n";
        // int maxans = 0;
        // for(auto x:mxlst)
        // {
        //     // cout << x.fi << " " << x.se << " " << prefix[x.se] << " " << prefix[x.fi] << " " << seg.getsum(x.fi,x.se) << "\n";
        //     maxans = max(maxans,prefix[x.se]-prefix[x.fi-1]-seg.getsum(x.fi,x.se));
        // }
        // cout << maxans << "\n";
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