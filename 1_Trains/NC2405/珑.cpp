    #include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(m>n) swap(n,m);
    if((n*m)%2==1){
        cout<<"No\n";
        return;
    }
    if(m == 1 && n == 2) {
        cout << "Yes\n";
        return;
    }
    if(a==0&&b==0){
        if(n==1&&m==2) cout<<"Yes\n";
        else if(n==2&&m==1) cout<<"Yes\n";
        else cout<<"No\n";
//         return;
    }
    if(a==1&&b==1){
        cout<<"Yes\n";
//         return ;
    }
    if(a==0&&b==1){
        if(n==1||m==1) cout<<"No\n";
        else cout<<"Yes\n";
    }
    if(a==1&&b==0){
        if((n==1&&m%2==0)||(m==1&&n%2==0)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
// 2 2 3 3
// 100 5 6