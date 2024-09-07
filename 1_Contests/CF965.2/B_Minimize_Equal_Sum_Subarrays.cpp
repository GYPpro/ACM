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
    vector<int> ans;
    vector<int> res(n);
    for(auto &x:res) cin >> x;
    for(auto x:res) cout << (x)%n+1 << " ";cout << "\n";
    
    // lop(i,n/2,n) ans.pb(res[i]);
    // lop(i,0,n/2) ans.pb(res[i]);
    // lop(i,0,n) ans.pb(res[n-i-1]);
    // swap(ans[n/2],ans[n-1]);
    // for(auto x:ans) cout << x << " ";cout << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif

    freopen("01.in","r",stdin);
    freopen("01.out","w",stdout);
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
