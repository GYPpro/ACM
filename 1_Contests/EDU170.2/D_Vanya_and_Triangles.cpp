#pragma GCC optimize(2)

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
const int MEX = 105;
map<int,int> rcn;

void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for(auto &[x,y]:a) {
        cin >> x >> y;
    }
    using tii = array<int,3>;
    struct my_hash
    {
        size_t operator()(tii x) const {
            return x[0]*1600800+x[1]*410+x[2];
        }
    };
    unordered_map<tii,int,my_hash> lineCNT;
    pii gt,ft;
    auto rtv = [&](pii a,pii b) -> void {
        tii stdfuinc = {  b.fi-a.fi, b.se-a.se, -a.fi*b.se+a.se*b.fi};
        int t = __gcd(__gcd(stdfuinc[0],stdfuinc[1]),stdfuinc[2]);
        stdfuinc[0] /= t;
        stdfuinc[1] /= t;
        stdfuinc[2] /= t;
        lineCNT[stdfuinc] ++;
    };
    auto C3 = [](int n) -> int {
        if(n < 3) return 0;
        return n*(n-1)*(n-2) / 6;
    };
    int cur = C3(n);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            if(a[i].fi == a[j].fi && a[i].se == a[j].se) continue;
            else rtv(a[i],a[j]);
    for(auto [line,val]:lineCNT)
        cur -= C3(rcn[val]);
    cout << cur << "\n";

}

void init(){
    for(int i = 0;i < 2050;i ++) rcn[i*(i-1)] = i;
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
    init();
    while(T--) solve();
    return 0;
}
