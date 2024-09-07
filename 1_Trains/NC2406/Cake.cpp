#include<bits/stdc++.h>
using namespace std;
// const int N=2e5+100;
#define ll long long
#define int long long


void solve(){
    
	int n;
    cin>>n;
    int N = n+1;
    vector<vector<pair<int,int>>> e(N);
    vector<int> cnt1(N);
    vector<int> cnt0(N);
    vector<int> s(N);
    vector<double> ans(N);

    for(int i=0;i<=n;i++){ 
        e[i].clear();
        cnt0[i]=0;
        cnt1[i]=0;
    }
	for(int i=0;i<n-1;i++){
        int u,v,s;
        cin>>u>>v>>s;
        e[u].push_back({v,s});
        e[v].push_back({u,s});
        //
    }
    auto dfs = [&](auto self,int id,int fa,int f) -> void{  //f -> G    
        if(id==1) ans[id]=0;
        else ans[id]=(double)((double)(cnt1[id])/(double)(cnt0[id]+cnt1[id]));
        double son=1;
        if(f==1) son=0;
        bool ff=0;
        for(auto y:e[id]){
            int x=y.first,s=y.second;
            if(x==fa) continue;
            cnt1[x]+=cnt1[id]+(s==1);
            cnt0[x]+=cnt0[id]+(s==0);
            self(self,x,id,f^1);
            if(f==0){
                son=min(son,ans[x]);
            }
            else{
                son=max(son,ans[x]);
            }
            ff=1;
        }
        if(ff==0) return;
        if(f==1) ans[id]=son;
        else ans[id]=min(ans[id],son);
    };

    dfs(dfs,1,0,1);
//     ans[1]=1.0-ans[1];
    printf("%.12lf\n",ans[1]);
    return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}
