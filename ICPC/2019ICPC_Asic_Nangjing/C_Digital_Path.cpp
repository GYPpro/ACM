// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;
const int N=1010;

int mtx[1010][1010];
int cnt[1010][1010][4];
bool vis[1010][1010];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
const int mod=1e9+7;
void dfs(int x,int y){
    if(vis[x][y]==1) return;
    vis[x][y]=1;
    bool f=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m||mtx[x][y]!=mtx[nx][ny]-1) continue;
        // if(x==0&&y==0)
        f=1;
        dfs(nx,ny);
        cnt[x][y][0]+=cnt[nx][ny][3]+cnt[nx][ny][0];
        cnt[x][y][2]+=cnt[nx][ny][1];
        cnt[x][y][3]+=cnt[nx][ny][2];
        for(int j=0;j<4;j++) cnt[x][y][j]%=mod;
    }
    if(f==0) cnt[x][y][1]=1;
    return;
}
void solve()
{
    // int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mtx[i][j];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==1) continue;
            bool ok=1;
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(mtx[nx][ny]==mtx[i][j]-1) ok=0;
            }
            // cout<<i<<" "<<j<<" "<<ok<<"\n";
            if(ok==1){
                dfs(i,j);
                ans+=cnt[i][j][0];
                ans%=mod;
            }
        }
    }
    // for(int i=0;i<4;i++) cout<<cnt[1][3][i]<<" ";
    cout << ans << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
