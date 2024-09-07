// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;

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
        d[p] = d[p * 2] + d[p * 2 + 1];
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
        return ansl + ansr;
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
        d[p] = d[p * 2] + d[p * 2 + 1];
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
        return subGetSum(l, r, 1, n, 1);
    }

    void update(int l, int r, TYPE_NAME c) // 修改区间
    {
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
    vector<vector<int>> cnj(n+1);
    lop(i,2,n+1){
        int t;
        cin >> t;
        cnj[i].pb(t);
        cnj[t].pb(i);
    }
    vector<int> wei(n+1);
    vector<int> DFN(n+1);
    vector<pii> DFNrange(n+1);
    int idx = 0;
    function<int(int,int)> dfs = [&](int p,int f) -> int  {
        idx ++;
        DFN[p] = idx;
        // if(cnj[p].size() == 1) return DFNrange[p] = {idx,idx},wei[p] = 1;
        int sum = 1;
        for(auto x:cnj[p]) if(x == f) continue;
        else{
            sum += dfs(x,p);
        }
        DFNrange[p] = {DFN[p],idx};
        return wei[p] = sum;
    };
    dfs(1,0);
    vector<int> initmp(n+2,0);
    lazyTree<int> seg(n+2);
    seg.build(initmp);
    // for(auto x:wei) cout << x << " ";cout << "\n";
    ordered_set P1;
    lop(i,1,n+1) P1.insert(i);
    vector<int> a(n+1),b(n+1);
    lop(i,1,n+1)
    {
        a[i] = *P1.find_by_order(wei[i]-1-seg.getsum(DFNrange[i].fi,DFNrange[i].se));
        P1.erase(a[i]);
        seg.update(DFN[i],1);
    }
    vector<pii> rst;
    lop(i,1,n+1) rst.pb({a[i],i});
    P1.clear();
    lop(i,1,n+1) P1.insert(i);
    sort(all(rst),[&](pii a,pii b) -> bool {return a.fi > b.fi;});
    lop(i,1,n+1) seg.update(i,0);
    // cout << "\n";
    // for(auto [u,v]:DFNrange) cout  << u << " " << v << "\n";
    // for(auto x:a) cout << x << " ";cout << "\n";
    // lop(i,1,n+1) cout << seg.getsum(DFNrange[i].fi,DFNrange[i].se) << "\n";
    for(auto [_,i]:rst)
    {
        // cout << i << ":" << seg.getsum(DFNrange[i].fi,DFNrange[i].se) << "\n";
        b[i] = *P1.find_by_order(wei[i]-1-seg.getsum(DFNrange[i].fi,DFNrange[i].se));
        P1.erase(b[i]);
        seg.update(DFN[i],1);
    }
    lop(i,1,n+1) cout << a[i] << " " << b[i] << " ";cout << "\n";
    // for(auto [sa,sb]:{a,b})
    // {

    // }
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

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
