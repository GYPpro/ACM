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

void solve()
{
    int n;
    cin>>n;
    vector<int> e[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<vector<int>> fa(n+1,vector<int>(18));
    vector<int> dep(n+1),sz(n+1);
    function<void(int,int)> dfs=[&](int id,int u){
        fa[id][0]=u;
        sz[id]=1;
        dep[id]=dep[u]+1;
        for(int i=1;i<18;i++) fa[id][i]=fa[fa[id][i-1]][i-1];
        for(auto x:e[id]){
            if(x==u) continue;
            dfs(x,id);
            sz[id]+=sz[x];
        }
    };
    dfs(1,0);

    auto lca=[&](int x,int y)->int{
        if(dep[x]<dep[y]) swap(x,y);
        int tmp=dep[x]-dep[y];
        for(int i=0;i<18;i++){
            if(tmp>>i&1) x=fa[x][i];
        }
        if(x==y) return x;
        for(int i=17;i>=0;i--){
            if(fa[x][i]!=fa[y][i]){
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        return fa[x][0];
    };
    int m;cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(dep[u]<dep[v]) swap(u,v);
        int lc=lca(u,v);
        int dis=-dep[lc]*2+dep[u]+dep[v];
        if(dis%2==1){
            cout<<"0\n";
            continue;
        }
        int tmp=dis/2;
        if(dep[v]-dep[lc]==tmp){
            int t=tmp-1;
            for(int i=17;i>=0;i--){
                if(t>>i&1){
                    v=fa[v][i];
                    u=fa[u][i];
                }
            }
            // cout<<"1:"<<u<<" "<<v<<" ";
            cout<<n-sz[v]-sz[u]<<"\n";            
        }
        else{
            int x=u,y=u,z=u;
            int t=tmp+1,tt=tmp-1;
            for(int i=17;i>=0;i--){
                if(tmp>>i&1){
                    x=fa[x][i];
                }
                // if(t>>i&1) y=fa[y][i];
                if(tt>>i&1) z=fa[z][i];
            }
            // cout<<"2: ";
            cout<<sz[x]-sz[z]<<"\n";
        }
    }
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
