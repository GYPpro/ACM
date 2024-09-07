// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}

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
        return ansl + ansr;
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

    void update(int idx, int tar)
    { // 修改单点，未测试
        int tmp = getsum(idx, idx);
        tar -= tmp;
        subUpdate(idx, idx, tar, 1, n, 1);
    }
};

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> sarr(n + 1);
    vector<pii> arr(n + 1);
    // for(auto &x:arr) cin >> x;
    lop(i, 1, n + 1) cin >> sarr[i];
    // arr = sarr;
    lop(i, 1, n + 1) arr[i] = {sarr[i], i};
    lop(i, 1, n + 1) arr[i].fi += min(i, n - i + 1);
    // arr[0] = {INF,0};
    sort(all(arr));
    // lop(i,0,n) cout << arr[i].fi << " ";cout << "\n";
    vector<int> prfx(n + 1);
    lop(i, 0, n) prfx[i + 1] = prfx[i] + arr[i + 1].fi;
    int cnt = 0;
    lazyTree st(n + 1);
    st.build(prfx);
    // lop(i,1,n+1) st.insert(prfx[i]);
    // for(auto x:prfx) cout << x << " ";cout << "\n";
    lop(i, 1, n + 1)
    {
        if ( (arr[i].fi - min(arr[i].se, n - arr[i].se + 1) + arr[i].se) > c)
            continue;
        st.update(i, n + 1, -(arr[i].fi));
        // lop(i,1,n+1) cout << st.getsum(i,i) << " ";cout << "\n";
        // cout <<  c-(arr[i].fi-min(arr[i].se,n-arr[i].se+1)+arr[i].se)  << "-";
        auto check = [&](int _t) -> bool
        {
            if (_t > n)
                return 0;
            if (_t == 0)
                return 1;
            // cout << "_t:" << _t << " sum:" << st.getsum(1,_t) << "\n";
            if (st.getsum(_t, _t) <= c - (arr[i].fi - min(arr[i].se, n - arr[i].se + 1) + arr[i].se))
                return 1;
            else
                return 0;
        };

        int l = 0, r = 1e7 + 1; // 因为是左闭右开的，所以 10^9 要加 1
        while (l + 1 < r)
        {                          // 如果两点不相邻
            int mid = (l + r) / 2; // 取中间值
            if (check(mid))        // 如果可行
                l = mid;           // 升高锯片高度
            else
                r = mid; // 否则降低锯片高度
        }
        while (check(l + 1))
            l++;
        // cout << l << "\n";
        cnt = max(cnt, l + 1 - (l >= i));
        st.update(i, n + 1, (arr[i].fi));
        // int rt = (int)st.order_of_key(c - arr[i] - i)+1;
        // if(st.lower_bound(arr[i]))
        // cnt = max(cnt,rt);
    }
    cout << cnt << "\n";

    // arr = sarr;
    // lop(i,1,n+1) arr[i] += i;
    // // lop(i,1,n+1) cout << arr[i] << " ";cout << "\n";
    // int minn = INF,mini = 0;
    // int cnt1 = 0,sum1 = 0;
    // lop(i,1,n/2+1) {
    //     if(arr[i] < minn) {
    //         sum1 = arr[i],mini = i,minn = arr[i];
    //     }
    // }
    // // if(sum > c){cout << 0 << "\n";return;}
    // arr[mini] = INF;
    // lop(i,1,n+1) arr[i] -= i;

    // arr = sarr;
    // lop(i,1,n+1) arr[i] += i;
    // // lop(i,1,n+1) cout << arr[i] << " ";cout << "\n";
    // int minn = INF,mini = 0;
    // int cnt2 = 0,sum2 = 0;
    // lop(i,1,n+1) {
    //     if(arr[i]+max(0LL,n-i+1-i) < minn) {
    //         sum2 = arr[i],mini = i,minn = arr[i]+max(0LL,n-i+1-i);
    //     }
    // }
    // // if(sum > c){cout << 0 << "\n";return;}
    // arr[mini] = INF;
    // lop(i,1,n+1) arr[i] -= i;
    // lop(i,1,n+1) arr[i] += min(i,n-i+1);
    // // lop(i,1,n+1) cout << arr[i] << " ";cout << "\n";
    // sort(all(arr));
    // lop(i,0,n)
    // {
    //     sum2 += arr[i];
    //     if(sum2 > c) break;
    //     cnt2 ++;
    // }
    // cout << max(0,cnt2) << "\n";
    // cout << cnt2 << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
