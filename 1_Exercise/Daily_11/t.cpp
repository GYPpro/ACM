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
#define map unordered_map

class Pollard_Rho
{
    vector<int> B;
    private:
    int mul(int a,int b,int m){
        int r = a * b - m * (int)(1.L / m * a * b);
        return r - m * (r >= m) + m * (r < 0);
    }
    int mypow(int a,int b,int m) {
        int res = 1 % m;
        for(;b;b >>= 1,a = mul(a,a,m))
        {
            if(b & 1) res = mul(res,a,m);
        }
        return res;
    }
    bool MR(int n){
        if(n <= 1) return 0;
        for(int p:B){
            if(n == p) return 1;
            if(n % p == 0) return 0;
        }
        int m = (n-1) >> __builtin_ctz(n-1);
        for(int p:B){
            int t = m,a = mypow(p,m,n);
            while(t != n-1 && a != 1 && a != n-1){
                a = mul(a,a,n);
                t *= 2;
            }
            if(a != n-1 && t %2 == 0) return 0;
        }
        return 1;
    }

    int PR(int n){
        for(int p:B) if(n%p == 0) return p;
        auto f = [&](int x) -> int {
            x = mul(x,x,n) + 1;
            return x >= n ? x - n : x ;  
        };
        int x = 0,y = 0,tot = 0,p = 1,q,g;
        for(int i = 0;(i & 255) || (g = gcd(p, n)) == 1;i ++,x = f(x),y = f(f(y))){
            if(x == y){
                x = tot ++;
                y = f(x);
            }
            q = mul(p,abs(x-y),n);
            if(q) p = q;
        }
        return g;
    }
    public:
    vector<int> fac(int n) {
        if(n <= 1) return {};
        if(MR(n)) return {n};
        int d = PR(n);
        auto v1 = fac(d),v2 = fac(n/d);
        auto i1 = v1.begin(),i2 = v2.begin();
        vector<int> ans;
        while(i1 != v1.end() || i2 != v2.end()){
            if(i1 == v1.end()) ans.pb(*i2 ++);
            else if(i2 == v2.end()) ans.pb(*i1++);
            else if(*i1 < *i2) ans.pb(*i1++);
            else ans.pb(*i2++); 
        }
        return ans;
    }
    Pollard_Rho(){
        B = {2,3,5,7,11,13,17,19,23};
    }
};

class eulaFac{
public:
vector<int> pri;
vector<int> vis;
    eulaFac(int n){
        vis.resize(n+1);
        for(int i = 2;i <= n;i ++) {
            if(!vis[i]) pri.push_back(i);
            for(auto x:pri){
                if(i * x > n) break;
                vis[x * i] = max(vis[x*i],x);
                if(i % x == 0) break;
            }
        }
    }
    vector<int> fac(int n){
        vector<int> res;
        while(n){
            while(vis[n] && (n%vis[n] == 0)) res.push_back(vis[n]),n /= vis[n];
            if(!vis[n]) {
                res.push_back(n);
                return res;
            }
        }
        return res;
    }
};  
eulaFac ec(1e7+10);

void solve()
{
    
}
using ld = long double;
void lst(){
    int a,b;
    cin >> a >> b;
    vector<ld> prf = {1,1};
    for(int i = 2;i < 200;i ++) prf.push_back(prf[prf.size()-1]*a + prf[prf.size()-2]*b);
    ld x = 0;
    ld t = 10;
    for(auto xx:prf) x += xx/t,t *= 10.0;
    cout << fixed << setprecision(15) << x << "\n"; 
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
    // for(int i = 0;i < 20;i ++) cout << ec.vis[i] << " ";cout << "\n";
    cin >> T;
    // while(T--) solve();
    while(T--) lst();
    return 0;
}