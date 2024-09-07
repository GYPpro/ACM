// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> cnt;
    vector<pair<int,char>> t;
    vector<pair<int,char>> rst;
    string ans;
    for(auto x:s) cnt[x] ++;
    for(auto x:cnt) t.pb({x.se,x.fi});
    sort(all(t));
    for(int k = t.size()-1;k >= 0;k --)
        lop(i,0,t[k].fi) rst.pb({i*n+(n-k-1),t[k].se});
    sort(all(rst));
    for(auto x:rst) cout << x.se;cout << "\n";
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
