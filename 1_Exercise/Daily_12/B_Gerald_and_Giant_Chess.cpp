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
#define ord(u, v) min(u ,v ),max(u ,v )
// #define set unordered_set
// #define map unordered_map


const int N = 1e6;
const int mod = 1e9+7;

int binpow(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

vector<int> fac(N), inv(N);

void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = binpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

// AC 带懒惰标记线段树 
template <class TYPE_NAME>
class lazyTree
{
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
        d[p] =max( d[p * 2] , d[p * 2 + 1]);
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
        return max(ansl , ansr);
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
        d[p] = max(d[p * 2] , d[p * 2 + 1]);
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

using segt = lazyTree<int>;

void solve()
{
    int n,m,b;
    cin >> n >> m >> b;
    vector<pii> dots(b);
    auto C = [&](int x, int y) -> int
    {
        // assert(x>=y);
        return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
    };
    for(auto &[x,y]:dots) cin >> x >> y;
    sort(all(dots),[&](pii x,pii y){return x.fi+x.se < y.fi+y.se;});
    auto fuc = [&](int n,int m) -> int {
        // cout << n+m-2 << " " << n-1 << "\n";
        return C(n+m-2,n-1) % mod;
    };
    int SUM = fuc(n,m);
    // cout << SUM << " " << fuc(n,m) << "\n";

    map<pii,int> ctr;
    for(auto [x,y]:dots) {
        ctr[{x,y}] = fuc(x,y);
    }

    for(auto [x,y]:dots) {
        int DEV = ctr[{x,y}];
        for(auto k:dots){
            auto [tx,ty] = k;
            if(tx >= x && ty >= y && (tx != x || ty != y))
            {
                // cout << DEV <<" "<< fuc(abs(tx-x)+1,abs(ty-y)+1) << "\n";
                ctr[k] -= DEV * fuc(abs(tx-x)+1,abs(ty-y)+1) % mod;
                ctr[k] = (ctr[k] + mod) % mod;
                // cout << ctr[k] << " \n";
            }
        }
        SUM -= DEV * fuc(n-x+1,m-y+1) % mod;
        SUM = (SUM + mod) % mod;
        // cout << DEV << " " << fuc(n-x+1,m-y+1) << " " << DEV * fuc(n-x+1,m-y+1) << " " << SUM << "\n";
    }

    cout << SUM << "\n";
}

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
    init();
    // cin >> T;
    while(T--) solve();
    return 0;
}
