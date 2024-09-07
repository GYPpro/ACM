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

bool cmp(int a,int b) {return a > b;}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    vector<pii> ADS;
    sort(all(arr),cmp);
    for(int i = 0;i+1 < n;i += 2)
    {
        int dev = arr[i]-arr[i+1];
        if(dev < k) {
            arr[i+1] = arr[i];
            k -= dev;
        } else {
            arr[i+1] += k;
            k = 0;
        }
    }
    int ans = 0;
    for(int i = 0;i+1 < n;i += 2)
    {
        int dev = arr[i]-arr[i+1]; ans += dev;
    }
    if(n%2) ans += arr[n-1];
    // ans 

    // for(auto x:ADS) cout << x.fi << " " << x.se << "\n";
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
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
