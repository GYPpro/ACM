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

int N = 300010;

vector<int> fact;

int binpow(int x,int y ){
    int res = 1;
    while(y > 0) {
        if(y & 1) res = res* x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int inv(int x){
    return binpow(x,mod-2);
}

void init(){
    fact.push_back(1);
    while(fact.size() < N) fact.push_back((fact.back() * (fact.size())) % mod);
}

void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    sort(all(arr));
    int p = n >> 1;
    int ans = 0;
    for(int i = 0;i < n/2;i ++){
        ans += abs(arr[i+p]-arr[i]);
    }
    ans %= mod;
    // cout << ans << " " << fact[n] << "\n";
    ans = ans * fact[n] % mod * inv(fact[n/2]) % mod * inv(fact[n/2]) % mod;
    // ans %= mod; 
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
init();
    int T = 1;
    // cin >> T;
    // for(int i = 0;i < 10;i ++) cout << fact[i] << " ";cout << "\n";
    while(T--) solve();
    return 0;
}
