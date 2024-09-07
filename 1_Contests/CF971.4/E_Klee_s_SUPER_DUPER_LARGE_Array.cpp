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
    // k --;

    auto cacu = [&](int i) -> int{
        int p = (i * (k + i - 1+ k))/2;
        int f = ( ( n -i ) *(k + n - 1 + k + i))/2;
        // cout << i << " " << p << " " << f << "\n";
        return abs(p-f);
    };

    int l = 0,r = n;

    while (l < r) {
        int mid = (l + r) / 2;
        if (cacu(mid) <= cacu(mid + 1)) r = mid;
        else l = mid + 1;
    }
    cout << cacu(l) << endl;


    // int i = (4 * k - 2)/4;
    // int p = (i * (k + i + k))/2;
    // int f = ((n-i-1)*(k+n+k+i+1))/2;
    // cout << i << " " << p << " " << f << "\n";
    // cout << t << " " << (t * (2 * k + t - 1)) / 2 << " " << ( (  (n - t - 1) * (2 * k + t + n - 1) ) / 2) << "\n";
    // cout << abs((t * (2 * k + t - 1)) / 2 - ( (  (n - t - 1) * (2 * k + t + n - 1) ) / 2)) << "\n";
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
