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
int val[N];
vector<int> e[N];
int disa[N],disb[N],disc[N];
int n,m,a,b,c;
struct node
{
    int u;
    int d;
    bool operator < (const node x) const 
    {
        return d>x.d;
    }
};
priority_queue<node> q;
void dj(int s,int dis[])
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    vector<int> vis(n+10,0);
    q.push((node){s,0});
    while(!q.empty())
    {
        node re=q.top();
        q.pop();
        int u=re.u;
        int d=re.d;
        // cout<<d<<"\n";
        if(vis[u])continue;
        dis[u]=d;
        vis[u]=1;
        for(auto v:e[u])
        {
            if(vis[v]||dis[v]<=d+1)continue;
            dis[v]=d+1;
            q.push((node){v,d+1});
        }
    }
    
}
void solve()
{
    
    cin>>n>>m>>a>>b>>c;
    val[0]=0;
    for(int i=1;i<=n;i++)
    {
        disa[i]=disb[i]=disc[i]=INF;
        e[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        cin>>val[i];
    }
    sort(val+1,val+1+m);
    for(int i=1;i<=m;i++)
    {
        // cout<<val[i]<<" ";
        val[i]+=val[i-1];
    }
    // cout<<"\n";
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dj(a,disa);
    dj(b,disb);
    dj(c,disc);
    int ans=INF,sum=0;
    for(int i=1;i<=n;i++)
    {
        // cout<<disa[i]<<" "<<disb[i]<<" "<<disc[i]<<"\n";
        if(disa[i]>m||disb[i]>m||disc[i]>m||disa[i]+disb[i]+disc[i]>m)continue;
        // sum=0;
        sum=2*val[disb[i]];
        sum+=val[disa[i]+disb[i]+disc[i]]-val[disb[i]];
        ans=min(ans,sum);
    }
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
    cin >> T;
    while(T--) solve();
    return 0;
}
