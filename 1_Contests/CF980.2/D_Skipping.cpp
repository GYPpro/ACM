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
const int INF = 1e18;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map


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
    vector<int> a(n+1),b(n+1);
    lop(i,1,n+1) cin >> a[i];
    lop(i,1,n+1) cin >> b[i];
    int cur = 2;
    vector<int> dis(n+1,INF);
    dis[1] = 0;
    // dis[b[1]] = a[1];
    
    // int nrg = b[1];
    // nrg 当前需要更新的区间右端点
    // cur 当前区间左端点
    // crg 下一个区间的右端点
    vector<vector<pii>> cnj(n+1);
    for(int i = 1;i <= n;i ++) {
        cnj[i].pb({b[i],a[i]});
        if(i > 1) cnj[i].pb({i-1,0});    
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    vector<int> LOCK(n+1);
    int t =0;
    while(q.size()){
        auto [_,u] = q.top();
        t ++;
        q.pop();
        if(LOCK[u]) continue;
        LOCK[u] = 1;
        for(auto [v,w]:cnj[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
            }
        }
        // if(t > 100){ cout << "NO\n";return;}
    }
    // cout << "ok\n";
    // return;
    
    // while(1) {
    //     int crg = nrg;
    //     int c = dis[nrg];
    //     // for(int i = nrg;i >= cur;i --)
    //     // {   
    //     //     if(b[i] <= crg) continue;
    //     //     crg = max(b[i],crg);
    //     //     dis[i] = min(dis[i],c);
    //     //     c = min(dis[i],c);
    //     //     dis[b[i]] = min(dis[b[i]],dis[i]+a[i]);
    //     // }
    //     // nrg = crg;
    //     if(crg == nrg) break;
    //     cur = nrg+1;
    //     nrg = crg;
    // }
    int mx = 0;
    lop(i,1,n+1) a[i] = a[i-1] + a[i];
    // lop(i,1,n+1) cout << dis[i] << " " ;cout << "\n";
    lop(i,1,n+1) mx = max(mx,a[i] - dis[i]);
    cout << mx << "\n";
    // auto update = [&](int l, int r,int c) -> int {
    //     int rg = n;
    //     for(int i = l;i <= r;i ++) dis[i] = min(dis[i],c),dis[];
    // };


    // // b[1]
    // update(1,b[1],dis[1]);
    // lazyTree<int> seg(n+1);
    // seg.build(a);
    // int ci = 1;
    // vector<set<pii>> cnj(n+1);
    // lop(i,1,n+1) cnj[i].insert({i-1,a[i]}),cnj[i].insert({b[i],-a[i]});
    // vector<int> dis(n+1,-INF);
    // priority_queue<pii,vector<pii>,less<pii>> q; //[w,i];
    // q.push({0,1});
    // while(q.size())
    // {
    //     auto [_,u] = q.top();
    //     q.pop();
    //     vector<int> rmc;
    //     for(auto [v,w]:cnj[u])
    //     {

    //     }
    // }
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
    cin >> T;
    while(T--) solve();
    return 0;
}
