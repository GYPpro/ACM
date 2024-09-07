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
const int INF = 10000000000LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n,m,l;
    cin >> n >> m >> l;

    vector<vector<int>> tr = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    vector<vector<int>> ali(n+1,vector<int>(m+1));
    vector<vector<int>> mtx(n+1,vector<int>(m+1,INF));
    pii f;
    lop(i,0,l)
    {
        int u,v;
        cin >> u >> v;
        mtx[u][v] = -i;
        ali[u][v] = -i;
        if(i == 0) f.fi = u,f.se = v;
    }
    lop(i,0,n)
        lop(j,0,m)
        {
            char c;
            cin >> c;
            // cin >> ali[i+1][j+1];
            ali[i+1][j+1] = c == '.'?ali[i+1][j+1]:1;
        }

    auto flat = [&](pii a) -> bool {
        if(a.fi <= 0 || a.fi > n) return 0;
        if(a.se <= 0 || a.se > m) return 0;
        return ali[a.fi][a.se] != 1;
    };

    using pwi = pair<int,pii>;
    // priority_queue<pwi,vector<pwi>,greater<pwi>> q;
    multiset<pwi> q;
    vector<vector<int>> LOCK(n+1,vector<int>(m+1));
    // lop(i,1,n+1){
    //     lop(j,1,m+1)
    //         cout << ali[i][j] << " ";
    //         cout << "\n";}
    q.insert({0,f});
    while(q.size())
    {
        auto [_,cur] = *q.begin();
        q.erase(q.begin());
        // q.pop();
        // if(LOCK[cur.fi][cur.se]) continue;
        // LOCK[cur.fi][cur.se] = 1;
        lop(i,0,4)
        {
            pii n = {cur.fi + tr[i][0],cur.se + tr[i][1]};
            if(!flat(n)) continue;
            if(LOCK[n.fi][n.se]) continue;
            LOCK[n.fi][n.se] = 1;
            if(ali[n.fi][n.se] < 0) {
                // q.erase({mtx[n.fi][n.se],n});
                
                if(mtx[n.fi][n.se] > mtx[cur.fi][cur.se] + 1 || mtx[n.fi][n.se] < 0) {
                    q.erase({mtx[n.fi][n.se],n});
                    mtx[n.fi][n.se] = mtx[cur.fi][cur.se] + 1;
                    mtx[n.fi][n.se] = max(l + ali[n.fi][n.se],mtx[n.fi][n.se]);
                    q.insert({mtx[n.fi][n.se],n});
                }
            } else {
                if(mtx[n.fi][n.se] > mtx[cur.fi][cur.se] + 1) {
                    q.erase({mtx[n.fi][n.se],n});
                    mtx[n.fi][n.se] = mtx[cur.fi][cur.se] + 1;
                    q.insert({mtx[n.fi][n.se],n});
                }
            }
        }
    }
    lop(i,1,n+1)
        lop(j,1,m+1)
            if(mtx[i][j] >= INF) mtx[i][j] = 0;
    using ull = unsigned long long;
    ull ans = 0;
    lop(i,1,n+1)
        lop(j,1,m+1)
            ans += (ull)((ull) mtx[i][j] * (ull)mtx[i][j]);
    // lop(i,1,n+1){
    //     lop(j,1,m+1)
    //         cout << mtx[i][j] << " ";
    //         cout << "\n";}
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
