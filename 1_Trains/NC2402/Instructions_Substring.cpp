#include <iostream>
#include <algorithm>
#define inf 1e9
#define ll long long
#define F(i, a, b) for(ll i = a; i <= b ; i++) 
#define mem(a,b) memset(a,b,sizeof(a))
// const ll N=2*1e5 + 20;
const ll N=20;
using namespace std;


ll n, x, y;

ll preLR[N], preUD[N];
string s;
#include<map>
map<pair<ll, ll>, ll> ma; 


signed main() {
	//open("E");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

	cin >> n >> x >> y; // stringlen, ups, rights 
	// start at left bottom 
	cin >> s;
	
	F(i, 0, n-1){
		if(s[i]=='W'){
			preUD[i + 1] += 1;
		} else
		if(s[i]=='S'){
			preUD[i + 1] -= 1;
		} else
		if(s[i]=='A'){
			preLR[i + 1] -= 1;
		} else
			preLR[i + 1] += 1;
	}
	
	F(i,1,n)preLR[i]+=preLR[i-1], preUD[i]+=preUD[i-1];
	
    // for(auto x:preUD) cout << x << " ";cout << "\n";
    // for(auto x:preLR) cout << x << " ";cout << "\n";

	if(x==0&&y==0) {
		cout << n*(n+1)/2 << "\n";
		return 0;
	}
	
	// select the point the exactly reach x,y
	ll ans = 0;
	// add pre[0] to map
	ma[{0, 0}]=1;
	F(i,1,n){
		// find j<i that pre__[i] - pre__[j] == x/y
		ma[{preUD[i], preLR[i]}]++;
		ans += ma[{preUD[i] - y, preLR[i] - x}] * (n-i+1);
        // // ma[{preUD[i] - y, preLR[i] - x}] = 0;
        // cout << i << " " << preUD[i] << " " << preLR[i] << "\n";
        // cout << i << " " << preUD[i] -y << " " << preLR[i] -x<< "\n";
	    cout << ans << "\n";
	}
	
	
	cout << ans << "\n";
	return 0;
} 