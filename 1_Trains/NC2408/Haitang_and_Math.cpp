// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

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

 int mul(int a, int b, int m) {
    int r = a * b - m * (int)(1.L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
 }
 int mypow(int a, int b, int m) {
    int res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m)) {
        if (b & 1) {
            res = mul(res, a, m);
        }
    }
    return res;
 }
 int B[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
 bool MR(int n) {
    if (n <= 1) return 0;
    for (int p : B) {
        if (n == p) return 1;
        if (n % p == 0) return 0;
    }
    int m = (n - 1) >> __builtin_ctz(n - 1);
    for (int p : B) {
        int t = m, a = mypow(p, m, n);
        while (t != n - 1 && a != 1 && a != n - 1) {
            a = mul(a, a, n);
            t *= 2;
        }
        if (a != n - 1 && t % 2 == 0) return 0;
    }
    return 1;
 }

inline const int getfecsum(int _n){
        int sum = 0;
        while(_n)
        {
            sum += _n%10;
            _n /= 10;
        }
        return sum;
};

 int PR(int n) {
    for (int p : B) {
        if (n % p == 0) return p;
    }
    auto f = [&](int x) -> int {
        x = mul(x, x, n) + 1;
        return x >= n ? x - n : x;
    };
    int x = 0, y = 0, tot = 0, p = 1, q, g;
    for (int i = 0; (i & 255) || (g = gcd(p, n)) == 1; i++, x = f(x), y = f(f(y))) {
        if (x == y) {
            x = tot++;
            y = f(x);
        }
        q = mul(p, abs(x - y), n);
        if (q) p = q;
    }
    return g;
 }
 vector<int> fac(int n) {
    // if(n == 0)
    // #define pb emplace_back
    if (n <= 1) return {};
    if (MR(n)) return {n};
    int d = PR(n);
    auto v1 = fac(d), v2 = fac(n / d);
    auto i1 = v1.begin(), i2 = v2.begin();
    vector<int> ans;
    while (i1 != v1.end() || i2 != v2.end()) {
        if (i1 == v1.end()) {
            ans.pb(*i2++);
        } else if (i2 == v2.end()) {
            ans.pb(*i1++);
        } else {
            if (*i1 < *i2) {
                ans.pb(*i1++);
            } else {
                ans.pb(*i2++);
            }
        }
    }
    return ans;
 }
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    // auto getfecsum = [](int _n) -> int{
    //     int sum = 0;
    //     while(_n)
    //     {
    //         sum += _n%10;
    //         _n /= 10;
    //     }
    //     return sum;
    // };
    
    // vector<std::size_t> factors;
    lop(f,1,109)
    {
        // factors.clear();
        if(n-f < 0) break;
        int t = n-f;
        auto srt = fac(t);
        // vector<pii>
        
        map<int,int> cnt;
        for(auto x:srt) cnt[x] ++;
        vector<pii> rt;
        for(auto x:cnt) rt.pb(x);
        vector<int> v;
        function<void(int,int)> dfs = [&](int id,int x){
            if(id == rt.size()){ v.pb(x);return;}
            lop(i,0,rt[id].se+1)
            {
                dfs(id+1,x*(mypow(rt[id].fi,i,INF)));
            }
        };
        dfs(0,1);
        // cout << t << " : " ;
        // for(auto x:v) cout << x << " ";cout << "\n";
        for(auto x:v) if(getfecsum(x) == f && x >= 10) ans ++;
        // array<int,3>

        // cout << rt.size() << "\n";
        // for(auto x:rt) cout << x << " ";cout << "\n";
        // for(int i = 0;i < (1 << rt.size());i ++)
        // {
        //     int tmp = 1;
        //     bitset<32> st = i;
        //     lop(j,0,rt.size()) tmp *= rt[j] * st[j];
        //     if(getfecsum(tmp) == f) ans ++;
        // }
        // for(int i = 1;i*i <= t;i ++)
        // {
        //     if(t%i == 0){
        //         if(i >= 10) if(getfecsum(i) == f) ans ++;
        //         if(t/i != i && t/i >= 10) if(getfecsum(t/i) == f) ans ++;
        //     }
        // }
        // for(auto x:factors) if(getfecsum(x) == f) ans ++;
        // cout << t << ":";
        // for(auto x:factors) cout << x << " ";cout << "\n";
        // cout << "-" << ans << "-\n";
    }
    cout << ans << "\n";
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
