// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less_equal<int>, rb_tree_tag,
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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    map<int,int> cnt;
    for(auto x:a) cnt[x]++;

    // ord_set ord;
    // // set<int> lst;
    // for(auto x:a) ord.insert(x);
    sort(all(a));
    int mx = 0;
    a.erase(unique(all(a)),a.end());
    for(int i = 0;i < a.size();){
        int pre = 0;
        int p = a[i];
        int pi = i;
        // cout << i << " " << pi << " " << p << "\n";
        while(cnt[p] && p <= a[i]+k-1){
            pre += cnt[p];
            // cout <<"+" << p << "\n";
            p ++;
            pi ++;
        }
        mx = max(pre,mx);
        while(cnt[p]){
            pre -= cnt[p-k];
            // cout << "-"<<p-k << "\n";
            // cout << "+"<<p << "\n";
            pre += cnt[p];
            mx = max(pre,mx);
            p ++;
            pi ++;
        }
        i = pi;
    }
    // int curg = cnt.begin()->fi;
    // cnt[INF] ++;
    // while(curg < a.back()){
    //     // cout << "---\n";
    //     // cout << curg << " ";
    //     int pre = 0;
    //     int p = 0;
    //     for(int i = 0;i < k;i ++) {
    //         p = curg+i;
    //         pre += cnt[curg+i];
    //         if(cnt[curg+i] == 0) break;
    //     }
    //     mx = max(pre,mx);
    //     // k = 3  p:5 [3 4 5] + [6] -[3]
    //     curg = cnt.lower_bound(p+1)->fi;
    //     // cout << curg << " ";
    //     if(!cnt[p]) continue; 
    //     while(cnt[p+1]) {
    //         pre += cnt[p+1];
    //         pre -= cnt[p-k+1];
    //         mx = max(pre,mx);
    //         p ++;
    //     }
    //     curg = cnt.lower_bound(p+1)->fi;
    //     // cout << curg << " ";

    //     // curg
    //     // for()
    // }
    // // for(auto x:a)cout << x << " ";cout << "\n";
    // int mx = 0;
    // for(int i = 0;i < a.size();i ++) {
    //     int ls = ord.order_of_key(a[i]);
    //     // int idx = lower_bound(all(a),x)-a.begin();
    //     // cout << x << " "
    //     int rs = ord.order_of_key(a[min(i+k-1,(int)a.size()-1)]+1);
    //     mx = max(mx,rs-ls);
    // }
    cout << mx << "\n";
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
