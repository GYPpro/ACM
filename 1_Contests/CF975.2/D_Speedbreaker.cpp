// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

// AC 带懒惰标记线段树 
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
    int n;
    const TYPE_NAME INI = INF; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

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

    TYPE_NAME subGetSum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p] != 0)
        {
            d[p * 2] += b[p]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
            d[p * 2 + 1] += b[p]; // 合并运算符的高阶运算 此处运算为应用懒惰标记
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
        return min(ansl , ansr);
        // 合并运算符↑
    }

    void subUpdate(int l, int r, TYPE_NAME c, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            d[p] += c; // 合并运算符的高阶运算 此处运算为修改整匹配区间值
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
        d[p] = min(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

public:
    lazyTree(TYPE_NAME _n)
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
        if(r < l) return 0;
        return subGetSum(l, r, 1, n, 1);
    }

    void update(int l, int r, TYPE_NAME c) // 修改区间
    {
        if(r < l) return;
        subUpdate(l, r, c, 1, n, 1);
    }

    void update(int idx, TYPE_NAME tar)
    { // 修改单点，未测试
        TYPE_NAME tmp = getsum(idx, idx);
        tar -= tmp;
        subUpdate(idx, idx, tar, 1, n, 1);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    vector<int> buildtmp(n+1);
    lop(i,1,n+1) buildtmp[i] = arr[i]-i-1;
    lazyTree<int> seg(n+1);
    seg.build(buildtmp);

    vector<int> lrg(n+1,INF),rrg(n+1);
    lop(i,1,n+1) lrg[arr[i]] = min(i,lrg[arr[i]]),rrg[arr[i]] = max(i,rrg[arr[i]]);
    lop(i,1,n+1)
    {
        lrg[i] = min(lrg[i],lrg[i-1]),rrg[i] = max(rrg[i],rrg[i-1]);
        if(rrg[i]-lrg[i] >= i) {
            cout << 0 << "\n";
            return;
        }
    }
    int cnt = 0;
    lop(i,1,n+1)
    {
        seg.update(i,n,1);
        seg.update(1,i-1,-1);
        // lop(j,1,n+1) cout << seg.getsum(j,j) << " ";cout << "|";
        // cout << seg.getsum(1,i-1) << " " << seg.getsum(i+1,n) << "|";
        // cout << (seg.getsum(1,i-1) >= n-i || seg.getsum(i+1,n) >= i) << "\n";
        if(seg.getsum(1,i-1) >= 0 && seg.getsum(i+1,n) >= 0) cnt ++;
    }
    cout << cnt << "\n";
}

/*


};
void solve()
{
    int n;
    cin >> n;
    // vector<pii> arr;
    // lop(i,1,n+1)
    // {
    //     pii t;
    //     cin >> t.fi;
    //     arr.pb({t.fi,i});
    // }
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    // sort(all(arr));
    vector<int> buildtmp(n+1);
    lazyTree<int> seg(n+1);
    seg.build(buildtmp);
    // // vector<pii> i2vi;
    // lop(i,0,n)
    // {
    //     auto [nrd,mid] = arr[i];
    //     seg.update(mid-nrd+1,mid+nrd+1);
    // }
    // int cnt = 0;
    lop(i,1,n+1)
    {
        seg.update(max(1LL,i-arr[i]+1),min(n,i+arr[i]-1),1);
    }
    int cnt = 0;

    lop(i,1,n+1) if(seg.getsum(i,i) == n) cnt ++;
    lop(i,1,n+1) cout << seg.getsum(i,i) << " ";cout << "\n";
    cout << cnt << "\n";
}

 */

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
