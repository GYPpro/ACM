#include <bits/stdc++.h>
using namespace std;
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

int lcm(int a,int b) {
    int t = __gcd(a,b);
    return a * b / t;
}

// Version 2
int gcd(__int128 a, __int128 b) { return b == 0 ? a : gcd(b, a % b); }
signed main()
{
    // // freopen("A.in","w",stdout);
    // __int128 a,b;
    // int ta,tb;
    // cin >> ta >> tb;
    // a = ta;
    // a *= ta,a *= ta;
    // a *= 233;
    // b = tb;
    // b *= tb,b *= tb;
    // b *= 233;
    // cout << (int)__gcd(a,b) << "\n";
    // std::gcd()
    const int MEXK = 26;
    cout << "start:" << MEXK << "\n";
    vector<int> a(MEXK);
    iota(all(a),1);
    bitset<MEXK> subsets;
    vector<pair<int,vector<int>>> cnt(MEXK+3);
    vector<int> tmp;
    lop(i,0,1LL<<(MEXK+1))
    {
        // subsets = i;
        int t = 1;
        int nums = 0;
        tmp.clear();
        lop(k,0,MEXK) if((i >> (k) )% 2) t = lcm(t,a[k]),tmp.pb(a[k]),nums ++;
        // lop(k,0,MEXK+1) if(subsets[k]) t = lcm(t,a[k]),nums ++;
        // cnt[nums] = max(cnt[nums],t); 
        if(cnt[nums].fi < t) cnt[nums] = {t,tmp};
        // cout << "complete" << 
    }
    // for(auto [k,v]:cnt) 
    lop(i,0,MEXK)
    {
        auto [k,v] = pair(i,cnt[i]);
        cout << k << ":" << v.fi << "\n";
        for(auto x:v.se) cout << x << " ";cout << "\n";
    }
    system("pause");
    // system("pause");
    return 0;
}
