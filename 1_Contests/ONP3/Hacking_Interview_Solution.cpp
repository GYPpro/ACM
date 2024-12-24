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

const int N = 1 << 21;
int mod1 = 1e9+7,base1 = 127;
int mod2 = 1e9+9,base2 = 131;
vector<int> val1;
vector<int> val2;
using puv = pair<int,int>;
void init(int n = N)
{
    val1.resize(n+1),val2.resize(n+1);
    val1[0] = 1,val2[0] = 1;
    for(int i = 1;i <= n;i ++)
    {
        val1[i] = val1[i-1] * base1 % mod1;
        val2[i] = val2[i-1] * base2 % mod2;
    } 
}
class hs{
public:
    vector<int> h1,h2;
    string s;
    hs(string _s) : s(_s),h1{0},h2{0} {build();}
    void build()
    {
        for(auto it:s)
        {
            h1.pb((h1.back() * base1 % mod1 + it) % mod1);
            h2.pb((h2.back() * base2 % mod2 + it) % mod2);
        }
    }
    puv get() {
        return {h1.back(),h2.back()};
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    cin.get();
    vector<string> mtx;
    lop(i,0,m)
    {
        string s;
        // getline(stdin,s);
        // cin.getline(s,stdin);
        char c = cin.get();
        while(c != '\n')
        {
            s.push_back(c);
            c = cin.get();
        }
        // cout << s << "\n";
        mtx.push_back(s);
    }
    vector<puv> hmtx;
    map<puv,int> cnt;
    int ans = 0;
    for(auto s:mtx) hmtx.pb(hs(s).get());
    for(int i = m-1;i >= 0;i --)
    {
        ans += cnt[hmtx[i]];
        cnt[hmtx[i]] ++;
    }
    cout << ans << "\n";
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
