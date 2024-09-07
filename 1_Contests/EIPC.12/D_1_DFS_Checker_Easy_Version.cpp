// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
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

// AC 带懒惰标记线段树 
class minTree
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
    const int INI = INF; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

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
        return min(ansl , ansr);
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
        d[p] = min(d[p * 2] , d[p * 2 + 1]);
        //    合并运算符 ↑
    }

public:
    minTree(int _n)
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

// AC 带懒惰标记线段树 
class maxTree
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
    const int INI = 0; // 不会影响合并运算的初始值，如max取INF，max取0，mti取1

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
    maxTree(int _n)
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
    int n,q;
    cin >> n >> q;
    vector<vector<int>> cnj(n+1);
    vector<vector<int>> pas(n+1);
    vector<vector<int>> secs(n+1);
    lop(i,2,n+1) {
        int t;
        cin >> t;
        cnj[i].pb(t);
        cnj[t].pb(i);
    }
    lop(i,1,n+1) secs[i].pb(i);
    function<void(int,int)> dfs = [&](int p,int f)
    {
        for(auto x:cnj[p])
        {
            if(x == f) continue;
            pas[x] = pas[p];
            pas[x].pb(p);
            for(auto xx:pas[x]) secs[xx].pb(x);
            dfs(x,p);
        }
    };
    dfs(1,0);
    lop(i,1,n+1) pas[i].pb(i);
    vector<int> p(n+1);
    lop(i,1,n+1) cin >> p[i];
    vector<vector<int>> subtreesets(n+1,vector<int>(1));
    vector<vector<int>> rmp(n+1);
    lop(i,1,n+1) 
        for(auto x:pas[i]) subtreesets[x].pb(p[i]),rmp[i].pb(subtreesets[x].size()-1);
        
    // lop(i,1,n+1){
    //     cout << i << " : \n";
    //     for(auto y:rmp[i]) cout << y << " ";
    //     cout << "\n";
        // }

    vector<pair<maxTree,minTree>> sa(1,{maxTree(1),minTree(1)});
    // for(auto &x:sa) x = minTree(subtreesets[])
    lop(i,1,n+1) sa.pb({maxTree(subtreesets[i].size()),minTree(subtreesets[i].size())});
    lop(i,1,n+1) sa[i].fi.build(subtreesets[i]),sa[i].se.build(subtreesets[i]);

    // lop(i,1,n+1)
    // {
    //     cout << i << " ---\n";
    //     lop(j,1,subtreesets[i].size()) cout << sa[i].fi.getsum(j,j) << " ";
    //     cout << "\n";
    // }
    map<int,int> rq;
    lop(i,1,n+1) rq[p[i]] = i; 

    auto checkNode = [&](int ps)-> bool{
        if(subtreesets[ps].size() <= 2) return 1;
        // cout << p[ps] << ":";
        // cout << sa[ps].fi.getsum(1,subtreesets[ps].size()-1) << " ";
        // cout << sa[ps].se.getsum(1,subtreesets[ps].size()-1) << " ";
        // cout << subtreesets[ps].size() << "\n";
        // cout << p[ps] << ":" << sa[ps].fi.getsum(1,subtreesets[ps].size()-1)-subtreesets[ps].size()+2 << "\n";
        if(p[ps] == sa[ps].fi.getsum(1,subtreesets[ps].size()-1)-subtreesets[ps].size()+2 && p[ps] == sa[ps].se.getsum(2,subtreesets[ps].size()-1)-1) return 1;
        else return 0;
    };


    vector<int> tmp(n+1);
    minTree ALLCMP(n+1);
    lop(i,1,n+1) tmp[i] = checkNode(i);
    ALLCMP.build(tmp);


        // cout << "\n";
    while(q--)
    {
        // cout << "\n";
        int cx,cy;
        cin >> cx >> cy;
        int x = rq[cx],y = rq[cy];
        // cout << "x:" << x << " y:" << y << "\n";
        // for(auto [k,v]:rq) cout << "k:" << k << " v:" <<v << "\n";
        swap(rq[cx],rq[cy]);
        int tarx = p[y],tary = p[x];
        swap(p[x],p[y]);
        // for(auto tx:pas[x]) sa[tx].
        lop(i,0,pas[x].size())
            sa[pas[x][i]].fi.update(rmp[x][i],tarx),sa[pas[x][i]].se.update(rmp[x][i],tarx);
        lop(i,0,pas[y].size())
            sa[pas[y][i]].fi.update(rmp[y][i],tary),sa[pas[y][i]].se.update(rmp[y][i],tary);

        for(auto xx:pas[x])
            ALLCMP.update(xx,checkNode(xx));
        for(auto xx:pas[y])
            ALLCMP.update(xx,checkNode(xx));

        // ALLCMP.update(x,checkNode(x));
        // ALLCMP.update(y,checkNode(y));

        // lop(i,1,n+1) cout << ALLCMP.getsum(i,i) << " ";

        // lop(i,1,n+1)
        // {
        //     cout << i << " ---\n";
        //     lop(j,1,subtreesets[i].size()) cout << sa[i].fi.getsum(j,j) << " ";
        //     cout << "\n";
        // }

        // for(auto x:sa)
        // {

        // }
        // lop

        // lop(i,1,n+1){
        //     // cout <<  sa[i].fi.getsum(1,subtreesets[i].size()-1) - sa[i].se.getsum(1,subtreesets[i].size()-1) << " " << subtreesets[i].size()-2 <<  "\n";
        //     if(subtreesets[i].size() <= 3) continue;
        //     if(
        //         sa[i].fi.getsum(2,subtreesets[i].size()-1) == 
        //         - sa[i].se.getsum(2,subtreesets[i].size()-1) == subtreesets[i].size()-3) continue;
        //     else {
        //         cout << "NO\n";
        //         goto NXT;
        //     }
        // }
        if(ALLCMP.getsum(1,n) == 1)
        cout << "YES\n";
        else cout << "NO\n";
        NXT:
    }
    // for(auto x:p) cout << x << " ";
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
