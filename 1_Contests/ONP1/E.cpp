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

void er(multiset<int> &t,int v)
{
    int times = t.erase(v);
    times --;
    while(times--) t.insert(v);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mtx(n+1,vector<int>(m+1));
    // // map<int,vector<int>> pii
    // vector<array<int,3>> piq;
    lop(i,1,n+1)
        lop(j,1,m+1){
            cin >> mtx[i][j];
            // piq.push_back({mtx[i][j],i ,j});
        }
    vector<vector<pii>> col(m+1);
    lop(j,1,m+1)
        lop(i,1,n+1)
            col[j].pb({mtx[i][j],i});
    lop(j,1,m+1) sort(all(col[j])),reverse(col[j].begin()+1,col[j].end());
    //col:[m,n],n is sorted,pair[v,i]

    vector<int> idxs(m+1,1);
    set<int> cnt;
    auto check = [&]()
    {
        cnt.clear();
        lop(i,1,m+1)
        {
            int j = idxs[i];
            cnt.insert(col[i][j].se);
        }
        return cnt.size() == 2;
    };
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;//[v,i,j]
    lop(i,1,m+1) q.push({col[i][1].fi,i,1LL});
    while(!check() && q.size())
    {
        auto [v,i,j] = q.top();
        q.pop();
        if(j+1 > n) break;
        idxs[i] ++;
        j ++;
        q.push({col[i][j].fi,i,j});
    }
    if(check()) {
        cnt.clear();
        lop(i,1,m+1)
        {
            int j = idxs[i];
            cnt.insert(col[i][j].se);
        }
        cout << (*cnt.begin()) << " " << (*cnt.rbegin()) << "\n";
    } else {
        int mi = 0;
        int mx = 0;
        lop(i,1,n+1)
        {
            if(*min(mtx[i].begin()+1,mtx[i].end()) > mx) mx = *min(mtx[i].begin()+1,mtx[i].end()),mi = i;
        }
        cout << mi << " " << mi << "\n";
    }
    // sort(all(piq)),reverse(all(piq));
    // set<int> xlis,ylis;
    // // multiset<int> cel;
    // vector<pii> cel;
    // auto check = [&]() -> int {
    //     int mi = -INF;
    //     for(auto [i,j]:cel) mi = min(mtx[i][j],mi);
    //     if(xlis.size() == m && ylis.size() == 2) return mi;
    //     else return -1;
    // };
    // int idx = 0;
    
    // while(check() == -1)
    // {
    //     auto [v,i,j] = piq[idx];
        
    // }

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
