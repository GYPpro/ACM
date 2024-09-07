// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
// using namespace std;

using ord_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
using ord_multiset = tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>;

void solve()
{
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    vector<int> tar(n+1);
    lop(i,1,n+1) tar[i] = arr[i] - i;
    // for(auto x:tar) cout << x << " ";cout << "\n";
    // vector<int> ctr;
    // using p3i = pair<int,pair<int,int>>;
    set<pii> sp;
    map<int,int> cnt;
    lop(i,1,k+1) cnt[tar[i]] ++;
    for(auto x:cnt) sp.insert({x.se,x.fi});
    vector<int> rec(n+2);
    int cur = k;
    rec[cur] = k - sp.rbegin()->first;
    // for(auto x:cnt) cout << x.fi << " " << x.se << "\n";
    while(cur <= n) {
        pii t = *cnt.find(tar[cur - k + 1]);
        // cout << t.fi << " " << t.se << "\n";
        // for(auto x:cnt) cout << x.fi << " " << x.se << " | ";cout << "\n";
        // for(auto x:sp) cout << x.fi << " " << x.se << " | ";cout << "\n";
        cnt[tar[cur-k+1]] --;
        sp.erase({t.se,t.fi});
        // sp.insert({t.fi})
        if(t.se > 1) sp.insert({t.se-1,t.fi});
        cur ++;
        cnt[tar[cur]] = cnt[tar[cur]];
        t = *cnt.find(tar[cur]);
        sp.erase({t.se,t.fi});
        sp.insert({t.se+1,t.fi});
        cnt[tar[cur]] ++;
        rec[cur] = k - sp.rbegin()->first;
    };
    // for(auto x:rec) cout << x << " ";cout << "\n";
    vector<int> prf(n+1);
    lop(i,1,n+1) prf[i] = prf[i-1] + rec[i];
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << prf[r] - prf[l+k-2]<< "\n";
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
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
