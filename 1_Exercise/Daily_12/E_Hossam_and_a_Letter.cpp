#pragma GCC optimize(2)

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
    int n,m;
    cin >> n >> m ;
    vector<vector<char>> s(n,vector<char>(m));
    for(auto &y:s) for(auto &x:y) cin >> x;
    vector<vector<int>> tmp(n,vector<int>(m));

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            tmp[i][j] = s[i][j] == '.';
    prfx_2 GOOD(tmp);

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            tmp[i][j] = s[i][j] == 'm';
    prfx_2 MID(tmp);

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            tmp[i][j] = s[i][j] == '#';
    prfx_2 BAD(tmp);
    
    auto ExtentUP = [&](int j1,int j2,int sep,int f) -> int {
        int l = -1,r = sep;
        sep --;
        while(l + 1 < r) {
            int mid = l + r + 1 >> 1;
            if(
                (BAD.getsum({mid,j1},{sep,j1}) + BAD.getsum({mid,j2},{sep,j2})) == 0 &&
                (MID.getsum({mid,j1},{sep,j1}) + MID.getsum({mid,j2},{sep,j2})) <= f
            ) r = mid;
            else l = mid;
        } l ++;
        // cout << "PASS";
        sep ++;
        // cout << "PASS UP extent at:" << format("j1:{} j2:{} sep:{} f:{} at: l {}\n",j1,j2,sep,f,l);
        return sep - l << 1;
    };
    auto ExtentDOWN = [&](int j1,int j2,int sep,int f) -> int {
        int l = sep ,r = n-1;
        sep ++;
        while(l + 1 < r) {
            int mid = l + r + 1 >> 1;
            if(
                (BAD.getsum({sep,j1},{mid,j1}) + BAD.getsum({sep,j2},{mid,j2})) == 0 &&
                (MID.getsum({sep,j1},{mid,j1}) + MID.getsum({sep,j2},{mid,j2})) <= f
            ) l = mid;
            else r = mid;
        } r;
        sep --;
        // cout << "PASS DOWN extent at:" << format("j1:{} j2:{} sep:{} f:{} at: r {}\n",j1,j2,sep,f,r);
        return r - sep << 1;
    };

    int MXLEN = 0;
    for(int i1 = 0;i1 < n;i1 ++)
        for(int j1 = 0;j1 < m;j1 ++)
            for(int j2 = 0;j2 < m;j2 ++)
            {
                if(j2 <= j1+1) continue;
                // else cout << j1 << " " << j2 << "\n";
                if(BAD.getsum({i1,j1},{i1,j2})) continue;
                int f = MID.getsum({i1,j1},{i1,j2});
                if(f > 1) 
                    continue
                    ;
                else if(f == 1) 
                {
                    int U0 = ExtentUP(j1,j2,i1,0)  ,
                        D0 = ExtentDOWN(j1,j2,i1,0);
                    
                    int X1 = U0+D0;
                    if(U0 && D0) X1 += (j2-j1+1);
                    else X1 = 0;
                    MXLEN = max(MXLEN,X1);
                }
                else 
                {
                    int U0 = ExtentUP(j1,j2,i1,0)  , U1 = ExtentUP(j1,j2,i1,1)  ,
                        D0 = ExtentDOWN(j1,j2,i1,0), D1 = ExtentDOWN(j1,j2,i1,1); 
                    
                    int X1 = U0+D1,X2 = U1+D0;
                    if(U0 && D1) X1 += (j2-j1+1);
                    else  X1 = 0;
                    if(U1 && D0) X2 += (j2-j1+1);
                    else X2 = 0;
                    MXLEN = max({MXLEN,X1,X2});
                }
            }
    cout << MXLEN << "\n";
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
    int n;
    cin >> n;
    vector<int> a(n);
    // iota(all(a),1);
    // shuffle(all(a),mt19937(random_device()()));
    // for(auto x:a) cout << x << " ";cout << "\n";

    // while(T--) solve();
    return 0;
}
