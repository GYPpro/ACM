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
    vector<int> ans(n+1);
    if(n%2 == 0) {
        cout << "-1\n";return;
    }
    int l = n/2;
    int r = n/2+1;
    int cnt = 1;
    while(l >= 0 || r < n)
    {
        if(l >= 0){
            ans[l] = cnt ++;
            l --;
        }
        if(r >= n) continue;
        ans[r] = cnt++;
        r ++;
    }
    lop(i,0,n) cout << ans[i] << " \n"[i == n-1];
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
