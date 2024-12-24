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
#define ld long double
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    if(n <= 2){ cout << "-1\n";
    return;}
    sort(all(arr));
    int sum = 0;
    lop(i,0,n) sum += arr[i];
    auto check = [&](int k) -> bool {
        ld avg = (ld)(sum+k)/(ld)n;
        if(arr[n/2] * 2 < avg) return 1;
        else return 0;
    };
    int l = -1,r = 1e13;
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
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
