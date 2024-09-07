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
#pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

template <class int>
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
    vector<int> d;
    vector<int> a;
    vector<int> b;
    int n;
    const int INI = 0; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

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
        d[p] = d[p * 2] + d[p * 2 + 1];
        //    合并运算符 ↑
    }

    int subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        // cout << "1";
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            // if(b[p] % 2 == 1){
                // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2] = (m - s + 1) - d[p*2]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] = (t - m) - d[p*2+1]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] ^= b[p];               // 下传标记，无需修改
            b[p * 2 + 1] ^= b[p];           // 下传标记，无需修改
            b[p] = 0;
            // } else {
            //     b[p * 2] += b[p];               // 下传标记，无需修改
            //     b[p * 2 + 1] += b[p];           // 下传标记，无需修改
            //     b[p] = 0;
            // }
        }
        int ansl = INI;
        int ansr = INI;
        if (l <= m)
            ansl = subGetSum(l, r, s, m, p * 2);
        if (r > m)
            ansr = subGetSum(l, r, m + 1, t, p * 2 + 1);
        #ifdef D
        // cout << "subgetsum rt->" << l << " " << r << " " << s << " " << t << " " << p << " sl:" << ansl << " sr:" << ansr << "\n";
        #endif
        // d[p] = d[p * 2] + d[p * 2 + 1];
        return ansl + ansr;
        // 合并运算符↑
    }

    void subUpdate(int l, int r, int c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            b[p] ^= c;               // 记录懒惰标记，无需修改
            // if(b[p]%2 == 1)
            #ifdef D
            cout << "update ALL*** :" << l << " " << r << " " << c << "\n";
            #endif
            d[p] = (t - s + 1)-d[p]; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            // if(b[p] % 2 == 1){
                // d[p * 2] += b[p] * (m - s + 1); // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2] = (m - s + 1) - d[p*2]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] = (t - m) - d[p*2+1]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            b[p * 2] ^= b[p];               // 下传标记，无需修改
            b[p * 2 + 1] ^= b[p];           // 下传标记，无需修改
            b[p] = 0;
            // }
        }
        if (l <= m)
            subUpdate(l, r, c, s, m, p * 2);
        if (r > m)
            subUpdate(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
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

    // void update(int idx, TYPE_NAME tar)
    // { // 修改单点，未测试
    //     TYPE_NAME tmp = getsum(idx, idx);
    //     tar -= tmp;
    //     subUpdate(idx, idx, tar, 1, n, 1);
    // }
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
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        vector<vector<int>> bits(21,vector<int>(n+1,0));
        for(int i = 0;i < 21;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                bits[i][j] = (arr[j-1] >> i) & 1;
            }
        }
        vector<lazyTree<int>> segs(21,lazyTree<int>(n));
        for(int i = 0;i < 21;i++)
        {
            #ifdef D
            for(auto x:bits[i]) cout << x << " ";cout << "\n";
            #endif
            segs[i].build(bits[i]);
        }
        int m;
        cin >> m;
        while(m--)
        {
            int op;cin >> op;
            if(op == 1)
            {
                int l,r;
                cin >> l >> r;
                int ans = 0;
                for(int i = 0;i < 21;i++)
                {
                    int cnt = segs[i].getsum(l,r);
                    #ifdef D
                    cout << "getsum:" << i << " " << l << " " << r << ":" << cnt << "\n";
                    #endif
                    ans += cnt * (1 << i);
                }
                cout << ans << "\n";
            } else {
                int l,r,c;
                cin >> l >> r >> c;
                for(int i = 0;i < 21;i ++)
                {
                    if((c >> i) & 1)
                    {
                        #ifdef D
                        // lop(j,1,n+1) cout << segs[i].getsum(j,j) << " ";
                        // cout << "\n ^ update v :" << i << " " << l << " " << r << " " << 1 << "\n";
                        #endif
                        segs[i].update(l,r,1);
                        #ifdef D
                        // lop(j,1,n+1) cout << segs[i].getsum(j,j) << " ";cout << "\n";
                        // cout << segs[i].getsum(1,5) << "\n";
                        #endif
                    }
                }
            }
            #ifdef D
            // for(int i = 0;i < n;i ++)
            // {
            //     int ans = 0;
            //     for(int j = 0;j < 21;j++)
            //     {
            //         cout << segs[j].getsum(i+1,i+1);
            //         ans += (segs[j].getsum(i+1,i+1) << j);
            //     }
            //     cout << " " << ans << "\n";
                
            // } cout << "\n";

            #endif
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