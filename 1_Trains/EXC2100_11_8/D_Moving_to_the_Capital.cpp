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
const int N=2e5+7;
int n,m;
vector<int> e[N];
int dis[N]={0};
int vis[N]={0};
int ans[N]={0};
void bfs()
{
    queue<int> q;
    dis[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:e[u])
        {
            if(dis[v])continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    } 
}
void dfs(int u)
{
    vis[u]=1;
    ans[u]=dis[u];
    for(auto v:e[u])
    {
        if(dis[v]<=dis[u])
        {
            ans[u]=min(dis[v],ans[u]);
            continue;
        }
        else 
        {
            if(vis[v]) 
            {
                ans[u]=min(ans[u],ans[v]);
                continue;
            }           
            dfs(v);
            ans[u]=min(ans[v],ans[u]);
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        dis[i]=0;
        vis[i]=0;
        ans[i]=INF;    
    }
    ans[1]=1;
    vis[1]=1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].pb(v);
    }   
    bfs();
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]-1<<" ";
    }
    cout<<"\n";
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
    cin >> T;
    while(T--) solve();
    return 0;
}
