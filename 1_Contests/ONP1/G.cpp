// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pii pair<int,int>
using ord_set = tree<pii, null_type, less_equal<pii>, rb_tree_tag,
tree_order_statistics_node_update>;
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

class segt{
public:
#define LS p*2
#define RS p*2+1
    vector<int> d,a,b;
    int n;
    int INI = 0;
    void sb(int s,int t,int p)
    {
        if(s == t) {
            d[p] = a[s];
            return;
        }
        int m = s + ((t - s) >> 1);
        sb(s,m,LS);
        sb(m+1,t,RS);
        d[p] = d[LS] + d[RS];
    }
    int sgs(int l,int r,int s,int t,int p)
    {
        if(l <= s && t <= r)
        {
            return d[p];
        }
        int m = s + ((t-s) >> 1);
        if(b[p] != 0)
        {
            d[LS] += b[p] * (m-s+1);
            d[RS] += b[p] * (t-m);
            b[LS] += b[p];
            b[RS] += b[p];
            b[p] = 0;
        }
        int ansl = INI,ansr = INI;
        if(l <= m) ansl = sgs(l,r,s,m,LS);
        if(r > m) ansr = sgs(l,r,m+1,t,RS);
        return ansl+ansr;
    }
    void su(int l,int r,int c,int s,int t,int p)
    {
        if(l <= s && t <= r)
        {
            d[p] += (t-s+1) * c;
            b[p] += c;
            return;
        }    
        int m = s + ((t-s) >> 1);
        if(b[p] != 0 && s != t)
        {
            d[LS] += b[p] * (m-s+1);
            d[RS] += b[p] * (t-m);
            b[LS] += b[p];
            b[RS] += b[p];
            b[p] = 0;
        }
        if(l <= m) su(l,r,c,s,m,LS);
        if(r > m) su(l,r,c,m+1,t,RS);
        d[p] = d[LS]+d[RS];
    }
    segt(int _n)
    {
        n = _n;
        d.resize(4*n+5);
        a.resize(4*n+5);
        b.resize(4*n+5);
        // d.resize(4*n+5);
    }

    void build(vector<int> _a)
    {
        a = _a;
        sb(1,n,1);
    }
    int getsum(int l,int r){
        return sgs(l,r,1,n,1);
    }
    void update(int l,int r,int c)
    {
        su(l,r,c,1,n,1);
    }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    ord_set st;
    lop(i,1,n+1){
        cin >> arr[i];
        st.insert({arr[i],i});
    }
    vector<array<int,4>> que;
    lop(i,0,q)
    {
        int l,r,k;
        cin >> l >> r >> k;
        que.pb({k,l,r,i});
    }
    sort(all(que));
    segt lset(n+1),rset(n+1);
    // <=k/2 : l, >k/2 R
    vector<int> bt(n+1);
    rset.build(bt);
    // bt = arr;
    lset.build(arr);
    vector<int> ans(q);
    int rsz = 0;
    int prvk = 0;
    for(auto [k,l,r,i]:que)
    {
        if(prvk < k) {
            int rg =  st.order_of_key({k/2,INF});
            for(int idx = st.order_of_key({prvk/2,INF})+1;idx <= rg;idx ++)
            {
                auto [v,i] = *st.find_by_order(idx-1);
                lset.update(i,i,-v);
                rset.update(i,i,v);
                rsz ++;
            }
            prvk = k;
        }
        lop(idx,1,n+1) cout << lset.getsum(idx,idx) << " ";cout << "\n";
        lop(idx,1,n+1) cout << rset.getsum(idx,idx) << " ";cout << "\n";
        ans[i] = lset.getsum(l,r) + (k * rsz - rset.getsum(l,r));
    }
    for(auto x:ans) cout << x << "\n";
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
