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
const int mod = 1e9+7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}


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
    int n;
    cin >> n;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    SparseTable st;
    st.build(arr);
    // for(auto &x:arr) cin >> x;
    int mx = 0;
    int ttl = 0;
    auto fac2 = [](int x) -> pair<int,int> {
        int cnt = 0;
        while(x % 2 == 0) {
            cnt ++;
            x >>= 1;
        }
        return {cnt,x};
    };

    // auto md2 = [](int x) -> int {

    // };

    vector<int> prfx_facted(n+1),prfx_2(n+1);
    lop(i,1,n+1) {
        auto [f,v] = fac2(arr[i]);
        prfx_facted[i] = prfx_facted[i-1] + v;
        prfx_2[i] = prfx_2[i-1] + f;
    }

    // vector<int> lastGret(n+1);
    vector<int> anss(n+1);
    int FORCE_UPDATE_IDX = -1;
    for(int i = 1;i <= n;i ++)
    {
        int LOOPRG = 0;
        int que = arr[i];
        // if(FORCE_UPDATE_IDX)
        while (++LOOPRG < 35){
            int l = 0,r = i;
            // 1111[1]00000
            auto check = [&](int x) -> bool {
                return st.getsum(x,i) > que; 
            };
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(check(mid)) l = mid;
                else r = mid-1;
            }
            int newly = anss[l] + binpow(2,prfx_2[i-1]-prfx_2[l]) * arr[i] + prfx_facted[i-1]-prfx_facted[l];
            anss[i] = max(anss[i],newly);
            if(anss[i] > 1e9+1) FORCE_UPDATE_IDX = i;
            anss[i] %= mod;
            if(newly < que) break;
            que = newly;
        }
        // cout << l << " " << arr[l] << "\n"; 
    }
    for(int i = 1;i <= n;i ++) cout << anss[i] << " ";cout << "\n";

    // int prfx = 0;
    // for(auto x:arr) {
    //     mx = max(x,mx);
    //     auto [fc,v] = fac2(x);
    //     ttl += fc;
    //     prfx += v;
    //     prfx %= mod;
    //     auto [curf,curv] = fac2(mx);
    //     cout <<( prfx - curv +  mx * (binpow(2,ttl-curf)) % mod + mod )%mod << " ";
    //     // ttl += fac2(x);
    //     // cout << mx * (binpow(2,ttl-fac2(mx))) % mod << " ";
    // }
    // cout << "\n";
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
