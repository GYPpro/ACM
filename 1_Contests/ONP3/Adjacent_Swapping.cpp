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
    string s;
    cin >> s;
    s = " "+s;
    map<char,vector<int>> idxs;
    lop(i,1,n+1)
    {
        idxs[s[i]].pb(i);
    }
    int sum = 0;
    vector<pii> iuv;
    for(auto [ch,v]:idxs)
    {
        int step = v.size() >> 1;
        lop(i,0,step)
        {
            // sum += abs(abs(v[i+step]-v[i]) - (n/2));
            iuv.pb({v[i],v[i+step]});
        }
    }
    // cout << sum << "\n";
    // sort(all(iuv));
    // int exp = 1;
    // for(auto [u,v]:iuv) cout << u << " " << v << "\n";
    // int suml = 0,sumr = 0;
    // deque<int> prps;
    // int convexRG = 0;
    // for(auto &[u,v]:iuv)
    // {
    //     if(u > n/2) prps.push_back(u),suml += u,convexRG = max(convexRG,u);
    //     if(u != exp) u = exp;
    //     exp ++;
    //     // if(u > n/2) suml += u,u -= n/2;
    //     // if(v <= n/2) sumr += v,v += n/2;
    // }
    // sort(all(iuv),[](pii a,pii b) {return a.se < b.se;});
    // // sort(all(prps));rev
    // cout << "--------\n";
    // for(auto [u,v]:iuv) cout << u << " " << v << "\n";
    // for(auto &[u,v]:iuv)
    // {
    //     // if(u != exp) u = exp,suml ++;
    //     // if(u > n/2) prps.push_back(u);
    //     // if(u > n/2) suml += u,u -= n/2;
    //     if(v <= convexRG){
    //         sumr += v;
    //         v = prps.front();
    //         prps.pop_front();
    //     }
    // }
    // int ans = 0;
    // ans += abs(suml-sumr);
    sort(all(iuv));
    // cout << "--------\n";
    // for(auto [u,v]:iuv) cout << u << " " << v << "\n";
    ord_set ord;
    // int cnt = 0;
    for(int i = iuv.size()-1;i >= 0;i --)
    {
        sum += ord.order_of_key(iuv[i].se);
        ord.insert(iuv[i].se);
    }
    for(int i = iuv.size()-1;i >= 0;i --)
    {
        sum += ord.order_of_key(iuv[i].fi);
        ord.insert(iuv[i].fi);
    }
    // cout << "--------\n";
    // for(auto [u,v]:iuv) cout << u << " " << v << "\n";
    // cout << ans << "\n";
    // for(auto [u,v]:iuv) sum += abs(abs(v-u)-n/2);
    
    // cout << ans + sum << "\n";
    cout << sum << "\n";
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
