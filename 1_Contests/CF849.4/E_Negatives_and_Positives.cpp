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
    sort(all(arr));
    int cnt = 0;
    for(auto x:arr) if(x < 0) cnt ++;
    int sum = 0;
    for(auto x:arr) sum += abs(x);
    if(cnt % 2)
    {
        int mindisc = INF;
        for(auto x:arr) mindisc = min(mindisc,abs(x));
        cout << sum-2*mindisc << "\n";
        // lop(i,1,n) 
    } else {
        cout << sum << "\n";
    }
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
