#pragma GCC optimize(3)

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
#define set unordered_set
// #define map unordered_map


// #define int long long
// #define pii pair<int, int>
// const int INF = 1145141919810LL;
// using namespace std;

class Pollard_Rho
{
public:

    vector<int> B;
    int mul(int a, int b, int m)
    {
        int r = a * b - m * (int)(1.L / m * a * b);
        return r - m * (r >= m) + m * (r < 0);
    }
    int mypow(int a, int b, int m)
    {
        int res = 1 % m;
        for (; b; b >>= 1, a = mul(a, a, m))
        {
            if (b & 1)
            {
                res = mul(res, a, m);
            }
        }
        return res;
    }
    bool MR(int n)
    {
        if (n <= 1)
            return 0;
        for (int p : B)
        {
            if (n == p)
                return 1;
            if (n % p == 0)
                return 0;
        }
        int m = (n - 1) >> __builtin_ctz(n - 1);
        for (int p : B)
        {
            int t = m, a = mypow(p, m, n);
            while (t != n - 1 && a != 1 && a != n - 1)
            {
                a = mul(a, a, n);
                t *= 2;
            }
            if (a != n - 1 && t % 2 == 0)
                return 0;
        }
        return 1;
    }

    inline const int getfecsum(int _n)
    {
        int sum = 0;
        while (_n)
        {
            sum += _n % 10;
            _n /= 10;
        }
        return sum;
    };

    int PR(int n)
    {
        for (int p : B)
        {
            if (n % p == 0)
                return p;
        }
        auto f = [&](int x) -> int
        {
            x = mul(x, x, n) + 1;
            return x >= n ? x - n : x;
        };
        int x = 0, y = 0, tot = 0, p = 1, q, g;
        for (int i = 0; (i & 255) || (g = gcd(p, n)) == 1; i++, x = f(x), y = f(f(y)))
        {
            if (x == y)
            {
                x = tot++;
                y = f(x);
            }
            q = mul(p, abs(x - y), n);
            if (q)
                p = q;
        }
        return g;
    }

    vector<int> fac(int n)
    {
        // if(n == 0)
        // #define pb emplace_back
        if (n <= 1)
            return {};
        if (MR(n))
            return {n};
        int d = PR(n);
        auto v1 = fac(d), v2 = fac(n / d);
        auto i1 = v1.begin(), i2 = v2.begin();
        vector<int> ans;
        while (i1 != v1.end() || i2 != v2.end())
        {
            if (i1 == v1.end())
            {
                ans.pb(*i2++);
            }
            else if (i2 == v2.end())
            {
                ans.pb(*i1++);
            }
            else
            {
                if (*i1 < *i2)
                {
                    ans.pb(*i1++);
                }
                else
                {
                    ans.pb(*i2++);
                }
            }
        }
        return ans;
    }

public:

    Pollard_Rho(){
        B = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    }

    vector<pii> fac_Comp(int n)
    {
        auto srt = fac(n);
        map<int, int> cnt;
        for (auto x : srt)
            cnt[x]++;
        vector<pii> rt;
        for (auto x : cnt)
            rt.push_back(x);
        return rt;
    }

    vector<int> fac_pri(int n)
    {
        return fac(n);
    }
    
    vector<int> fac_all(int n)
    {
        vector<pii> rt = fac_Comp(n);
        vector<int> v;
        function<void(int, int)> dfs = [&](int id, int x)
        {
            if (id == rt.size())
            {
                v.push_back(x);
                return;
            }
            for(int i = 0;i <= rt[id].se;i ++)
            {
                dfs(id + 1, x * (mypow(rt[id].fi, i, INF)));
            }
        };
        dfs(0, 1);
        return v;
    }
};
 

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> cnj(n+1);
    for(int i = 1;i < n;i ++)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v);
        cnj[v].pb(u);
    }
    // vector<int> wei(n+1);
    Pollard_Rho pr;
    int mx = 0,mxi;
    for(int i = 1;i <= n;i ++)
    {
        if(cnj[i].size() > mx) mxi = i,mx = cnj[i].size();
    }

    set<int> trm;
    for(int i = 2;i <= 2*n;i ++) trm.insert(i);
    vector<int> ans(n+1);
    
    using itf =  function<void(int,int)>;

    bool aviflag = 1;

    ans[mxi] = 1;

        vector<int> tbr;
    itf dfs = [&](int p,int f) -> void {
        // int curmx = 0;
        for(auto x:cnj[p]) if(x == f) continue;
        else {
            if(ans[x]) continue;
            int  itt = 0;
            tbr.clear();
        // for(auto x:trm) if(x <= curmxd) tbr.push_back(x);
        // else break;
            for(auto tb:trm){
                if(!pr.MR(abs(ans[p]-tb))) {
                    ans[x] = tb;
                    break;
                }
                tbr.push_back(tb);
                itt ++;
                // if(itt > 30) break;
            }
            for(auto tb:tbr) trm.erase(tb);
            // if(!ans[x]) for(auto tsb = trm.rbegin();tsb != trm.rend();++tsb){
            //     auto tb = *tsb;
            //     if(!pr.MR(abs(ans[p]-tb))) {
            //         ans[x] = tb;
            //         break;
            //     }
            //     itt ++;
            //     // if(itt > 30) break;
            // }
            if(!ans[x]) aviflag = 0;
            trm.erase(ans[x]);
            // curmx = max(curmx,ans[x]);
            // for(auto  x:trm) if()
        }
        for(auto x:cnj[p]) if(x == f) continue;
        else dfs(x,p);
    };dfs(mxi,0);
 
    // assert(aviflag);
    // while(!aviflag){
    //     aviflag = 1;
    //     fill(all(ans),0);
    //     dfs(rand()%n+1,0);
    // }
    if(!aviflag) {cout << -1 << "\n";return;}
    // for(auto x:ans) cout << x << " ";cout << "\n";
    for(int i = 1;i <= n;i ++) cout << ans[i] << " ";cout << "\n";

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
    srand(time(0));
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
