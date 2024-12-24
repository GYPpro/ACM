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
const int N=1e5+7;
int fa[N][20];
int low[N],dfn[N],cnt=0,dis[N];
vector<int> dv[N],e[N];
void dfs(int u,int f)
{
    dis[u]=dis[f]+1;
    low[u]=dfn[u]=++cnt;
    dv[dis[u]].pb(cnt);
    for(int i=1;i<=19;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto v:e[u])
    {
        dfs(v,u);
        low[u]=max(low[u],low[v]);
    }
}
void solve()
{
    int n;
    cin>>n;
    cnt=0;
    for(int i=0;i<=n;i++)
    {
        fa[i][0]=0;
        low[i]=dfn[i]=dis[i]=0;
        dv[i].clear();
        e[i].clear();
        for(int j=1;j<=19;j++)
        {
            fa[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>fa[i][0];
        e[fa[i][0]].pb(i);
    }
    dfs(0,0);
    int q;
    cin>>q;
    while(q--)
    {
        int v,p;
        cin>>v>>p;
        int f=v;
        for(int i=19;i>=0;i--)
        {
            int d=((int)1<<i);
            if(p>=d)
            {
                f=fa[f][i];
                p-=d;
            }
        }
        if(f==0)
        {
            cout<<0<<" ";
            continue;
        }
        int tl=0,tr=dv[dis[v]].size()-1;
        int l=0,r=tr,mid=(l+r)>>1;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(dv[dis[v]][mid]<dfn[f])l=mid+1;
            else r=mid;
        }
        tl=l;
        l=0,r=tr;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(dv[dis[v]][mid]>low[f])r=mid-1;
            else l=mid;
        }
        tr=l;
        int ans=tr-tl;
        cout<<ans<<" ";
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
