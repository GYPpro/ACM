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

vector<vector<int>> tr = { {1 , 0},
                           {-1, 0},
                           {0 , 1},
                           {0 ,-1} };

void solve()
{
    int n,m,l;
    cin >> n >> m >> l;
    vector<vector<int>> mtx(n+1,vector<int>(m+1,INF));
    vector<vector<int>> rec(n+1,vector<int>(m+1));
    vector<vector<int>> pol(n+1,vector<int>(m+1));
    vector<pii> sn;
    pii ini;
    lop(i,0,l)
    {
        int u,v;
        cin >> u >> v;
        sn.pb({u,v});
        rec[u][v] = l-i;
        if(i == 0) ini = {u,v};
    }
    lop(i,1,n+1) lop(j,1,m+1)
        {
            char c;
            cin >> c;
            pol[i][j] = c == '#'?0:1;
        }

    auto flat = [&](pii x) -> bool {
        if(x.fi <= 0 || x.fi > n) return 0;
        if(x.se <= 0 || x.se > m) return 0;
        return pol[x.fi][x.se];
    };

    using pwi = pair<int,pii>;
    // priority_queue<pwi,vector<pwi>,greater<pwi>> q;
    set<pwi> q;
    queue<pwi> mq;
    q.insert({0,ini});
    mtx[ini.fi][ini.se] = 0;
    mq.push(*q.begin());
    while(mq.size()+q.size())
    {
        pii cur;
        if( q.size() && mq.size() ) 
            if(q.begin()->first >= mq.front().first) {
                cur = mq.front().se;
                mq.pop();
            } else {
                cur = q.begin()->se;
                q.erase(q.begin());
            }
        else if (mq.size())
        {
            cur = mq.front().se;
            mq.pop();
        } else {
            cur = q.begin()->se;
            q.erase(q.begin());
        }
        lop(i,0,4)
        {
            int tu = cur.fi + tr[i][0],tv = cur.se + tr[i][1];
            if(!flat({tu,tv})) continue;
            if(rec[tu][tv])
                if( mtx[tu][tv] > max(mtx[cur.fi][cur.se] + 1 , rec[tu][tv]) )
                {
                    q.erase({mtx[tu][tv],{tu,tv}});
                    mtx[tu][tv] = max(mtx[cur.fi][cur.se] + 1 , rec[tu][tv]);
                    q.insert({mtx[tu][tv],{tu,tv}});
                } else "skiped";
            else if(mtx[tu][tv] > mtx[cur.fi][cur.se] + 1)
                {
                    mtx[tu][tv] = mtx[cur.fi][cur.se] + 1;
                    mq.push({mtx[tu][tv],{tu,tv}});
                } else "skiped";
        }
    }

    using ull = unsigned long long;
    ull ans = 0;
    lop(i,1,n+1)
        lop(j,1,m+1)
            if(mtx[i][j] >= INF) continue;
            else ans += (ull)mtx[i][j] * (ull)mtx[i][j];
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
