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
    int n;
    cin >> n;
    vector<set<int>> cnj(n+1),rev(n+1);
    vector<int> nxt(n+1);
    set<int> unr,withrev;
    for(int i = 0;i < n;i ++) unr.insert(i+1);
    for(int i = 1;i <= n;i ++){
        int v = 0;
        cin >> v;
        nxt[i] = v;
        cnj[i].insert(v);
        rev[v].insert(i);
        unr.erase(v);
        withrev.insert(v);
    }
    int steps = 0;
    set<int> nex;
    map<int,int> mxc;
    while(unr.size()){
        nex.clear();
        mxc.clear();
        for(auto x:unr){
            if(rev[nxt[x]].size() > 1){
                rev[nxt[x]].erase(x);
                mxc[nxt[x]] ++;
            } else {
                rev[nxt[x]].erase(x);
                nex.insert(nxt[x]);
            }
        }

        unr = nex;
        int dev = 0;
        for(auto [k,v]:mxc) dev = max(dev,v);
        steps += dev+1;
    }
    cout << steps + 2 << "\n";
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
    while(T--) solve();
    return 0;
}
