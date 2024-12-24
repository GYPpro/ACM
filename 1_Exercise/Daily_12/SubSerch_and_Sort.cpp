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
    int n,q;
    cin >> n >> q;
    map<int,vector<pii>> sct;
    auto pw = [&](auto x) {return x*x;};
    for(int i = 0;i < n;i  ++)
    {
        int x,y;
        cin >> x >> y;
        sct[pw(x)+pw(y)].push_back({x,y});
    }
    for(auto &[k,v]:sct) sort(all(v));
    while(q--){
        int x,y;
        cin >> x >> y;
        if(sct.find(pw(x)+pw(y)) != sct.end()){
            auto [tx,ty] = sct[pw(x)+pw(y)].front();
            cout << tx << " " <<ty << "\n";
        } else cout << "-1 -1\n";
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
