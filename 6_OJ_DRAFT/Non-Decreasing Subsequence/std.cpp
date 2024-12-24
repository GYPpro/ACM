#include<bits/stdc++.h>
using namespace std;
#define int long long

// const int INF=1e18;

const int N=1E5+120;

#define lc p<<1
#define rc p<<1|1
struct node{
	int l,r,mx;
}tr[4*N];
void pushup(int p){
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
vector<int> v(N);
void build(int p,int l,int r){
	tr[p].l=l;tr[p].r=r;
	if(l==r){
		tr[p].mx=v[l];
		return;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
int query(int p,int l,int r){
	if(l<=tr[p].l&&tr[p].r<=r) return tr[p].mx;
	int m=tr[p].l+tr[p].r>>1;
	int mx=0;
	if(l<=m) mx=max(mx,query(lc,l,r));
	if(m<r) mx=max(mx,query(rc,l,r));
	return mx;
}
void solve(){
	int n,q;
	cin>>n>>q;
	string s;cin>>s;
	s=" "+s;
	vector<int> pre(n+1),suf(n+2);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='0');
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s[i]=='1');
	for(int i=1;i<=n;i++){
		if(s[i]=='1') v[i]=suf[i]+pre[i-1];
		else v[i]=pre[i]+suf[i+1];
	}
	build(1,1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(1,l,r)-pre[l-1]-suf[r+1]<<"\n";
	}
	return;
}

signed main() {
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("temp.in","r",stdin);
    freopen("temp.out","w",stdout);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}