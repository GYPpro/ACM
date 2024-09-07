// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

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
    cin >> n >> m;
    vector<vector<int>> ini(n+1,vector<int>(m+1));
    lop(i,1,n+1)
        lop(j,1,m+1)
        {
            char c;
            cin >> c;
            ini[i][j] = c == '#';  
        }
    pii colRange,rowRange; //[ fi,se];
    int curSize = 0;
    auto update = [&](pii p) -> void {
        colRange = {min(colRange.fi,p.fi),max(colRange.se,p.fi)};
        rowRange = {min(rowRange.fi,p.se),max(rowRange.se,p.se)};
    };

    vector<int> iniColSum(n+1),iniRowSum(m+1);
    lop(i,1,n+1)
        lop(j,1,m+1)
            iniColSum[i] += !ini[i][j],iniRowSum[j] += !ini[i][j];

    auto inrange = [&](pii p) -> bool {
        if(p.fi <= 0 || p.fi > n) return 0;
        if(p.se <= 0 || p.se > m) return 0;
        return ini[p.fi][p.se];
    };

    vector<pii> tr = {
        {1 ,0},
        {-1,0},
        {0,-1},
        {0, 1}
    };

    conj_diff_2 div(n+1,m+1);

    vector<vector<int>> vst(n+1,vector<int>(m+1));

    // function<void(pii)> dfs = [&](pii p) -> void {
    //     update(p);
    //     if(vst[p.fi][p.se]) return;
    //     vst[p.fi][p.se] = 1;
    //     // cout << "dfs:" << p.fi << " " << p.se << "\n";
    //     curSize ++;
    //     for(auto x:tr)
    //     {
    //         pii t = {p.fi + x.fi,p.se + x.se};
    //         if(!inrange(t)) continue;
    //         else dfs(t);
    //     }
    // };
    


    vector<int> colSum(n+6),rowSum(m+6);

    lop(i,1,n+1)
        lop(j,1,m+1)
        {
            if((!ini[i][j] ) ||  vst[i][j]) continue;
            colRange = {i,i},rowRange = {j,j},curSize = 0;
            // dfs({i,j});

            queue<pii> q;
            q.push({i,j});
            while(q.size()){
                auto p = q.front();
                q.pop();
                update(p);
                if(vst[p.fi][p.se]) continue;
                vst[p.fi][p.se] = 1;
                // cout << "dfs:" << p.fi << " " << p.se << "\n";
                curSize ++;
                for(auto x:tr)
                {
                    pii t = {p.fi + x.fi,p.se + x.se};
                    if(!inrange(t) || vst[t.fi][t.se]) continue;
                    else q.push(t);
                }
            }
            // cout << colRange.fi << " " << colRange.se << "\n";
            // cout << rowRange.fi << " " << rowRange.se << "\n";
            div.modify({colRange.fi-1,rowRange.fi-1},{colRange.se+1,rowRange.se+1},curSize);
            colSum[colRange.fi-1] += curSize,colSum[colRange.se+2] -= curSize;
            rowSum[rowRange.fi-1] += curSize,rowSum[rowRange.se+2] -= curSize;
        }

    lop(i,1,n+1) colSum[i] += colSum[i-1];
    lop(i,1,m+1) rowSum[i] += rowSum[i-1];

    int ans = 0;
    
    prfx_2 prf(div.cacu());

    // for(auto x:div.cacu())
    // {
    //     for(auto y:x)
    //      cout << y << " ";
    //      cout << "\n";
    // }

    lop(i,1,n+1)
        lop(j,1,m+1)
        {
            // cout << i << " " << j << " : ";
            // cout << colSum[i] << " " <<  rowSum[j] << " " << prf.getsum({i,j},{i,j}) << " " << iniColSum[i] << " " << iniRowSum[j]  << "\n";
            ans = max(ans,colSum[i] + rowSum[j] - prf.getsum({i,j},{i,j}) + iniColSum[i] + iniRowSum[j] - (!ini[i][j]));
        }
    cout << ans << "\n";
    // cout << prf.getsum({1,2},{1,2}) << "\n";
}


signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();
    // cout << "ac\n";
    // test();

    // system("pause");

    return 0;
}
