// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

#include <bits/stdc++.h>
// #define int long long
#define pii pair<int,int>
// #define int long long
#define pb push_back
#define fi first
#define se second
const int INF = 100000000LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

// #define map unordered_map

long long shash(pii a){
    return a.fi * (long long)(1e10)+a.se;
};

vector<vector<int>> factors(5e5+1);

void solve()
{
    int n;
    cin >> n;
    // if(500000 == n) return;
    vector<int> p(n+1);
    lop(i,1,n+1) cin >> p[i];
    vector<int> a(n+1),b(n+1);
    vector<vector<int>> posa(n+1),posb(n+1);
    lop(i,1,n+1) 
        a[i] = p[i] / __gcd(i,p[i]),b[i] = i / __gcd(i,p[i]),
        posa[a[i]].pb(i),posb[b[i]].pb(i);
    // map<long long,int> cnt;
    // vector<map<int,int>> cnt(n+1);
    vector<int> cnt(n+1);

    // Pollard_Rho pr;
    long long ans = 0;
    lop(i,1,n+1)
    {
        for(int k = 1;k * i <= n;k ++) 
            for(auto j : posa[ i * k ]) cnt[b[j]] ++;
        
        for(auto bi : posb[i])
            for(auto fac:factors[a[bi]]) ans += cnt[fac];
            
        for(int k = 1;k * i <= n;k ++) 
            for(auto j : posa[ i * k ]) cnt[b[j]] --;

        // #define rt factors[a[i]]
        // // auto rt = factors[a[i]];
        // for(auto x:rt)
        //     if(cnt[a[i]/x].find(b[i]) != cnt[a[i]/x].end())
        //         ans += cnt[a[i]/x][b[i]];
        //     // if(cnt.find(shash({a[i] / x,b[i]})) != cnt.end())
        //     //     ans += cnt[shash({a[i] / x,b[i]})];
        // for(auto y:rt)
        //     cnt[b[i]][a[i]/y] ++;
        //     // cnt[shash({b[i],a[i] / y})] ++;
        // #undef rt
    }
    for(auto x:b) if(x == 1) ans --;
    cout << ans/2 << "\n";

}

void init()
{
    const int N = 5e5+1;
    for(int i = 1;i < N;i ++)
    {
        for(int k = 1;k * i < N;k ++ )
        {
            factors[k*i].pb(i);
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
init();
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
