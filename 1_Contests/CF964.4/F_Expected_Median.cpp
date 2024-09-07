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
const int mod = 1e9+7;
int N = 1e6;
using namespace std;

// }
int ksm(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return  ans;
}


void solve()
{

    vector<int> fac(N),inv(N);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    auto C  = [&](int x,int y) -> int{
        if(x < 0 || y < 0) return 0;
        if(y > x) return 0;
        return (fac[x]*inv[y]%mod)*inv[x-y]%mod;
    };

    int t;
    cin >> t;
    while(t--)
    {
        vector<int> cnt(2);
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        for(auto x:arr) cnt[x] ++;
        int ans = 0;
        int mt1 = (k+1)/2;
        lop(i,mt1,k+1)
        {
            // cout << i << " " << cnt[1] << " " << k-i << " " << cnt[0] << "\n";
            ans += C(cnt[1],i) * C(cnt[0],k-i) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }
}


signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
