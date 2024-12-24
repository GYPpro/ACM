#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int mod=998244353;
vector<vector<vector<ll>>>dp(110,vector<vector<ll>>(110,vector<ll>(110,0)));
void solve()
{
	for(int i=0;i<=101;i++)
	{
		for(int j=0;j<=101;j++)
		{
			for(int k=0;k<=101;k++)
			{
				if(j>k)dp[i][j][k]=1;
			}
		}
	}
	string s,t;
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	s=' '+s;
	t=' '+t;
	for(int i=1;i<=n;i++)
	{
		for(int len=1;len<=m;len++)
		{
			for(int l=1;l+len-1<=m;l++)
			{
				int r=l+len-1;
				dp[i][l][r]+=2*dp[i-1][l][r]%mod;
				dp[i][l][r]%=mod;
				for(int mid=l;mid<r;mid++)
				{
					dp[i][l][r]+=dp[i-1][l][mid]*dp[i-1][mid+1][r]%mod;
					dp[i][l][r]%=mod;
				}
				for(int mid=l;mid<=r;mid++)
				{
					if(t[mid]==s[i])
					{
						dp[i][l][r]+=dp[i-1][l][mid-1]*dp[i-1][mid+1][r]%mod;
						dp[i][l][r]%=mod;
					}
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cout<<dp[i][j][k]<<" \n"[k==m];
			}
		}
		cout<<'\n';
	}*/
	cout<<dp[n][1][m]<<'\n';
	return;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("1.in")
	int t=1;
	//init();
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
