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

using i128 = __int128;

i128 abs(i128 t) {
    if(t < 0)  return -t;
    else return t;
}

string i2str(i128 x){
    string sign;
    string s;
    if(x < 0) sign.push_back('-'),x = -x;
    while (x)
    {
        s.push_back('0' + x%10);
        x /= 10;
    }
    reverse(all(s));
    return sign + s;
}

void solve()
{
    i128 a,b;
    int ta,tb;
    cin >> ta >> tb;
    a = ta,b = tb;
    i128 f = a * 10 + b;
    if(a == 11 && b == -10) {
        cout << "1 9\n";
    } else if(f == 100) 
        cout <<  "-1\n";
    else {
        i128 p = (i128)11-a;
        i128 q = (i128)100-f;
        i128 t = __gcd(abs(p),abs(q));
        if(q < 0) p = -p,q = -q;
        cout << i2str(p/t) << " " << i2str(q/t) << "\n";
    }
}

void write(__int128_t x)
{
    if(x<0)
        cout<<('-'),x=-x;
    if(x>9)
        write(x/10);
    cout<<char(x%10+'0');
    return;
}

void test(){
    int t;
    cin >> t;
    write(t); 
    cout<< "\n";
    // cout << write(t) << "\n";
}

signed main()
{
#ifdef FC
    freopen("J.A.in","r",stdin);
    freopen("J.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    // while(T--) test();
    return 0;
}
