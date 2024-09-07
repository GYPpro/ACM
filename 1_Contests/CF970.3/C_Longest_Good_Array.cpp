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
    vector<int> rm(44724);

void solve()
{
    int l,r;
    cin >> l >> r;
    auto check = [&](int k )-> bool {
        if(rm[k]) return l+rm[k] <= r;
        // vector<int> mi;
        int t = 0;
        // mi.pb(l);
        int cur = l;
        int cnt = 1;
        while(cnt < k)
        {
            cur += t;
            t ++;
            if(cur > r) return 0;
            cnt ++;
            // cout << cur << " "; 
        }
        // cout << "\n";
        rm[k] = cur - l;
        return cur <= r;
    };  

    int ll = 0,rr = 44724;
    while(ll < rr) {
        int mid = ll+rr+1 >> 1;
        if(check(mid)) ll = mid;
        else rr = mid - 1;
    }
    cout << ll - 1 << "\n";

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
