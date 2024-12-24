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


class prfx_2{
public:
    vector<vector<int>> mtx;
    int n,m;
    public:
    prfx_2(vector<vector<int>> _mtx){init(_mtx);};
    prfx_2() { };
    void init(vector<vector<int>> _mtx)
    {
        n = _mtx.size();
        m = _mtx[0].size();
        mtx.resize(n+1);
        for(auto &x:mtx) x.resize(m+1);
        lop(i,1,n+1)
            lop(j,1,m+1)
                mtx[i][j] = mtx[i-1][j] + mtx[i][j-1] - mtx[i-1][j-1] + _mtx[i-1][j-1];
    }

    int getsum(int x1,int y1,int x2,int y2)
    {
        x1 ++,x2 ++,y1 ++,y2 ++;
        return mtx[x2][y2] - mtx[x1-1][y2] - mtx[x2][y1-1] + mtx[x1-1][y1-1];
    }

    int getsum(pii d1,pii d2)
    {
        auto [x1,y1] = d1;
        auto [x2,y2] = d2;
        x1 ++,x2 ++,y1 ++,y2 ++;
        return mtx[x2][y2] - mtx[x1-1][y2] - mtx[x2][y1-1] + mtx[x1-1][y1-1];
    }

    vector<int> & operator[](std::size_t i)
    {
        return mtx[i];
    }

};

class conj_diff_2{
    vector<vector<int>> mtx;
    vector<vector<int>> prf;
    int n,m;
    public:

    conj_diff_2(int _n,int _m)
    {
        n = _n+1,m = _m+1;
        vector<vector<int>> initmp(n,vector<int> (m,0));
        init(initmp);
    }

    conj_diff_2(vector<vector<int>> _mtx)
    {
        this->init(_mtx);
    }

    conj_diff_2(){ }

    void init(vector<vector<int>> _mtx)
    {
        n = _mtx.size();
        m = _mtx[0].size();
        mtx.resize(n+2);
        for(auto &x:mtx) x.resize(m+2);
        prf.resize(n+2);
        for(auto &x:prf) x.resize(m+2);
        lop(i,1,n+1)
            lop(j,1,m+1)
                prf[i][j] = _mtx[i-1][j-1];
    }

    void modify(int x1,int y1,int x2,int y2,int k)
    {
        x1 ++,x2 ++,y1 ++,y2 ++;
        mtx[x1][y1] += k;
        mtx[x2+1][y1] -= k,mtx[x1][y2+1] -= k;
        mtx[x2+1][y2+1] += k;
    }

    void modify(pii d1,pii d2,int k)
    {
        this->modify(d1.fi,d1.se,d2.fi,d2.se,k);
    }

    vector<vector<int>> cacu()
    {
        auto res = prfx_2(mtx);
        vector<vector<int>> rst(n,vector<int>(m));
        lop(i,1,n+1)
            lop(j,1,m+1)
                rst[i-1][j-1] = prf[i][j] +  res[i+1][j+1];
        return rst;
    }

    vector<int> & operator[](std::size_t i)
    {
        return mtx[i];
    }
};



void solve()
{
    int n,m,q;
    cin >> n >> m >> q;

    vector<int> a(n),b(m);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;

    map<int,int> ca,cb;

    for(auto x:a) ca[x] = 1;
    for(auto x:b) cb[x] = 1;

    // for(auto [u,v]:ca) cout << u <<" ";cout << "\n";
    // for(auto [u,v]:cb) cout << u <<" ";cout << "\n";
    
    int suma = 0,sumb = 0;
    for(auto x:a) suma += x;
    for(auto x:b) sumb += x;
    int M = suma * sumb;
    // cout << M << "\n";
    while(q--){
        int x;
        cin >> x;
        // x = M - x;
        // x = -x;
        // cout << x << "\n";
        for(int i = 1;i*i <= (abs(x));i ++) {
            if(abs(x) % abs(i) == 0) {
                int s = i,v = x/i;
                // cout << s << " " <<v << "\n";
                // cout << "que:" << suma - s  << " " << sumb - v << "\n";
                if(ca[suma - s] && cb[sumb - v]) {
                    cout << "YES\n";
                    goto FORCES_CONTINUE;
                }
                s = -s,v = -v;
                // cout << s << " " <<v << "\n";
                // cout << "que:" << suma - s  << " " << sumb - v << "\n";
                if(ca[suma - s] && cb[sumb - v]) {
                    cout << "YES\n";
                    goto FORCES_CONTINUE;
                }
                swap(s,v);
                // cout << s << " " <<v << "\n";
                // cout << "que:" << suma - s  << " " << sumb - v << "\n";
                if(ca[suma - s] && cb[sumb - v]) {
                    cout << "YES\n";
                    goto FORCES_CONTINUE;
                }
                s = -s,v = -v;
                // cout << s << " " <<v << "\n";
                // cout << "que:" << suma - s  << " " << sumb - v << "\n";
                if(ca[suma - s] && cb[sumb - v]) {
                    cout << "YES\n";
                    goto FORCES_CONTINUE;
                }
            }
        }
        cout << "NO\n";
        FORCES_CONTINUE:;
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
