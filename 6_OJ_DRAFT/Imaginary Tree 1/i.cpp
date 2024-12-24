#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int mod=998244353;
mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>>a(n+1);
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<int>maxdep(n+1),maxdep1(n+1),dep(n+1);
	vector<int>big(n+1);
	vector<vector<int>>fa(n+1,vector<int>(21,0));
	auto dfs=[&](auto &&self,int x,int f)->void
	{
		dep[x]=dep[f]+1;
		fa[x][0]=f;
		for(int i=1;i<=20;i++)
		{
			fa[x][i]=fa[fa[x][i-1]][i-1];
		}
		if(a[x].size()==1&&x!=1)
		{
			return;
		}
		int mx=0,mx1=0;
		int cnt=0;
		for(auto y:a[x])
		{
			if(y==f)continue;
			self(self,y,x);
			cnt++;
			if(maxdep[y]>=mx)
			{
				mx1=mx;
				mx=maxdep[y];
				big[x]=y;
			}
			else if(maxdep[y]>=mx1)
			{
				mx1=maxdep[y];
			}
		}
		if(cnt>=2)
		{
			maxdep[x]=mx+1;
		    maxdep1[x]=mx1+1;
		}
		else
		{
			maxdep[x]=mx+1;
		}
		
	};
	dfs(dfs,1,0);
	auto lca=[&](int x,int y)->int
	{
		if(dep[x]>dep[y])swap(x,y);
		for(int i=20;i>=0;i--)
		{
			if(dep[fa[y][i]]>=dep[x])y=fa[y][i];
		}
		if(x==y)return x;
		for(int i=20;i>=0;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	};
	vector<int>dp(n+1);
	auto dfs1=[&](auto self,int x,int f)->void
	{
		if(x!=1)
		{
			if(big[f]==x)
			{
				dp[x]=max(dp[x],1+max(dp[f],maxdep1[f]));
			}
			else
			{
				dp[x]=max(dp[x],1+max(dp[f],maxdep[f]));
			}
		}
		for(auto y:a[x])
		{
			if(y==f)continue;
			self(self,y,x);
		}
		return;
	};
	dfs1(dfs1,1,0);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int p=lca(x,y);
		if(p!=y)
		{
			cout<<dep[x]+dep[y]-2*dep[p]+maxdep[y]<<'\n';
		}
		else
		{
			int ans=0;
			if(lca(big[y],x)==big[y])
			{
				ans=max(ans,dep[x]+dep[y]-2*dep[p]+maxdep1[y]);
			}
			else
			{
				ans=max(ans,dep[x]+dep[y]-2*dep[p]+maxdep[y]);
			}
			ans=max(ans,dep[x]+dep[y]-2*dep[p]+dp[y]);
			cout<<ans<<'\n';
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}