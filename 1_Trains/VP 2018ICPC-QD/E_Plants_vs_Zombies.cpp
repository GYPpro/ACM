#include <bits/stdc++.h>
#define inf 1e18
#define ll long long
#define F(i, a, b) for(int i = a; i <= b ; i++) 
#define sf scanf
#define pf printf 
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define open(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
#define M 1000010
// #define M 101
using namespace std;


int T, n,m, len,a[M], d[M];


int check(int def) {

	int remain = m;
	F(now, 1, n) {
		// walk a step to now point
		remain--;
		d[now] += a[now];
		if(d[now] < def) {
			
			int cnt = (def - d[now]) % a[now] == 0? (def-d[now])/a[now] : (def-d[now])/a[now] +1;
			
			remain -= cnt * 2;
			if(remain < 0) return 0;
			d[now + 1] += a[now + 1] * (cnt);
			if(now + 1 == n && d[now + 1] >= def) return 1; 
		}
	}
	
	return remain >= 0;
}

signed main() {
	//open("E");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

	cin >> T;
	while(T--) {
		cin >> n >> m;
		int tmp = 0, ans = 0;
		F(i,1, n) cin >> a[i];
		F(i, 1, n)tmp = max(tmp, a[i]);
		
		int l = 0, r = tmp * m, mid = (l + r) >> 1;
		while(l<r){
			mid = (l+r)>>1;
			F(i,1,n)d[i]=0;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}
				 else r = mid-1;
		}
		F(i,1,n)d[i]=0;
		if(check(l)) ans = max(ans, l);
		cout << ans << "\n";
	}
	return 0;
} 
