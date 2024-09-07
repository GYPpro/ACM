#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define ll long long
#define int long long

vector<int> e[N];
vector<int> d(N);
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
vector<int> sz(N);
int n;
vector<int> tsz(N),lsz(N),tdp(N),ldp(N);
// vector<int> pa1(N),pa2(N);
void init(int id,int fa){
	sz[id]=1;
	for(auto x:e[id]){
		if(x==fa) continue;
		init(x,id);
		sz[id]+=sz[x];
	}

}
void init2(int id,int fa){
	for(auto x:e[id]){
		if(x==fa) continue;
		init2(x,id);
	}
	if(d[id]==2){
		tsz[id]=n-sz[id];
		if(e[id][0]!=fa) lsz[id]=sz[e[id][0]];
		else lsz[id]=sz[e[id][1]];
	}
}
int tmp=0,mx=0;
void dfs(int id,int fa,int dep){
	for(auto x:e[id]){
		if(x==fa) continue;
		dfs(x,id,dep+1);
	}
	if(dep>mx){
		mx=dep;
		tmp=id;
	}
}
vector<int> dp(N);
void dfs1(int id,int fa){
	dp[id]=d[id]-1;
	for(auto x:e[id]){
		if(x==fa) continue;
		dfs1(x,id);
		dp[id]=max(dp[id],dp[x]);
		for(auto y:e[x]){
			if(y==id) continue;
			dp[x]=max(dp[x],d[y]);
		}
	}
	if(d[id]==2){
		if(e[id][0]!=fa) ldp[id]=dp[e[id][0]];
		else ldp[id]=dp[e[id][1]];
	}
}
void dfs2(int id,int fa){
	dp[id]=d[id]-1;
	for(auto x:e[id]){
		if(x==fa) continue;
		dfs2(x,id);
		dp[id]=max(dp[id],dp[x]);
		for(auto y:e[x]){
			if(y==id) continue;
			dp[x]=max(dp[x],d[y]);
		}
	}
	if(d[id]==2){
		if(e[id][0]!=fa) tdp[id]=dp[e[id][0]];
		else tdp[id]=dp[e[id][1]];
	}
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		e[i].clear();
		d[i]=0;
	}
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++;d[v]++;
	}
	int t1,t2;
	mx=0;
	dfs(1,0,1);
	t1=tmp;
	mx=0;
	dfs(t1,0,1);
	t2=tmp;

    cout << t1 << " " << t2 << "\n";

	init(t1,0);
	init2(t1,0);
	// dfs1(t1,0);
	// dfs2(t2,0);
	
//	cout<<tsz[4]<<" "<<tdp[4]<<"\n";
//	cout<<lsz[4]<<" "<<ldp[4]<<"\n";
    vector<int> DHNODES;
    map<int,int> cnt;
    int cntflag = 0;
    for(int i = 1;i <= n;i ++) cnt[e[i].size()] ++;
    for(int i = 3;i <= n;i ++) cntflag += cnt[i];
    if(cntflag > 2){
        printf("No");
        return;
    }
    // vector<int> jnLis;
    // jnLis.push_back(e[t1].back());
    // jnLis.push_back(e[t2].back());
    cout << e[t1].back() << " " << e[t2].back() << "\n";
    if(e[t1].back() == e[t2].back()){
        cout << e[e[t1].back()].size() << "\n";
        if(e[e[t1].back()].size() > 2) {printf("No");return;}
    }
    for(auto x:e[e[t1].back()]) DHNODES.push_back(x);
    // if(DHNODES.size() == n-1) {printf("No");return;}
    for(auto x:e[e[t2].back()]) DHNODES.push_back(x);
    if(DHNODES.size() >= n-2)printf("Yes");
	// for(int i=1;i<=n;i++){
	// 	if(d[i]!=2) continue;
	// 	if(tsz[i]==tdp[i]+1&&lsz[i]==ldp[i]+1){
	// 		printf("Yes");
	// 		return;
	// 	}
	// }
	else printf("No");
	return;
}


signed main(){
//	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=read();
	while(t--){
		solve();
		if(t!=0) printf("\n");
	}
	return 0;
}