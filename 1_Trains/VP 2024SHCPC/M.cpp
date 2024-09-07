#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define lop(i,a,b) for(int i = a;i < b;i ++)
#define fi first
#define se second

void solve()
{
    int n;
    cin >> n;
    int mtxl = sqrt(n)+((int)sqrt(n)*sqrt(n) != n);
    // cout << mtxl << "\n";
    vector<vector<int>> mtx(mtxl+1,vector<int>(mtxl+1));
    lop(i,0,mtxl)
        lop(j,0,mtxl)
            mtx[i][j] = i*mtxl+j+1;
    set<pii> b,r;
    lop(i,0,mtxl)
        lop(j,0,mtxl-1)
        {
            if(mtx[i][j+1] <= n && mtx[i][j] <= n ) b.insert({mtx[i][j],mtx[i][j+1]});
            // if(mtx[i+1][j] <= n && mtx[i][j] <= n ) r.insert({mtx[i][j],mtx[i+1][j]});
        }
    lop(i,0,mtxl-1)
        lop(j,0,mtxl)
        {
            // if(mtx[i][j+1] <= n && mtx[i][j] <= n ) b.insert({mtx[i][j],mtx[i][j+1]});
            if(mtx[i+1][j] <= n && mtx[i][j] <= n ) r.insert({mtx[i][j],mtx[i+1][j]});
        }
    int mex = min(b.size(),r.size());
    int t = 0;
    cout << mex << "\n";
    for(auto it = b.begin();t < mex;++t,++it)
    {
        auto x = *it;
        cout << x.fi << " " << x.se << "\n";
    } t = 0;
    for(auto it = r.begin();t < mex;++t,++it)
    {
        auto x = *it;
        cout << x.fi << " " << x.se << "\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    //system("pause");
}