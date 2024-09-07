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
    int n,s,m;
    cin >> n >> s >> m;
    int pve = 0;
    bool flag =  0;
    lop(i,0,n)
    {
        int l,r;
        cin >> l >> r;
        // cout << l << " " << r << " " << pve << "\n";
        if(l - pve >= s && !flag) {cout << "YES\n";flag = 1;}
        pve = r;
    }
    if(flag) return;
    if(m - pve >= s) {cout << "YES\n";return;}
    cout << "NO\n";
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
