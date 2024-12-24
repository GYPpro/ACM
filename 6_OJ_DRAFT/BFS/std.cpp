#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1010;

pair<int,int> have[N][N];
int vis[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void solve()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=-1;
            have[i][j]={-1,-1};
        }
    }
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;y1--;x2--;y2--;
    int k;cin>>k;
    while(k--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        have[a][b]={c,d};
    }
    queue<pair<int,int>> q;
    q.push({x1,y1});
    vis[x1][y1]=0;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;q.pop();
        if(have[x][y].first!=-1){
            int nx=have[x][y].first,ny=have[x][y].second;
            if(vis[nx][ny]==-1){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
        if(s[x][y]=='#') continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]!=-1) continue;
            vis[nx][ny]=vis[x][y]+1;
            q.push({nx,ny});
        }
    }
    cout<<vis[x2][y2]<<"\n";
	return;
}
signed main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        freopen("temp.in","r",stdin);
    freopen("temp.out","w",stdout);
	int t=1;
	// cin>>t;
	while(t--) solve();
    return 0;
}
