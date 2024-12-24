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
using ld = long double;
pair<int,vector<ld>> GaussianELI(vector<vector<ld>> a,vector<ld> b) {
    assert(a.size()),assert(a.size() == a[0].size()),assert(a.size() == b.size());
    int n = a.size();
    vector<int> p(n);
    iota(all(p),0);
    for(int i = 0;i < n;i ++){
        sort(p.begin()+i,p.end(),[&](int x,int y) -> bool {return abs(a[x][i]) > abs(a[y][i]); });
        for(auto x:p) cout << x <<" ";
        cout << "begin:" << p[i] << " " << a[p[i]][i] << "\n";
        
        for(int i = 0;i < n;i ++)
            for(int j = 0;j <= n;j ++) if(j != n) cout << a[p[i]][j] << " ";
        else cout << b[p[i]] << "\n";
        if(a[p[i]][i] == 0) continue;
        for(int j = i+1;j < n;j ++)
        {
            cout << "at:" << p[j] << "\n";
            ld k = a[p[j]][i]/a[p[i]][i] ;
            for(int f = i;f < n;f ++) a[p[j]][f] -= a[p[i]][f] * k;
            b[p[j]] -= b[p[i]] * k;
        }
    }
    cout << fixed << setprecision(2);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j <= n;j ++) if(j != n) cout << a[i][j] << " ";
        else cout << b[i] << "\n";

    vector<ld> res(n);
    bool f = 0;
    // int cur = n-1;



    for(int i = n-1;i >= 0;i --)
    {
        ld dev = 0;

        int cap = n-1;
        // for(int f = 0;f < n;f ++ ) if(a[p[i]][f]) cap = min(cap,f);

        // for(int f = i+1;f < n;f ++)

        for(int f = i+1;f < n;f ++) dev += a[p[i]][f] * res[f];
        if(fabs(a[p[i]][i]) <= 1e-8){
            if(fabs(dev - b[p[i]]) < 1e-8) f = 1;
            else return {-1,{}};
        } else res[i] = (b[p[i]] - dev)/a[p[i]][i];
    }
    return {f,res};
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ld>> a(n,vector<ld>(n));
    vector<ld> b(n);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j <= n;j ++) if(j == n) cin >> b[i];
        else cin >> a[i][j];
    auto [flag,val] = GaussianELI(a,b);
    // cout << flag << " ";
    if(flag != 0) cout << (flag == 1 ? 0 : flag)  << "\n";
    else 
    lop(i,0,n) cout << fixed << "x" << i << "=" << setprecision(2) << val[i] << "\n";
    // vector<
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
