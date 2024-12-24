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

const int mod = 998244353;

int binpow(int a,int b) {
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mtx(n,vector<int>(m));
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
        {
            char c;
            cin >> c;
            mtx[i][j] = c == 'o';
        }
    
    map<int,int> rec;
    vector<int> tmp0(max(n,m)+1),tmp1(max(n,m)+1);
    tmp0[0] = tmp1[0] = 1;
    for(int i = 0;i < max(n,m)+1;i ++)
    {
        if(i%2) tmp1[i] = binpow(2,i);
        else tmp0[i] = binpow(2,i); 
    }
    for(int i = 1;i < max(n,m)+1;i ++)
    {
        tmp0[i] = (tmp0[i-1] + tmp0[i]) % mod;
        tmp1[i] = (tmp1[i-1] + tmp1[i]) % mod;
    }
    auto f = [&](int x) -> int {
        
        if(rec.find(x) != rec.end()) return rec[x];

        int res = 0;
        for(int i = 0;i <= x-2;i ++){
            if(i%2) res += tmp0[i] * binpow(2,x-i-2) % mod;
            else res += tmp1[i] * binpow(2,x-i-2) % mod;
            res %= mod;
        }
        return rec[x] = res;
    };

    int ans = 0;
    int ttl = 0;
    for(auto x:mtx) for(auto y:x) ttl += y;
    ttl %= mod;
    auto cacu = [&](){
        for(auto x:mtx)
        {
            int len = 0;
            for(auto y:x) {
                if(y) len ++;
                else {
                    ans += binpow(2,ttl-len) * f(len) % mod;
                    ans %= mod;
                    len = 0;
                }
            }
            ans += binpow(2,ttl-len) * f(len) % mod;
            ans %= mod;
        }
    };
    cacu();
    vector<vector<int>> mtx2(m,vector<int>(n));
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)   
            mtx2[j][i] = mtx[i][j];
    mtx = mtx2;
    cacu();
    cout << ans << "\n";
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
    // while(T--) test();
    return 0;
}
