// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

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

vector<int> fa;
int find(int x){
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> mtx(n);
    
    lop(i,0,n)
    {
        cin >> mtx[i];
        for(auto &x:mtx[i]){
            x = x-'0';
        }
    }
    
    lop(j,0,m/2+1){
        int cnt = 0;
        lop(i,0,n)
        {
            if(mtx[i][j] || mtx[i][m-j-1]) cnt ++;
        }
        if(cnt >= 3) {cout << 0 << "\n";return;}
    }
    set<int> st[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mtx[i][j]==1) st[j].insert(i);
        }
    }
    fa.resize(n*2+1);
    iota(fa.begin(),fa.end(),0);
    // vector<int> b(n,-1);
    // for(int i=0;i<m;i++){
    //     for(auto x:st[i]){
    //         for(auto y:st[i]){
    //             if(y==x) continue;
    //             if(find(x)==find(y)){
    //                 cout<<"0\n";
    //                 return;
    //             }
    //             if(b[y]==-1) b[y]=x;
    //             else{
    //             1    fa[find(x)]=find(b[y]);
    //             }if(b[x]==-1) b[x]=y;
    //             else fa[find(y)]=find(b[x]);
    //         }
    //         for(auto y:st[m-i-1]) fa[find(y)]=find(x);
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(b[i]==-1) continue;
    //     if(find(i)==find(b[i])){
    //         cout<<"0\n";
    //         return;
    //     }
    // }
    vector<int> e[2*n+1];
    for(int i=0;i<m;i++){
        for(auto x:st[i]){
            for(auto y:st[i]){
                if(x==y) continue;
                e[x].push_back(y+n);
                e[y+n].push_back(x);
                e[y].push_back(x+n);
                e[x+n].push_back(y);
            }
            for(auto y:st[m-i-1]){
                if(y==x) continue;
                e[x].push_back(y);
                e[y].push_back(x);
                e[x+n].push_back(y+n);
                e[y+n].push_back(x+n);
            }
        }
    }
    vector<int> vis(2*n+1);
    function<void(int,int)> dfs11=[&](int id,int u){
        vis[id]=1;
        fa[id]=u;
        for(auto x:e[id]){
            if(vis[x]==1) continue;
            dfs11(x,id);
        }
    };
    int cnt=0;
    for(int i=0;i<n*2;i++){
        if(!vis[i]) dfs11(i,i),cnt++;
    }
    cnt/=2;
    for(int i=0;i<n;i++){
        if(find(i)==find(i+n)){
            cout<<"0\n";
            return;
        }
    }
    int t = 1;
    int mod = 1e9+7;         
    while(cnt)
    {
        t *= 2;
        t %=mod;
        cnt --;
    }
    cout << t << "\n";
}  

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
