#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//using ord_setl = tree<int, null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update>;
#define int long long

#define lc p<<1
#define rc p<<1|1
const int N=3e5+10;
using i128 = __int128;
vector<i128> a(N);
i128 gcd(i128 x,i128 y){
	return y==0 ? x : gcd(y,x%y);
}
i128 max(i128 x,i128 y) {
	if(x > y) return x;
	else return y;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<i128> b(n+1);
    i128 g=0;
	for(int i=1;i<=n;i++){
    	// cin>>a[i];
		int t;
		cin >> t;
		a[i] = t;
    	b[i]=gcd(b[i-1],a[i]);
    	g=gcd(a[i],g);
	}
	if(k==0){
		cout<<(int)g<<"\n";
		return;
	}
	i128 ans=g;
	g = 0;
	for(int i = 1 ;i <= n;i ++){
        g = gcd(a[i]+k,g);
    }
    ans = max(ans,g);
	auto check=[&](__int128 x)->void {
		if(b[x]==1) return;
		i128 tmp=-1,tmpp=-1;
		for(int i=1;i<=n;i++){
//			cout<<a[i]%b[x]<<" ";
			if((a[i]%b[x])==0) continue;
			if(tmp==-1) tmp=i;
			tmpp=i;
		}
//		cout<<tmp<<" "<<tmpp<<"\n";
		if(tmp==-1) return;
		i128 g=0;
		for(int i=1;i<tmp;i++) g=gcd(a[i],g);
		for(int i=tmp;i<=tmpp;i++) g=gcd(a[i]+(__int128)k,g);
		for(int i=tmpp+1;i<=n;i++) g=gcd(a[i],g);
//		cout<<g<<"\n";
		ans=max(ans,g);
	};
	map<i128,int> mp;
	for(int i=1;i<=n;i++){
		if(mp[b[i]]>0) continue;
		mp[b[i]]=1;
//		cout<<i<<" :";
		check(i);
//		cout<<"\n";
	}
	mp.clear();
	b[n]=a[n];
	for(int i=n-1;i>=1;i--) b[i]=gcd(b[i+1],a[i]);
	for(int i=n;i>=1;i--){
	    if(mp[b[i]]>0) continue;
	    mp[b[i]]=1;
	    check(i);
	}
	cout<<(int)ans<<"\n";
}
/*
1
5 4 2
2 1 1 1 1
3 6 -1 -1 -1
3 1 1 1 2
3 4 -1 -1 -1
4 3 3 2 2

1
3 4 1
2 2 2 2 2
3 9 -1 -1 -1
3 -1 -1 -1 -1
*/
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}

