#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int INF=1e10;
const int N=3e5+100;
#pragma GCC optimize(2)
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
// const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}

vector<int> vv(N);
vector<int> fa(N),sz(N);
#define ord(u, v) {min(u ,v ),max(u ,v )}
#define pii pair<int,int>
int find(int x){
	return (fa[x]==x) ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x = find(x),y = find(y);
	if(x == y) return;
	if(sz[x] > sz[y]){
		sz[x] += sz[y];
		fa[x]=y;
	} else {
		sz[y] += sz[x];
		fa[y] = x;
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> st(m+1);//vector<deque<pii>> st[0]
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		st[i]=ord(u,v);
		vv[i]=-1;
	}
    if(n <= 500)
    {
        set<int> sts;
        map<pii,deque<int>> sta;
        lop(i,1,m+1) sta[st[i]].pb(i);
        // for(auto x:st) sts.insert(x);
        // lop(i,1,m+1) sts.insert(i); 
        for(auto x:sta) sts.insert(x.se.front());

        // int MEXN = n*(n-1)/2;
        // vector<deque<int>> rst(MEXN);
        // map<pii,int> uv2i;
        // lop(i,1,n+1)
        //     lop(j,i+1,n+1) uv2i[{i,j}] ++;
        // // for(auto x:st) 
        // lop(i,1,m+1) rst[uv2i[st[i]]].pb(i);
         // int mn = min(m,n*n-1);
        int tt=1;
        for(int o=1;;o++){
            for(int i=1;i<=n;i++) fa[i]=i;
            for(int i=1;i<=n;i++) sz[i]=1;
            int rmcnt = 0;
            vector<int> tbm;
            for(auto i : sts){
                // cout << "YES\n";
            // lop(i,1,m+1){
                if(vv[i]!=-1) continue;
                int u=st[i].first,v=st[i].second;
                if(find(u)==find(v)) continue;
                rmcnt ++;
                merge(u,v);vv[i]=o;
                // sts.erase(i);
                tbm.pb(i);
                if(rmcnt >= n-1) break;
            }
            for(auto x:tbm) sts.erase(x);
            for(auto x:tbm) sta[st[x]].pop_front();
            for(auto x:tbm) if(sta[st[x]].size()) sts.insert(sta[st[x]].front());
            int tmp=find(1);
            bool ok=0;
            for(int i=2;i<=n;i++){
                int cur=find(i);
                if(tmp!=cur){
                    ok=1;
                    break;
                }
            }
            if(ok==1) {
                tt=o;break;
            }
        }
        for(int i=1;i<=m;i++){
            if(vv[i]==tt) vv[i]=-1;
            cout<<vv[i]<<" \n"[i==m];
        }   
    } else {
	int tt=1;
	for(int o=1;;o++){
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++) sz[i]=1;
		for(int i=1;i<=m;i++){
                // cout << "YES\n";
			if(vv[i]!=-1) continue;
			int u=st[i].first,v=st[i].second;
			if(find(u)==find(v)) continue;
			merge(u,v);vv[i]=o;
		}
		int tmp=find(1);
		bool ok=0;
		for(int i=2;i<=n;i++){
			int cur=find(i);
			if(tmp!=cur){
				ok=1;
				break;
			}
		}
		if(ok==1) {
			tt=o;break;
		}
	}
	for(int i=1;i<=m;i++){
		if(vv[i]==tt) vv[i]=-1;
		cout<<vv[i]<<" \n"[i==m];
	}
	}return;
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}