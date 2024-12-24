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

vector<int> pri;
void init(int n)
{
    vector<bool> vis(n+1,0);
    for(int i = 2;i <= n;i ++)
    {
        if(!vis[i]) pri.pb(i);
        for(int j = 0;j < pri.size();j ++)
        {
            if(i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break; 
        }
    }
}

const int mod = 998244353;

// int solve(int n)
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    auto pw = [](int x) -> int {
        x = (x*x % mod) * x % mod;
        return x % mod;
    };
    lop(i,0,n)
        lop(j,i+1,n)
            lop(l,j+1,n)
            {
                if(pri[i] * pri[j] * pri[l] > n) continue;
                sum += pw(pri[i]+pri[j]+pri[l]);
                // cout << pri[i] << " " << pri[j] << " " << pri[l] << "\n";
            }
    cout << sum << "\n";
    // return sum;
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
    init(1e4);
    int T = 1;
    cin >> T;
    while(T--) solve();
    // lop(i,1,T)
    //     cout << i << ":" << solve(i) << "\n";
    return 0;
}
