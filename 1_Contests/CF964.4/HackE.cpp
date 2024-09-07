#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define ll long long
#define int long long

vector<int> a(N);
void solve(){
	int l,r;
	cin>>l>>r;
	int ans=0;
	int x=l;
	while(x){
		x/=3;
		ans++;
	}
	ans*=2;
	for(int i=l+1;i<=r;i++){
		ans+=a[i];
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	for(int i=1;i<N;i++){
		int x=i;
		while(x){
			x/=3;
			a[i]++;
		}
	}
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}