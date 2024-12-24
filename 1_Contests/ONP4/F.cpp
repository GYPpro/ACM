#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ord_set = tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
// #define map unordered_map
#pragma GCC optimize(3)
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n+1);
    lop(i,1,n+1) cin >> s[i];
    // vector<int> rs(n+2);
    // ord_set ord;
    // for(int i = n;i >= 1;i --){
    //     rs[i] = rs[i+1] + ord.order_of_key(s[i]);
    //     ord.insert(s[i]);
    // }
    auto rec = [&]() -> int {
        vector<int> rs(n+2);
        ord_set ord;
        for(int i = n;i >= 1;i --){
            rs[i] = rs[i+1] + ord.order_of_key(s[i]);
            ord.insert(s[i]);
        }
        return rs[1];
    };

    int cur = rec();
    int mi = cur;
    int m;
    cin >> m;

    while(m--)
    {
        int l,r;
        cin >> l >> r;
        if(l == r) continue;
        // if()
        int al = s[l],ar = s[r];
        lop(i,l+1,r)
            if(s[i] < al) cur --;
            else if(s[i] > al)  cur ++;
        lop(i,l+1,r)
            if(s[i] > ar) cur --;
            else if(s[i] < al) cur ++;
        if(s[l] > s[r]) cur --;
        else cur ++;
        swap(s[l],s[r]);
        mi = min(mi,cur);
        // cout << cur << " ";
        // cout << ((cur == rec())?"AC":"WA") << "\n";
    }
    cout << mi << "\n";
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // init(5e5);
    int t = 1;
    cin >> t;
    while(t--) solve();
}