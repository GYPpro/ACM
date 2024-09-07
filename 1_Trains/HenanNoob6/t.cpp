// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> dis(n+1);
    ordered_set ord;
    lop(i,1,n+1) cin >> dis[i];
    lop(i,1,m+1) {
        int t;
        cin >> t;
        ord.insert(t);
    }
    int Q;
    while(Q--)
    {
        int t,x;
        cin >> t >> x;
        if(ord.lower_bound(t-dis[x]) != ord.end()) 
        cout << (*ord.lower_bound(t-dis[x])) << "\n";
        else cout << "TNT\n";
    }
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
