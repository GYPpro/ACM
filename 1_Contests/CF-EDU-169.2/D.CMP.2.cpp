#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =2e5+100;
const int mod=998244353;

void solve(){
	int n,q;cin>>n>>q;
	vector<string> v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i];
	vector<vector<int>> a(50,vector<int> (n+1)),b(50,vector<int>(n+2,n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<50;j++){
			a[j][i]=a[j][i-1];
		}
		a[v[i][0]-'A'+v[i][1]-'A'][i]=i;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<50;j++){
			b[j][i]=b[j][i+1];
		}
		b[v[i][0]-'A'+v[i][1]-'A'][i]=i;
	}
	vector<int> c(4);
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		if(v[l][0]==v[r][0]||v[l][0]==v[r][1]||v[l][1]==v[r][0]||v[l][1]==v[r][1]){
			cout<<r-l<<"\n";continue;
		}
		int cnt=0;
		for(int i=0;i<2;i++){  
			c[cnt++]=v[l][i]+v[r][i]-2*'A';
			c[cnt++]=v[l][i]+v[r][i^1]-2*'A';
		}
		int ans=1e9;
		for(int i=0;i<4;i++){
			if(b[c[i]][l]<r){
				cout<<r-l<<"\n";continue;
			}
			int cur=1e9;
			if(b[c[i]][r]!=n+1){
				cur=min(cur,r-l+(b[c[i]][r]-r)*2);
			}
			if(a[c[i]][l]!=0){
				cur=min(cur,r-l+(l-a[c[i]][l])*2);
			}
			ans=min(ans,cur);
		}
		if(ans==1e9) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	return;
}
signed main(){
    freopen("1.in","r",stdin);
    freopen("1.b.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}