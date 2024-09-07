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


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> mtx(n);
    lop(i,0,n)
    {
        cin >> mtx[i];
        for(auto &x:mtx[i]) x = x-'0';
    }
    
    lop(j,0,m/2+1){
        int cnt = 0;
        lop(i,0,n)
        {
            if(mtx[i][j] + mtx[i][m-j-1]) cnt ++;
        }
        if(cnt >= 3) {cout << 0 << "\n";return;}
    }

    vector<set<int>> cnj(n*2+2);
    auto addedge = [&](int u,int v) -> void {
        cnj[u].insert(v);
        cnj[v].insert(u);
    };
    lop(i,0,m)
        lop(f,0,n)
        {
            if(mtx[f][i]) 
            {
                lop(e,f+1,n){
                    if(mtx[e][i]) 
                        addedge(e+n,f),addedge(f+n,e);
                    if(mtx[e][m-i-1]) 
                        addedge(e,f),addedge(e+n,f+n);
                }
            }
        }
    vector<int> vst(n*2+2);
    int cnt = 0;
    function<void(int)> dfs = [&](int p) -> void {
        if(vst[p]) return;
        vst[p] = cnt;
        for(auto x:cnj[p]) dfs(x);
    };

    lop(i,0,n*2+1) if(vst[i] == 0) cnt++,dfs(i);
    // for(auto x:cnj)

    // lop(i,0,n*2+1)
    //     for(auto x:cnj[i]) cout << i << " " << x << "\n";
    // for(auto x:vst)cout << x << " ";cout << "\n";

    lop(i,0,n) if(vst[i] == vst[i+n]) {cout << "0\n";return;}
    
    // cout << (1<<cnt) << "\n";
    int t = 1;
    int mod = 1e9+7;
    // cout << cnt << "\n";
    cnt /= 2;
    // cnt --;
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
