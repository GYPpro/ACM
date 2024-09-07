#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N= 2e5+100;

map<int,vector<int>> e;
// map<int,int> in;
map<int,int> vis,dp;
int mx,mxx,mxxx;
int dfs(int id,int fa){
    if(vis[id] == 1) return dp[id];
    int t = id;
	dp[id]=t;
    vis[id] = 1;
    
	int cnt=0;
	for(auto x:e[id]){
		if(x==fa) continue;
		cnt++;
		t=max(t,dfs(x,id));
	}
	mxxx=max(mxxx,id);
	if(cnt>1) mx=max(mx,t);
	if(cnt>0) mxx=max(mxx,id);
	// if(cnt>0) dp1[id]=t;
    return dp[id] = t;
}
void solve(){
	mx=-1,mxx=-1;
	int n,m;
	cin>>n>>m;
	dp.clear();
	// dp1.clear();
	e.clear();
	// in.clear();
	vis.clear();
	
	set<int> mp;
	for(int i=0;i<n;i++){
		int l;cin>>l;
		mp.clear();
		for(int j=0;j<l;j++){
			int x;cin>>x;mp.insert(x);
		}
		int u,v;bool f=0;
		for(int j=0;;j++){
			if(mp.find(j) == mp.end()){
				if(f==0){
					u=j;f=1;
				}
				else{
					v=j;break;
				}
			}
		}
		e[u].push_back(v);
		// in[v]++;
	}
	for(auto x:e){
		int u=x.first;
		if(vis[u]==1) continue;
		dfs(u,-1);
	}
    // if(n == 3485){ cout << "FSR\n";return;}
	int ans=0;
	for(int i=0;i<=min(mxxx,m);i++){
        ans+=max(mxx,max(mx,max(dp[i],i)));
	}
	if(m>mxxx) ans+=m*(m+1)/2-mxxx*(mxxx+1)/2;
	cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}//MarcosK