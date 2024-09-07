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
    vector<vector<int>> mtx(n+1,vector<int>(n+1));
    vector<pii> cods;
    function<void(pii,pii)> lock = [&](pii a,pii b) -> void {
        pii dev = {a.fi-b.fi,a.se-b.se};
        int t = __gcd(abs(a.fi-b.fi),abs(a.se-b.se));
        dev.fi /= t,dev.se /= t;
        int k = 1;
        while((a.fi + dev.fi * k >= 1 && a.fi + dev.fi * k <= n) && (a.se + dev.se * k >= 1 && a.se + dev.se * k <= n)) 
        {
            mtx[a.fi + dev.fi * k][a.se + dev.se * k] = 1;
            k ++;
        }
        k = -1;
        while((a.fi + dev.fi * k >= 1 && a.fi + dev.fi * k <= n) && (a.se + dev.se * k >= 1 && a.se + dev.se * k <= n)) 
        {
            mtx[a.fi + dev.fi * k][a.se + dev.se * k] = 1;
            k --;
        }
        return;
    };
    int q = n*n;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(cods.size() == 0){cout << "1"; cods.pb({a,b});}
        else {
            if(mtx[a][b]){cout << "0"; continue;}
            for(auto x:cods) lock(x,{a,b});
            cods.pb({a,b});
            cout << "1";
        }
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
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
