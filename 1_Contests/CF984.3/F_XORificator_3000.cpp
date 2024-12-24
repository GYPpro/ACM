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

int prfxor(int x)  {
    if(x < 0) return 0;
    switch (x%4)
    {
        case 0: return x;
        case 1: return 1;
        case 2: return x+1;
        case 3: return 0;
    }
}

void solve()
{

    int l,r,i,k;
    cin >> l >> r >> i >> k;

    // auto prfintr = [&]()
    int f = 1LL << i;
    auto prfcnt = [&](int x) -> int  {
        if(x  < k) return 0;
        else 
        return (x - k) / f + 1;
    };

    int px = prfxor(r) ^ prfxor(l-1);
    // cout << px << " ";
    // cout <<  prfcnt(r) << " " << prfcnt(l-1) << "\n";

    // int pc = prfcnt(r) - prfcnt(r-1);
    // cout << prfxor(prfcnt(r)) << " " << 
    int pc = prfxor(prfcnt(r)-1) ^ prfxor(prfcnt(l-1)-1);
    // cout << (pc  * f) << " " << ((pc  * f) ^ ((prfcnt(r) - prfcnt(l-1)) %2 == 0 ? 0 : k )) << "\n";
    cout << (px ^ (pc  * f) ^ ((prfcnt(r) - prfcnt(l-1)) %2 == 0 ? 0 : k )) << "\n";

}
/*<<<>>>>[-<<>>>]<<[]
10000
|
[  ]^]
char * ptr
^ *ptr ^= 1;
< ptr ++;
> ptr --;
[1 if() goto ]2;
]2 if() goto [1;
- print(*ptr);
*/
void lister()
{
    int n;
    cin >> n;
    int prv = 0;
    for(int i =1;i <=n ;i ++)
    {
        prv ^= i;
        cout << i << ": " << prv << "\n";
    }
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
    // lister();
    cin >> T;
    while(T--) solve();
    return 0;
}
