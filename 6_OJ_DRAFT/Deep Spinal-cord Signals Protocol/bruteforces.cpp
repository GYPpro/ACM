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
    int n,k;
    cin >> n >> k;
    int wd = 0;
    int pd = 0;
 
    wd ++;pd += n;
    int curex = 2;
    // cout  << wd << " " << pd << "\n";

    while(pd < k) {
        for(int curey = 1;curey < curex;curey  ++){
            if(__gcd(curey,curex) == 1) wd ++,pd += n/curex;
            // cout  << wd << " " << pd << "\n";
            if(pd >= k) goto FORCE_END;
            if(__gcd(curey,curex) == 1) wd ++,pd += n/curex;
            // cout  << wd << " " << pd << "\n";
            if(pd >= k) goto FORCE_END;
        }
        curex ++;
    }

    FORCE_END:;

    // cout << wd << " " << pd << "\n";s
    cout << wd << "\n";

    // if(k <= n) {

    // }
}

signed main()
{
    // freopen("temp.in","r",stdin);
    // freopen("temp.out","w",stdout);
    
#ifdef FC
    freopen("A.A.in","r",stdin);
    freopen("A.A.std","w",stdout);
#endif


    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
