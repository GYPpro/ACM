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
    int a,b,c;
    cin >> a >> b >> c;
    int ma = pow(10,a-1);
    int mb = pow(10,b-1);
    c --;
    ma /= pow(10,c);
    mb /= pow(10,c);
    while(__gcd(ma,mb) != 1) ma ++;
    string str;
    while(c--) str += '0';
    cout << ma << str << " " << mb << str << "\n";
    // vector<int> diga(a,0),digb(b,0);
    // diga.front() = 1;
    // if(a == b) digb.front() = 3;
    // else digb.front() = 1;
    // diga[a-c] = digb[b-c] = 1;
    // for(auto x:diga) cout << x;cout << " ";
    // for(auto x:digb) cout << x;cout << "\n";
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
    while(T--) solve();
    return 0;
}
