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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "$"+s;
    vector<int> cp(n+1),ca(n+1),ct(n+1);
    for(int i = 1;i <= n;i ++)
    {
        if(s[i] == '-') cp[i] = cp[i-1]+1,ca[i] = ca[i-1];
        else ca[i] = ca[i-1] + 1,cp[i] = cp[i-1];
        ct[i] = cp[i]-ca[i];
    }
    int ans = 0;
    vector<ord_set> cnt(3);
    for (int i = 0; i <= n; i++)
    {
        int f = (ct[i] + (int)3e9) % 3;
        ans += cnt[f].size() - cnt[f].order_of_key(-ct[i]);
        cnt[f].insert(-ct[i]);
    }
    cout << ans << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
