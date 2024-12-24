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

void solve()
{
    int n;
    cin >> n;
    if(n == 1) {
        cout << "24\n";
        return;
    }
    int ans = 1;
    int prv = 1;
    int cnt = 0;
    int i = 0;
    while(cnt < 3)
    {
        while(pri[i] < prv + n) i ++;
        prv = pri[i],ans *= pri[i],cnt ++;
    }
    cout << ans << "\n";
    // vector<int> ans;
    // for(int i = 1;i * i <= n;i ++)
    // {
    //     if(n % i == 0) ans.pb(i),ans.pb(n/i);
    // } 
    // sort(all(ans));
    // for(auto x:ans) cout << x << " ";
    // cout << "\n";
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
    init(1e6);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
