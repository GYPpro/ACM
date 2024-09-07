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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> mtx(n);
    for(auto &x:mtx) cin >> x;
    int cntx = 0,cnty = 0;
    lop(i,0,n)
    {
        int tmpcnty = 0;
        lop(j,0,m) if(mtx[i][j] == 'x') tmpcnty ++;
        if(tmpcnty) cntx ++;
        cnty = max(cnty,tmpcnty);
    }
    int t = __gcd(cntx,cnty);
    cntx /= t,cnty /= t;
    lop(i,0,cntx)
    {
        lop(j,0,cnty)
        {
            cout << "x";
        }cout << "\n";
    }

}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
