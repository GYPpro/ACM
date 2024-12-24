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

class leftist
{
public:
    struct point
    {
        int l, r, d, v, t, to;
    };
    vector<point> a;
    vector<int> r;
private:
    vector<int> fa;
    void Union(int u,int v){
        if((u=find(u))^(v=find(v)))
            this->merge(this->r[v],this->r[u]),fa[u]=v;
    }
    int find(int x){
        return x^fa[x]?fa[x]=find(fa[x]):x;
    }
    leftist(int _n) {
        a.clear();
        a.resize(_n,{0, 0, -1, 0, 0, 0});
        r.resize(_n);
        fa.resize(_n),iota(fa.begin(),fa.end(),0);
    }
    void merge(int &x, int &y)
    {
        if (!x || !y)
        {
            x ^= y;
            return;
        }
        if (a[x].v > a[y].v)
            x ^= y ^= x ^= y;
        a[y].t -= a[x].t, a[y].v -= a[x].t;
        merge(a[x].r, y);
        if (a[a[x].l].d < a[a[x].r].d)
            a[x].l ^= a[x].r ^= a[x].l ^= a[x].r;
        a[x].d = a[a[x].r].d + 1;
    }
    void spread(int &p)
    {
        a[a[p].l].t += a[p].t, a[a[p].r].t += a[p].t;
        a[a[p].l].v += a[p].t, a[a[p].r].v += a[p].t;
        a[p].t = 0;
    }
    void pop(int &x)
    {
        spread(x), merge(a[x].l, a[x].r), x = a[x].l;
    }
    using prt = pair<bool,point*>;
    prt top(int &x)
    {
        while (r[x] && !(find(a[r[x]].to) ^ x))
            pop(r[x]);
        if (!r[x]) return prt({0,nullptr});
        a[r[x]].to = find(a[r[x]].to);
        return prt({1,&a[r[x]]});
    }
};

void solve()
{
    int n,m;
    cin >> n >> m;

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
