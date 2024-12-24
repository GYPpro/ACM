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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mtx(m+1,vector<int>(n+1)); //[m][n](n:permu)
    lop(i,0,m)
        lop(j,1,n+1)
            cin >> mtx[i][j];
    vector<int> ans(n+1);
    vector<int> curvst(n+1);
    vector<int> stdr;
    vector<int> newly;
    vector<int> ptrs(m,1);
    vector<vector<char>> vst(m+1,vector<char>(n+1));
    int curct = n-1;
    int cur;
    auto pushto = [&](int x) -> void {
        lop(i,0,m)
        {
            while(!vst[i][x]) {
                cur = mtx[i][ptrs[i]];
                if(curvst[cur] == 0) newly.pb(cur),curvst[cur] = 1;
                vst[i][cur] = 1;
                ptrs[i] ++;
            }
        }
    };
    while(curct > 0)
    {
        int ctr = 0;
        lop(i,0,m) {
            cur = mtx[i][ptrs[i]];
            if(!curvst[cur]) stdr.pb(cur),curvst[cur] = 1,ctr ++;
        }
        do{
            newly.clear();
            for(auto x:stdr) ans[x] = curct;
            for(auto x:stdr) pushto(x);
            stdr = newly;
            // curct -= newly.size();
            ctr += newly.size();
        }while(newly.size() != 0);
        curct -= ctr;
    }
    lop(i,1,n+1) cout << ans[i] << " ";cout << "\n";
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
