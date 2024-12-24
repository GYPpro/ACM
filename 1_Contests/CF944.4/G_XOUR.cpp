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
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    map<int, pair<vector<int>,vector<int>> > parts;
    lop(i,0,n) parts[arr[i]/4 + 1].fi.pb(i),parts[arr[i]/4 + 1].se.pb(arr[i]);
    vector<int> res(n);
    for(auto &x:parts) sort(all(x.se.se)),sort(all(x.se.fi));
    for(auto [_,x]:parts)
        lop(i,0,x.se.size())
            res[x.fi[i]] = x.se[i];
    for(auto x:res) cout << x << " ";cout << "\n";
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
