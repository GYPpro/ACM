
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
    vector<int> ans(n*2);
    if(n == 2)
    {
        ans = {1,-3,-3,1};
    for(auto x:ans) cout << x << " "; cout << "\n";
    return;
    }
    if(n == 3) {
        ans = {1,-10,6,6,-10,1};
        
    for(auto x:ans) cout << x << " "; cout << "\n";
    return;
    }
    lop(i,0,ans.size()) ans[i] = (i%2 == 0)?-1:2;
    ans[0] = 1;
    ans[n*2-1] = 3-n;
    for(auto x:ans) cout << x << " "; cout << "\n";
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
