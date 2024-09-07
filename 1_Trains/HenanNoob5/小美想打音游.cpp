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
    map<int,int> cnt;
    // for(auto &x:arr) cin >> x;
    int sum = 0;
    lop(i,0,n) {
        int t;
        cin >> t;
        cnt[t] ++;
        sum += t;
    }
    // sort(all(arr));
    int l = 0,r = n;
    // for(auto x:cnt) sum += x;
    int ans = INF;
    lop(i,1,n+1)
    {
        sum += l,sum -= r;
        l += cnt[i],r -= cnt[i];
        ans = min(ans,sum);
    }
    // sum /= n;
    // int cnt = 0;
    // for(auto x:arr) cnt += abs(x-sum);
    cout << ans+1 << "\n";
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
