// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin >> n >> m;
    // cout << n << " " << m << "\n";
    // return;
    vector<vector<int>> A(n,vector<int>(m));
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            cin >> A[i][j];
    string s;
    cin >> s;
    
    function<int(int,int)> f;
    if(s == "Max")
        f = [&](int i,int j) -> int {
            return max({A[i][j],A[i+1][j+1],A[i+1][j],A[i][j+1]});
        };
    else // s == "Floor"
        f = [&](int i,int j) -> int {
            return (long double)(A[i][j]+A[i+1][j+1]+A[i+1][j]+A[i][j+1]) / 4;
        };
    for(int i = 0;i < n-1;i ++) {
        for(int j = 0;j < m-1;j ++) cout << f(i,j) << " ";
        cout << "\n";
    }
}

signed main()
{
    // freopen("temp.in","r",stdin);
    // freopen("temp.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
