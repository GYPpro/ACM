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
const int INF = 1e17;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map


class SparseTable
{
    using func_type = function<int(const int &, const int &)>;
    
    vector<vector<int>> ST;
    int len;
    vector<int> preLog;
    func_type op;
    static int default_func(const int &t1, const int &t2) { return max(t1, t2); }

public:
    void build(const vector<int> &v, func_type _func = default_func)
    {
        op = _func;
        len = v.size();
        int l1 = ceil(log2(len)) + 1;
        ST.assign(len, vector<int>(l1, 0));
        for (int i = 0; i < len; ++i)
        {
            ST[i][0] = v[i];
        }
        for (int j = 1; j < l1; ++j)
        {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i)
            {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
        preLog.resize(len + 1);
        lop(i, 1, len + 1) preLog[i] = floor(log2(i));
    }

    int getsum(int l, int r)
    {
        if (r < l)
            return 0;
        l = max(0LL, l), r = min(len - 1, r);
        if (r == 0)
            return 0;
        int lt = r - l + 1;
        int q = preLog[lt];
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

void solve()
{
    int n,q,p;
    cin >> n >> q >> p;
    vector<int> a(n+2);
    lop(i,1,n+1) cin >> a[i];
    vector<int> cur;
    vector<int> ans(p+1);
    lop(i,1,p+1)
    {
        cur = a;
        deque<int> qs;
        vector<int> ptr;
        for(int k = 0;k <= n;k += i) ptr.pb(k);
        qs.push_back(n+1);
        for(int ptri = ptr.size()-1;ptri > 0;ptri --)
        {
            int si = ptr[ptri];
            while(!qs.empty() && cur[qs.back()] <= cur[si]) qs.pop_back();
            while(!qs.empty() && qs.front()-(si-i)>p) qs.pop_front();
            qs.push_back(si);
            cur[si-i] += cur[qs.front()];
         }
        int MAXans = -INF;
        for(int ci = 0;ci <= p;ci += i) MAXans = max(MAXans,cur[ci]);
        ans[i] = MAXans;
    }
    while(q--)
    {
        int x;
        cin >> x;
        if(x > p) cout << "Noob\n";
        else cout << ans[x] << "\n";
    }
}

signed main()
{
#ifdef FC
    freopen("C.A.in","r",stdin);
    freopen("C.A.ptc","w",stdout);
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
