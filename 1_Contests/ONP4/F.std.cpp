#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1 
const int N=1e5+100,M=1e5+10;
struct node{
	int l,r,sum=0;
}tr[N*4];
void pushup(int p){
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void build(int p,int l,int r){
	tr[p].l=l;tr[p].r=r;
	if(l==r){
		tr[p].sum=0;
		return;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void update(int p,int x){
	if(tr[p].l==tr[p].r){
		tr[p].sum++;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x);
	else update(rc,x);
	pushup(p);
}
int query(int p,int l,int r){
	if(l<=tr[p].l&&tr[p].r<=r) return tr[p].sum;
	int sum=0;
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) sum+=query(lc,l,r);
	if(m<r) sum+=query(rc,l,r);
	return sum;
}
void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]++;
		mx=max(mx,a[i]);
	}
	build(1,1,mx);
	int q;
	cin>>q;
	int cur=0;
	for(int i=n;i>=1;i--){
		if(a[i]!=1) cur+=query(1,1,a[i]-1);
		update(1,a[i]);
	}
	int ans=cur;
	while(q--){
//		cout<<cur<<"\n";
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		for(int i=x+1;i<y;i++){
			cur-=a[y]<a[i];
			cur-=a[x]>a[i];
		}
		cur-=a[x]>a[y];
		swap(a[x],a[y]);
		for(int i=x+1;i<y;i++){
			cur+=a[y]<a[i];
			cur+=a[x]>a[i];
		}
		
		cur+=a[x]>a[y];
		ans=min(ans,cur);
//		cout<<cur<<"\n";
	}
	cout<<ans<<"\n";
	return;
}

signed main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	    #ifdef FC
        freopen("F.A.in","r",stdin);
        freopen("F.A.std","w",stdout);
    #endif

	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}