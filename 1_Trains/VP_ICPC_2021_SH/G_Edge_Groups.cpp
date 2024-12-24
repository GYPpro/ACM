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

const int N=1e5+100;
const int mod=998244353;
int fac[N],inv[N];
int ksm(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int c(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void solve()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    int n;
    cin>>n;
    vector<int> e[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=1;
    // vector<int> 
    function<int(int ,int)> dfs=[&](int id,int fa)->int{
        int cnt=0;
        for(auto x:e[id]){
            if(x==fa) continue;
            cnt+=dfs(x,id);
        }
        if(cnt==0) return 1;
        int f=(cnt%2==0);
        if(cnt&1) cnt++;
        int cur=1;
        for(int i=2;i<=cnt;i+=2) cur=(cur*c(i,2))%mod;
        cur=cur*inv[cnt/2]%mod;
        ans*=cur;
        return f;
    };
    dfs(1,0);
    cout<<ans<<"\n";
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
