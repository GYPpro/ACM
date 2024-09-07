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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    set<int> lis;
    for(auto x:arr) lis.insert(x);
    vector<int> t = arr;
    auto getx = [&](int l) -> int {
        int sum = 0;
        t = arr;
        for(auto &tt:t)
            if(tt>l+k) tt = l+k;
            else if(tt < l) tt = l;
        // cout << l << "-\n";
        // for(auto x:t) cout << x << " ";cout << "\n";
        lop(i,1,n) //[1,n-1]
        {
            sum += abs(t[i-1] - t[i]);
        }
        // cout << sum << "\n";
        return sum;
    };
    int maxn = 0,maxi = 0;
    for(auto x:lis)
    {
        maxn = max(maxn,getx(x));
        maxn = max(maxn,getx(x-k));
    }
    cout << maxn << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
