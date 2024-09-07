#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
#define ll long long
#define int long long
#define lc p<<1
#define rc p<<1|1

struct node{
    int l,r,big=0,sma=0,ge=0,eq=0;
}tr[4*N];
void pushup(int p){
    tr[p].sma=tr[lc].sma+tr[rc].sma;
    tr[p].big=tr[lc].big+tr[rc].big;
    tr[p].ge=tr[lc].ge+tr[rc].ge;
}
void build(int p,int l,int r){
    tr[p].r=r;tr[p].l=l;
    if(l==r){
        tr[p].big=tr[p].ge=tr[p].sma=0;
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
    
}

void update_mi(int p,int x,int k){
    if(tr[p].l==tr[p].r){
        tr[p].sma+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update_mi(lc,x,k);
    else update_mi(rc,x,k);
    pushup(p);
}
void update_mx(int p,int x,int k){
    if(tr[p].l==tr[p].r){
        tr[p].big+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update_mx(lc,x,k);
    else update_mx(rc,x,k);
    pushup(p);
}
void update_ge(int p,int x,int k){
    if(tr[p].l==tr[p].r){
        tr[p].ge+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update_ge(lc,x,k);
    else update_ge(rc,x,k);
    pushup(p);
}
void update_eq(int p,int x,int k){
    if(tr[p].l==tr[p].r){
        tr[p].eq+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update_eq(lc,x,k);
    else update_eq(rc,x,k);
    pushup(p);
}
int query_mi(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].sma;
    }
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(l<=m) sum+=query_mi(lc,l,r);
    if(m<r) sum+=query_mi(rc,l,r);
    return sum;
}
int query_mx(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].big;
    }
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(l<=m) sum+=query_mx(lc,l,r);
    if(m<r) sum+=query_mx(rc,l,r);
    return sum;
}
int query_ge(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].ge;
    }
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(l<=m) sum+=query_ge(lc,l,r);
    if(m<r) sum+=query_ge(rc,l,r);
    return sum;
}
int query_eq(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].eq;
    }
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(l<=m) sum+=query_eq(lc,l,r);
    if(m<r) sum+=query_eq(rc,l,r);
    return sum;
}
void solve(){
	int n;
    cin>>n;
    build(1,1,N);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=query_mi(1,1,a[i]);
        ans+=query_mx(1,a[i],N);
        ans-=query_eq(1,a[i],a[i]);
        int ge_big=query_ge(1,a[i],N);
        int ge_sma=query_ge(1,1,a[i]);
        int eq=query_ge(1,a[i],a[i]);
        update_ge(1,a[i],1);
        update_eq(1,a[i],eq);
        update_mi(1,a[i],ge_sma);
        update_mx(1,a[i],ge_big);
//         cout<<ge_big<<" "<<ge_sma<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}