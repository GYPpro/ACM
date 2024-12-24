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

bool eq (vector<int> &a,vector<int> &b) {
    if(a.size() != b.size()) return 0;
    lop(i,0,a.size()) if(a[i] != b [i]) return 0;
    return 1;    
}

void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    // int a = 0,b = 0,c;
    set<char> ban;
    map<char,int> forceCNT_EQ,forceCNT_GT;
    map<char,vector<int>> forceLOC;
    map<char,vector<int>> forceUNLOC;
    lop(i,0,8)
    {
        if(s2[i] == 'B') {
            forceUNLOC[s1[i]].pb(i);
            // if(forceCNT_GT.find(s1[i]) == forceCNT_GT.end()) forceCNT_GT[s1[i]] = 0;
            forceCNT_EQ[s1[i]] = 0;
        }
        if(s2[i] == 'G') forceLOC[s1[i]].pb(i),forceCNT_GT[s1[i]] ++;
        if(s2[i] == 'P') forceCNT_GT[s1[i]] ++,forceUNLOC[s1[i]].pb(i);
    }
    vector<pair<char,int>> unm;
    for(auto [ch,v]:forceCNT_GT)
        if(forceCNT_EQ.find(ch) != forceCNT_EQ.end()) {
            forceCNT_EQ[ch] = v;
            unm.pb({ch,v});
        }
    for(auto [ch,v]:unm) forceCNT_GT.erase(ch);
    map<char,int> curcnt;
    map<char,vector<int>> curloc;

    // auto eq = [&]()

    auto check = [&](string s) -> bool
    {
        curcnt.clear(),curloc.clear();
        bool flag = 1;
        lop(i,0,8)
        {
            curcnt[s[i]] ++;
            curloc[s[i]].pb(i);
            // if(ban.find(s[i]) != ban.end()) return 0;
        }
        for(auto [ch,v]:forceCNT_EQ) if(curcnt[ch] != v) return 0;
        for(auto [ch,v]:forceCNT_GT) if(curcnt[ch] < v) return 0;
        for(auto [ch,v]:forceLOC)
            for(auto i:v) if(s[i] != ch) return 0;
        for(auto [ch,v]:forceUNLOC) 
            for(auto i:v) if(s[i] == ch) return 0;
        return 1;
    };
    vector<string> ans;
    string cur = "--+--=--";
    // cout << check("11+44=55");
    lop(a,0,100)
        lop(b,0,100)
        {
            if(a + b >= 100) continue;
            int c = a+b;
            cur[0] = '0' + (a/10);
            cur[1] = '0' + (a%10);
            cur[3] = '0' + (b/10);
            cur[4] = '0' + (b%10);
            cur[6] = '0' + (c/10);
            cur[7] = '0' + (c%10);
            if(check(cur)) ans.pb(
                cur
            );
        }  
    cout << ans.size() << "\n";
    for(auto x:ans )cout << x << "\n";
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
