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

vector<int> pris = {2,3,11,4649,513239,265371653,5363222357};
vector<int> pw(1,1);

void solve()
{
    int n;
    cin >> n;
    auto check = [&](int t) -> bool {
        for(auto x:pris) if(t % x == 0){
            cout << t << " " << x << "\n";
            return 1;
        }
        return 0;
    };
    for(int i = 0;pw[i] <= n;i ++)
    {
        int cur = n % pw[i] + (n / pw[i+1] * pw[i]);
        if(check(cur)) return;
    }
    if(check(n)) return;
    assert(1);
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
    for(int i = 1;i < 18;i ++) pw.push_back(pw.back() * 10);
    // for(auto x:pw) cout << x << " ";cout << "\n";
    cin >> T;
    while(T--) solve();
    return 0;
}
