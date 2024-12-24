// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> mtx(n,vector<int>(m));
    // for(auto &y:mtx) for(auto &x:y) cin >> x;
    for(int i = 0;i < n;i ++) 
        for(int j = 0;j < m;j ++)
            cin >> mtx[i][j];
    vector<vector<int>> ar2c(m);
    for(int i = 0;i < m;i ++){
        ar2c[i].push_back(mtx[0][i]);
        for(int c = 1;c < n;c ++) ar2c[i].push_back(ar2c[i].back() | mtx[c][i]);
    }
    
    // for(int i = 0;i < m;i ++){
    //     for(int j = 0;j < n ;j ++) cout << ar2c[i][j] << " ";
    //     cout << "\n";
    //     }
    while(q--)
    {
        int ttl;
        cin >> ttl;
        pii cur ={1,n};
        while(ttl --)
        {
            int r,c;
            char op;
            cin >> r >> op >> c;
            r --;
            pii newrg = {1,n};
            if(op == '<') {
                int idx = lower_bound(all(ar2c[r]),c) - ar2c[r].begin();
                newrg = {1,idx};
                // cout << "{1," << idx << "}\n";
            } else {
                int idx = upper_bound(all(ar2c[r]),c) - ar2c[r].begin()+1;
                newrg = {idx,n};
                // cout << "{" << idx << "," << n << "}\n";
            }
            cur.fi = max(cur.fi,newrg.fi);
            cur.se = min(cur.se,newrg.se);
        }
        if(cur.fi <= cur.se) cout  << cur.fi << "\n";
        else cout << "-1\n";
    }

}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
