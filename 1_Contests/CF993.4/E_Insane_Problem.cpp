// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

using i128 = __int128_t;

void solve()
{
    i128 MEXCAP = 1e10;
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    i128 prk = 1;
    auto get = [&]() -> int {
        i128 tl1 = l1 * prk,tr1 = r1 * prk;
        tl1 = max(tl1,(i128)l2),tr1 = min(tr1,(i128)r2);
        // cout << (int)tl1 << " " << (int)tr1 << " - " << (int)prk << " " << (int)max((i128)0,tr1/prk - (tl1-1)/prk) << "\n" ;
        return max((i128)0,tr1/prk - (tl1-1)/prk);
    };
    int sum = 0;
    while(prk < MEXCAP) {
        sum += get();
        // cout << (int)prk << " " << sum << "\n";
        prk *= k;
    }
    cout <<  sum << "\n";
}

void check(){
    
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    for(int i = l1;i <= r1;i ++)
        for(int j = l2;j <= r2;j ++)
            if(j%i == 0) cout << i << " " << j << " :" <<  j/i << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    // while(T--) check();
    while(T--) solve();
    return 0;
}
