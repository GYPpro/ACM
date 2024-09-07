#include <bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i = a;i < b;i ++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        // std::iota(f.begin(), f.end(), 0);
        for(int i = 0;i < n;i ++) f[i] = i;
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mtx(n,vector<int>(m));
    lop(i,0,n)
        lop(j,0,m)
        {
            char t;
            cin >> t;
            mtx[i][j] = t == '.';
        }
    
    auto ifDrop = [&](pii idx)-> bool {
        if(idx.fi < 0 || idx.fi >= n) return 1;
        if(idx.se < 0 || idx.se >= m) return 1;
        return !mtx[idx.fi][idx.se];
    };
    auto inMtx = [&](pii idx)-> bool {
        if(idx.fi < 0 || idx.fi >= n) return 0;
        if(idx.se < 0 || idx.se >= m) return 0;
        return 1;
    };

    vector<vector<int>> cnj(n+1);
    
    auto i2s = [&](array<int,4> i) {
        return  i[0] * m * n * m +
                i[1] * n * m +
                i[2] * m +
                i[3];
    };

    auto s2i = [&](int s) -> array<int,4> {
        return { s / (m * n * m),
                 s / (n * m) % m,
                 s / m % n,
                 s % m            };
    };

    // map<array<int,4>,int> i2s;
    // map<int,array<int,4>> s2i;
    vector<int> vst(n*m*n*m+100,-1);
    DSU dsu(n*m*n*m+100);
    

    function<bool(int)> dfs = [&](int p) -> bool {
        auto [ax,ay,bx,by] = s2i(p);
        pii a = {ax,ay},b = {bx,by};
        // cout << "dfs: " << a.fi << " " << a.se << " | " << b.fi << " " << b.se << " " << p << "\n";
        if(vst[dsu.find(p)] != -1) return vst[dsu.find(p)];
        vst[dsu.find(p)] = 0;
        if(ifDrop(b)) return 1;
        bool flag = 0;

        if( (!ifDrop({a.fi+1,a.se})) && inMtx({b.fi+1 ,b.se}))
            flag |= dfs(i2s({ a.fi+1 ,a.se ,  b.fi+1 ,b.se}) );


        if( (!ifDrop({a.fi-1,a.se})) && inMtx({b.fi-1 ,b.se})) 
            flag |= dfs(i2s({ a.fi-1 ,a.se ,  b.fi-1 ,b.se}) );


        if( (!ifDrop({a.fi,a.se+1})) && inMtx({b.fi ,b.se+1})) 
            flag |= dfs(i2s({ a.fi ,a.se+1 ,  b.fi ,b.se+1}) );


        if( (!ifDrop({a.fi,a.se-1})) && inMtx({b.fi ,b.se-1})) 
            flag |= dfs(i2s({ a.fi ,a.se-1 ,  b.fi ,b.se-1}) );

        if( (!ifDrop({a.fi+1,a.se})) && ifDrop({b.fi+1,b.se})) flag |= 1;
        if( (!ifDrop({a.fi-1,a.se})) && ifDrop({b.fi-1,b.se})) flag |= 1;
        if( (!ifDrop({a.fi,a.se+1})) && ifDrop({b.fi,b.se+1})) flag |= 1;
        if( (!ifDrop({a.fi,a.se-1})) && ifDrop({b.fi,b.se-1})) flag |= 1;

        if(!flag) return vst[dsu.find(p)] = flag;
        
        if((!ifDrop({a.fi+1,a.se})) && inMtx({b.fi+1 ,b.se})) dsu.merge(p,i2s({ a.fi,a.se, b.fi+1 ,b.se}));
        
        if((!ifDrop({a.fi-1,a.se})) && inMtx({b.fi-1 ,b.se})) dsu.merge(p,i2s({ a.fi,a.se, b.fi-1 ,b.se}));
        
        if((!ifDrop({a.fi,a.se+1})) && inMtx({b.fi ,b.se+1})) dsu.merge(p,i2s({ a.fi,a.se, b.fi ,b.se+1}));
        
        if((!ifDrop({a.fi,a.se-1})) && inMtx({b.fi ,b.se-1})) dsu.merge(p,i2s({ a.fi,a.se, b.fi ,b.se-1}));

        return vst[dsu.find(p)] = flag;
    };

    // map<pii,int> vst;
    // a beat b? 1:0
    // function<bool(pii,pii)> dfs = [&](pii a,pii b) -> bool {
    //     // cout << a.fi << " " << a.se << " | " << b.fi << " " << b.se << "\n";
    //     if(vst.find(a) != vst.end()) return vst[a];
    //     vst[a] = 0;
    //     if(ifDrop(b)) return 1;
    //     bool flag = 0;
    //     if( (!ifDrop({a.fi+1,a.se})) ) flag |= dfs({ a.fi+1 ,a.se},{ b.fi+1 ,b.se});
    //     if( (!ifDrop({a.fi-1,a.se})) ) flag |= dfs({ a.fi-1 ,a.se},{ b.fi-1 ,b.se});
    //     if( (!ifDrop({a.fi,a.se+1})) ) flag |= dfs({ a.fi ,a.se+1},{ b.fi ,b.se+1});
    //     if( (!ifDrop({a.fi,a.se-1})) ) flag |= dfs({ a.fi ,a.se-1},{ b.fi ,b.se-1});
    //     return vst[a] = flag;
    // };
    int ans = 0;
    lop(i,0,n)
        lop(j,0,m)
        {
            if(!mtx[i][j]) continue;
            bool f = 1;
            lop(k,0,n)
                lop(l,0,m)
                {
                    if(k == i && l == j) continue;
                    if(!mtx[k][l]) continue;
                    // vst.clear();
                    int m = i2s({i,j,k,l});
                    // cout << "et : " << i << " " << j << " | " << k << " " << l << " " << m << "\n";
                    if(vst[dsu.find(m)] == -1) f &= dfs(m);
                    else f &= vst[dsu.find(m)];
                    // cout << f << "\n";
                    // cout << "----\n";
                }
            // cout << "for:" << i << " " << j << ": " << f << "\n";
            ans += f;
        }
    cout << ans << "\n";

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}