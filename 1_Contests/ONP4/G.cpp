#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
void solve()
{
    int n,m;
    cin >> n >> m;
    // vector<vector<int>> mtx(n+1,vector<int>(m+1));
    // auto cac = [&](int x) -> int {
    //     int t = 1;
    //     while(t * t <= x) t ++;
    //     return t-1;
    // };
    cout << (int)sqrt(n)*(int)sqrt(m) << "\n";
    // // [i row][j col]
    // auto flipcol = [&](int j) -> void {
    //     lop(i,1,mtx.size()) 
    //         mtx[i][j] ^= 1;
    // };
    // auto fliprow = [&](int i) -> void {
    //     lop(j,1,mtx[0].size()) 
    //         mtx[i][j] ^= 1;
    // };
    // lop(i,1,n+1)
    //     lop(j,1,n+1)
    //         lop(ki,1,n+1)
    //             lop(kj,1,n+1)
    //                 if(ki * i > n || kj * j > m) continue;
    //                 else mtx[ki * i ][kj * j ] ^= 1;
    //                 // else flipcol(ki * i ),fliprow(kj * j );
    // lop(i,1,n+1){
    //     lop(j,1,m+1)
    //         cout << mtx[i][j] << " ";
    //     cout << "\n";
    // }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}