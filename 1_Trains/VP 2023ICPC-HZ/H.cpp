
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
using namespace std;

// int ans[4]={0};
// int n=4;
// vector<int> s(4);
// vector<int> a(n),b(n),c(n);
// int sum=0;
// void dfs(int id){
//     int j=s[id];
//     if(id==4){
//         // if(a[1]==8) sum++;
//         for(int i=0;i<4;i++) cout<<s[i]<<" ";
//         cout<<" ->  ";
//         for(int i=0;i<4;i++) cout<<a[i]<<" \n"[i==n-1];
//         // cout<<a[0]<<"\n";
//         for(int i=0;i<4;i++) ans[i]+=a[i];
//         return;
//     }
//     if(a[j]<a[b[j]]){
//         a[j]+=c[j];
//         dfs(id+1);
//         a[j]-=c[j];
//     }else dfs(id+1);
// }
const int mod=1e9+7;
int ksm(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
// void solve()
// {
//     int n;cin>>n;
    
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++){
//         cin>>b[i];b[i]--;
//     }
//     for(int i=0;i<n;i++) cin>>c[i];
//     int cnt=0;
//     for(int i=0;i<n;i++) s[i]=i;
//     do{
//         // for(int i=0;i<n;i++) cout<<s[i]<<" \n"[i==n-1];
//         cnt++;
//         dfs(0);
//     }while(next_permutation(s.begin(),s.end()));
//     cout<<sum<<"\n";
//     // for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
//     cnt=ksm(cnt,mod-2);
//     for(int i=0;i<n;i++) ans[i]=ans[i]*cnt%mod;
//     for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
// }
const int N=5e5+100;
vector<int> fac(N+1),inv(N+1);
void solve(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),w(n+1);
    vector<bool> vis(n+1),vst(n+1); 
    vector<int> fa(n+1);
    vector<int> sz(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>fa[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    vector<int> ans(n+1);
    queue<int> q;
    function<int(int)> dfs=[&](int id)->int{
        if(vis[id]==1) return sz[id];
        if(vst[id]==1) return sz[id]=-1;
        vst[id]=1;
        q.push(id);
        int cnt;
        if(a[id]>=a[fa[id]]+w[fa[id]]) cnt=-1;
        else if(a[id]<a[fa[id]]) cnt=0;
        else cnt=dfs(fa[id]);
        // cout<<id<<" "<<cnt<<"\n";
        if(cnt==-1){
            ans[id]=a[id];
            return sz[id]=-1;
        }
        sz[id]=cnt+1;
        ans[id]=((inv[sz[id]]*(a[id]+w[id]))%mod+(((fac[sz[id]]-1)*(inv[sz[id]]))%mod*a[id])%mod)%mod;
        return sz[id];
    };
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        dfs(i);
        while(!q.empty()){
            int cur=q.front();q.pop();
            vis[cur]=1;
        }
    }
    // for(int i=1;i<=n;i++) cout<<sz[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
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
    fac[0]=1,inv[0]=1;
    for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N]=ksm(fac[N],mod-2);
    for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
