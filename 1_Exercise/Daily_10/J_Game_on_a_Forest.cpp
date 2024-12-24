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

int n;
bool dfs(vector<array<int,2>> g,vector<int> vet){
    bool ok=0;
    vector<array<int,2>> ne;
    for(auto [x,y]:g){
        if(vet[x]==1&&vet[y]==1) ne.push_back({x,y});
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=vet[i];
    if(cnt==0) return 0;
    for(int i=1;i<=n;i++){
        if(vet[i]==1){
            vet[i]=0;
            if(dfs(ne,vet)==0) ok=1;
            vet[i]=1;
        }
    }
    int sz=ne.size();
    for(int i=0;i<sz;i++){
        vector<array<int,2>> fuck;
        for(int j=0;j<sz;j++){
            if(i==j) continue;
            fuck.push_back(ne[j]);
        }
        if(dfs(fuck,vet)==0) ok=1;
    }
    return ok;
}
void solve()
{
    int m;
    cin >> n >> m;
    vector<array<int,2>> g(m);
    for(int i=0;i<m;i++){
        cin>>g[i][0]>>g[i][1];
    }
    vector<int> a(n+1,1);
    a[0]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        a[i]=0;
        ans+=(dfs(g,a)==0);
        a[i]=1;
    }
    cout<<ans<<"\n";
    for(int i=0;i<m;i++){
        vector<array<int,2>> fuck;
        for(int j=0;j<m;j++){
            if(i==j) continue;
            fuck.push_back(g[i]);
        }
        ans+=(dfs(fuck,a)==0);
    }
    cout<<ans<<"\n";
    // vector<vector<int>> cnj(n+1);
    // vector<int> vis;
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
