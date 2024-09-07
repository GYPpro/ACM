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
    int n,c;
    int sum =0;
    cin >> n >> c;
    vector<int> arr(n+1);
    // for(auto &x:arr) cin >> x;
    lop(i,1,n+1) cin >> arr[i];
    for(auto x:arr) sum += x;
    lop(i,1,n+1) arr[i] += arr[i-1];
    for(auto &x:arr) x %= c;
    // sum %= c;
    map<int,int> cnt;
    // map<int,int> scnt;
    // lop(i,1,n+1) cnt[arr[i]] ++;
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        int x = arr[i];
        cnt[x] ++;
        ans += max(0LL,cnt[ x ]-1);
        // cnt[(x+sum)%c] ++;
        // ans += max(0LL,cnt[ (x + c - sum) %c ]-1);
    }
    cnt.clear();
    for(int i = 1;i <= n;i ++){
        int x = arr[i];
        // cnt[x] ++;
        // cout << x << " \n"[x == n];
        ans += max(0LL,cnt[ x ]);
        cnt[(x+sum)%c] ++;
        // ans += max(0LL,cnt[ (x + c - sum) %c ]-1);
    }
    // for(int i = 1;i <= n;i ++) {
    // cnt.clear();
    //     int x = arr[i];
    //     cnt[x] ++;
    // }
    cout << ans << "\n";
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
