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
    int n,k;
    cin >> n >> k;
    if(k == 1) {
        while(n--) cout << "a";cout << "\n";
        return;
    }
    string mod = "abb";
    char cur = 'c';
    while(mod.size() < n && cur - 'a' < k) {
        for(char i = 'a';i < cur;i ++)
        {
            mod += i;
            mod += cur;
        }
        mod += cur;
        cur ++;
    }
    mod += 'a';
    // cout << mod << "\n";
    k = 0;
    int cnt = 0;
    cout << "a";
    while(cnt < n-1) {
        cout << mod[k % (mod.size())];
        k ++;
        cnt ++;
    }
    cout << "\n";
}

void check(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for(int i = 0;i < n-1;i ++)
        for(int j = i+1;j < n-1;j ++)
            if(s[i] == s[j] && s[i+1] == s[j+1]) cnt ++;
    cout << cnt << "\n";
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
    // cin >> T;
    while(T--) solve();
    // while(T--) check();
    return 0;
}
