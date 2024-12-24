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
#define map unordered_map

void solve()
{
    string a,b;
    cin >> a >> b;
    if(b.size() == 1 || a.size() == 1 || a.size() == b.size()) {
        cout << b << "\n";
        return;
    }
    using pci = pair<char,int>;
    vector<pci> ptrs;
    int pta = 0,ptb = 0;
    while(pta < a.size() && ptb < b.size())
    {
        if(a[pta] == b[ptb]) ptrs.pb({b[ptb],pta}),pta++,ptb++;
        else pta++;
    }
    ptrs.pb({0,INF});
    map<char,vector<int>> nxt; //nxt[ch][i]
    map<int,int> prv;
    for(char c = '0';c <= '9';c ++) prv[c] = a.size(),nxt[c].resize(a.size());
    for(char c = 'a';c <= 'z';c ++) prv[c] = a.size(),nxt[c].resize(a.size());
    for(int i = a.size()-1;i >= 0;i --)
    {
        for(auto [ch,_]:prv)
        {
            nxt[ch][i] = prv[ch];
        }
        prv[a[i]] = i;
    }
    auto push = [&]() -> bool {
        int cur = ptrs.front().se;
        lop(k,0,ptrs.size())
        {
            auto [ch,i] = ptrs[k]; // ch,i
            ptrs[k].se = nxt[ch][cur];
            cur = ptrs[k].se;
            if(cur >= a.size()) return 0;
            if(ptrs[k].se < ptrs[k+1].se) return 1;
        }
        return 1;
    };
    pii ans = {0,0};
    int mi = INF;
    do{
        pii cur = {ptrs[0].se,ptrs[ptrs.size()-2].se};
        if(cur.se - cur.fi < mi) ans = cur,mi = cur.se - cur.fi;
    }while(push());
    cout << a.substr(ans.fi,ans.se-ans.fi+1) << "\n";
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
