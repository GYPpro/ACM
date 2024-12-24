// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
using ord_set = tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1e18;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    // cout << "-----\n";
    int n,k;
    cin >> n >>k;
    vector<pii> gst(n);
    for(auto &[b,a]:gst) cin >> a;
    for(auto &[b,a]:gst) cin >> b;
    sort(all(gst));
    // int MX = n == k ? INF : gst[k].fi;
    int MX = gst.back().first;

    set<int> sep;
    for(auto [b,a]:gst) 
        sep.insert(a-1),
        sep.insert(a),
        sep.insert(a+1),
        sep.insert(b-1),
        sep.insert(b),
        sep.insert(b+1);

    // auto cacu = [&](int va) -> int {
    //     int sum =0;
    //     for(auto [b,a]:gst) if(b > va) sum += va;
    //     return sum;
    // };

    ord_set sa,sb;
    for(auto [b,a]:gst) sa.insert(a),sb.insert(b);

    auto cacu2 = [&](int va) -> int {
        // cout << va << ":";
        int SA = sa.size() - sa.order_of_key(va);
        int SB = sb.size() - sb.order_of_key(va);
        // cout <<  SA << " " << SB << "\n";
        if(SB-SA > k) return 0;
        else return SB * va;
        // int sum =0;
        // for(auto [b,a]:gst) if(b > va) sum += va;
        // return sum;
    };
int mx = 0;
    for(auto v:sep)
    {
        mx = max(mx,cacu2(v));
        // cout << i << "\t" << cacu(i) << " " << cacu2(i) << "\t";
        // int sk = 0;
        // for(auto [b,a]:gst) if(i > a &&  i <= b) sk ++;
        // cout << sk << "\n";
    }
    cout << mx << "\n";
    // for(int i = 0;i < k;i ++){
    //     if(i == n)
    // }
    // vector<int> a(n),b(n);
    // for(auto &x:a) cin >> x;
    // for(auto &x:b) cin >> x;

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
