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

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i ++,cout << "\n")
        for(int j = 0;j < m;j ++)
        {
            int t;
            cin >> t;
            if((i+j)%2) cout << 720720 << " ";
            else cout << 720720-t*t*t*t << " ";
        }
}

void lst(){
    int T = 720720;
    while(T += 1){
        int t1 = sqrtl(T-720720);
        for(int i = 2;i <= 16;i ++) if(__gcd(i,T) == 1) goto FORCE_NEXT;
        // for(int i = 2;i <= 16;i ++)
        if(t1*t1 == T-720720) {
            int t2 = sqrtl(t1);
            if(t1 == t2 * t2) {
                cout << T << "\n";
                cout << t1 << " " << t2 << "\n";
                return;
            }
        }
        // if(T %(int)(1e7) == 0){
        //     cout << "curIterator:" << T << "\n";
        // }
        FORCE_NEXT:;
    }
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    // lst();
    while(T--) solve();
    return 0;
}
