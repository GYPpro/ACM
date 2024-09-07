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
    vector<vector<int>> mtx3 = {
        {1,0,1},
        {1,1,0},
        {1,1,1}
    };
    vector<vector<int>> mtx2 = {
        {1,1},
        {1,1}
    };
    vector<vector<int>> mtx1 = {{1}};
    vector<vector<int>> mtx(n,vector<int>(m));
    for(auto &xx:mtx) for(auto &x:xx){
        char t;
        cin >> t;
        x = t-'0';
    }

    auto cmp3 = [&](int i,int j) -> bool {
        lop(ti,0,3)
            lop(tj,0,3)
                if(mtx[i-ti][j+tj] == mtx3[2-ti][tj]) continue;
                else return 0;
        return 1;
    };
    auto cmp2 = [&](int i,int j) -> bool {
        lop(ti,0,2)
            lop(tj,0,2)
                if(mtx[i-ti][j+tj] == mtx2[1-ti][tj]) continue;
                else return 0;
        return 1;
    };
    auto cmp1 = [&](int i,int j) -> bool {
        lop(ti,0,1)
            lop(tj,0,1)
                if(mtx[i+ti][j+tj] == mtx1[ti][tj]) continue;
                else return 0;
        return 1;
    };

    vector<vector<int>> vst(n,vector<int>(m));
    auto EXT = [&](int i,int j) -> int {
        int exp = 0;
        auto check = [&](int dli,int dlj,int rti,int rtj) -> bool
        {
            if(dli - rti < 0 || dlj + rtj >= m) return 0;
            int tar = (rti == 0 || rtj == 0) || (rti == rtj);
            return vst[dli - rti][dlj + rtj] == tar;
        };
        auto checkALL = [&](int dli,int dlj,int exp) -> bool {
            lop(fii,0,exp) if(  check( dli,dlj,dli-fii-1,dlj+exp) == 0 ) return 0;
            lop(fii,0,exp) if(  check( dli,dlj,dli-exp,dlj+fii+1) == 0 ) return 0;
            return 1;
        };
        while(checkALL(i,j,exp)) exp++;
        return exp;
    };

    auto LOCK = [&](int ti,int tj,int exp) -> void {
        lop(i,0,exp)
            lop(j,0,exp)
                vst[ti-i][tj+j] = 1;
    };
    int ans = 0;
    lop(i,2,n)
        lop(j,0,m-2)
        {
            if(vst[i][j]) continue;
            int rt = 0;
            if(cmp3(i,j)) rt = EXT(i,j);
            ans = max(ans,rt);
            LOCK(i,j,rt); 
        }
    lop(i,1,n)
        lop(j,0,m-1)
            ans = max(ans,cmp2(i,j)?2LL:0LL);
    lop(i,0,n)
        lop(j,0,m)
            ans = max(ans,cmp1(i,j)?1LL:0LL);
    cout << ans << "\n";



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
