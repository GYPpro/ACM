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

void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    if(s.size() <= 3){
        while(q--)
        {
            int _;
            cin >> _ >> _;
            cout << "NO\n";
        }
        return;
    }
    int n = s.size();
    vector<int> st(s.size()-3);
    auto cacu = [&](int i) -> int {
        if(i < 0 || i >= n-3) return 0;
        int f = 0;
        int t = 1;
        for(int j = i;j < i+4;j ++)
        {
            f += (s[j]-'0') * t;
            t *= 2;
        }
        return f;
    };
    for(int i = 0;i < n-3;i ++)
    {
        st[i] = cacu(i);
    }
    // for(auto x:st) cout << x << " ";
    //  int cnt = 1
    // 11001101100
    // 10000001000
    int cnt3 = 0;
    for(auto x:st) if(x == 3) cnt3 ++;
    vector<int> cur,tar;
    while(q--)
    {
        int i,v;
        cin >> i >> v;
        i --;
        // 012[3]4
        cur.clear(),tar.clear();
        for(int j = max(0LL,i-3);j <= i;j ++) cur.push_back(cacu(j));
        s[i] = '0'+v;
        for(int j = max(0LL,i-3);j <= i;j ++) tar.push_back(cacu(j));
        for(int j = 0; j < tar.size();j ++) if(cur[j] == 3 && tar[j] != 3) cnt3 --;
        else if(cur[j] != 3 && tar[j] == 3) cnt3 ++;
        if(cnt3) cout << "YES\n";
        else cout << "NO\n";
    }
    // auto cacu = [&](int x)
//     int n,q;
//     cin >> n >> q;

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
