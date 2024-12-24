#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+100;


void solve()
{
	int n,qq,p;
	cin>>n>>qq>>p;
	vector<int> a(n+2),b;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	b=a;
	deque<int> q;
	vector<int> ans(n+1,-1e18);
	for(int i=1;i<=n;i++){
		if(i>p) break;
		while(!q.empty()) q.pop_back();
		q.push_back(n+1);
		int ls=n/i;ls*=i;
//		cout<<i<<" "<<ls<<"\n";
		for(int j=ls;j>=i;j-=i){
			while(!q.empty()&&q.front()-j+i>p) q.pop_front();
			while(!q.empty()&&a[q.back()]<=a[j]) q.pop_back();
			q.push_back(j);
			a[j-i]+=a[q.front()];
		}
//		for(int j=0;j<=n;j++) cout<<a[i]<<"\n";
//		ans[i]=a[0];
		for(int j=ls;j>=0;j-=i){
			if(j<=p) ans[i]=max(ans[i],a[j]);
			a[j]=b[j];
		}
	}
	
	while(qq--){
		int x;cin>>x;
		if(x>p) cout<<"Noob\n";
		else cout<<ans[x]<<"\n";
	}
}
/*


*/
signed main(){
        #ifdef FC
        freopen("C.A.in","r",stdin);
        freopen("C.A.std","w",stdout);
    #endif

	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
//	cin>>t;
	while(t--) solve(); 
    return 0;
}