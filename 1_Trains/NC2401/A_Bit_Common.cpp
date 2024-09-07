#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100,MAXN=5100;
#define int long long
#define ll long long
int MOD;
// long long fac[MAXN + 10], ifac[MAXN + 10];
vector<vector<int>> c(5005,vector<int>(5005));

long long C(int a, int b) {
    return c[a][b];
}
    

int ksm(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void solve(){
    int n,m;
    cin>>n>>m>>MOD;
    // fac[0] = 1;
    // for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    // 
    // ifac[0] = ifac[1] = 1;
    // int y;
    // for(int i=2;i<=n;i++) liEu(fac[i],MOD,1,ifac[i],y);
    // for(int i=0;i<=n;i++){
    //     ifac[i]=(ifac[i]%MOD+MOD)%MOD;
    // }
    //     for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
//     for (int i = 2; i <= n; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;
//     int cnt=1;
    int ans=0;
	for(int i=1;i<=n;i++){  //有i个
//         cnt=cnt*(n-i+1)%mod;
        int tmp=C(n,i)*ksm(ksm(2,m-1),n-i)%MOD;
        tmp=tmp*ksm(ksm(2,i)-1,m-1)%MOD;
        ans=(ans+tmp)%MOD;
    }
    cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;	
// 	cin>>t;
	while(t--) solve();
	return 0;
} 