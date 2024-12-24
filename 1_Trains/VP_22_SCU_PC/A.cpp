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
// map<int,int> prime;
vector<int> prils;
set<int> pri;
void eular(int n)
{
    vector<bool> vis(n+1,0);
    for(int i = 2;i <= n;i ++)
    {
        if(!vis[i]) prils.pb(i);
        for(int j = 0;j <  prils.size();j ++) {
            if(i * prils[j] > n) break;
            vis[prils[j] * i] = 1;
            if(i%prils[j] == 0) break;
        }
    }
    for(auto x:prils) pri.insert(x);
}
// vector<pair<int,int>> ans;
// void solve()
void solve(int n)
{
    // int n;
    // cin>>n;
    vector<pii> anss;
    auto ita = [&](int k) -> int {
        int p = *pri.upper_bound(k);
        int s = p-k;
        lop(i,0,((k-s)>>1)+1) anss.pb({s+i,k-i});
        return s-1;
    };
    int p = n*2;
    while((p = ita(p)) > 1){;}
    // if(anss.size() == n) for(auto [u,v]:anss) cout << u << " " << v << "\n";
    if(anss.size() == n) ;
    else cout << n <<  ":-1\n";
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
    cin >> T;
    
    eular(2e5);
    
    // while(T--) solve();
    lop(i,1e3,T+1) solve(i);
    system("pause");
    return 0;
}
