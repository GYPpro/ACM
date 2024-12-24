#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;
const int mod = 998244353;
using ld = long double;

ld EPS = 1e-12;

int sign(ld a) {
	if(fabs(a) <= EPS) return 0;
	else if(a > 0) return 1;
	else return -1;
}

void solve(){
	int n;
	cin>>n;
	int tag=0;
	int f=0;
	int sum=0;
	int have=0;
	for(int i = 0; i < n;i ++)
	{
		int x;
		cin>>x;
		sum+=x;
		if(sum>0) f=1;
		else if(sum<0) f=-1;
		else if(have==0) f=0;
		else f=tag;
		if(f==1) cout<<"+";
		else if(f==0) cout<<"0";
		else cout<<"-";
		if(abs(sum)%2==1){
			have==1;
			if(sum<0) tag=-1;
			else tag=1;
		}
		sum=(sum)/2; 
//		int t;
//		cin >> t;
//		prv /= 2;
//		prv += t;
//		if(sign(prv) == 0) cout << "0";
//		else if(sign(prv) == -1) cout << "-";
//		else cout << "+";
	}
	cout << endl;
	return;
} 

//
//1.5
//0.75 -8
//-7.25
//-3.125

signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
// 	cin >> t;
	while(t--) solve();
	return 0;
}
/*

1
5
1 3 2 3 2
*/