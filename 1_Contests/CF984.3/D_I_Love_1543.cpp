// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
                     tree_order_statistics_node_update>;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mtx(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            mtx[i][j] = c - '0';
        }
    vector<int> linner;
    pii beginner = {1, 1};
    // int cnt = 0;
    // vector<vector<int>> vst(n+1,vector<int>(m+1));
    // map<pii,pii> tr = {
    //     {{0,1}, {1,0}},
    //     {{1,0}, {0,-1}},
    //     {{0,-1},{-1,0}} };
    // function<void,pii
    // auto next = [&](pii cur) -> int {
    //     auto [i,j] = cur;
    //     if(i < )
    // };
    int cnt = 0;
    while (beginner.fi <= n / 2 && beginner.se <= m / 2)
    {
        linner.clear();
        for (int j = beginner.se; j <= m - beginner.se; j++)
            linner.push_back(mtx[beginner.fi][j]);

        for (int j = beginner.fi; j <= n - beginner.fi; j++)
            linner.push_back(mtx[j][m - beginner.se+1]);

        for (int i = m - beginner.se+1; i >= beginner.se; i--)
            linner.push_back(mtx[ n - beginner.fi+1][i]);

        for (int j = n - beginner.se; j >= beginner.se+1; j--)
            linner.push_back(mtx[j][beginner.se]);
        for (int j = beginner.se; j <= m - beginner.se; j++)
            linner.push_back(mtx[beginner.fi][j]);

        for (int j = beginner.fi; j <= n - beginner.fi; j++)
            linner.push_back(mtx[j][m - beginner.se+1]);

        for (int i = m - beginner.se+1; i >= beginner.se; i--)
            linner.push_back(mtx[ n - beginner.fi+1][i]);

        for (int j = n - beginner.se; j >= beginner.se+1; j--)
            linner.push_back(mtx[j][beginner.se]);

        int mex = linner.size()/2  + 3;
        for(int i = 3;i < mex;i ++){
            if(
                linner[i] == 3 &&
                linner[i-1] == 4 &&
                linner[i-2] == 5 &&
                linner[i-3] == 1
                )  cnt ++;
        }
        // for (auto x : linner)
        //     cout << x << " ";
        // cout << "\n";
        beginner.fi++, beginner.se++;
        // for(int i = beginner.se;i <e;i ++) linner.push_back(mtx[beginner.fi][i]);
    }
    cout << cnt << "\n";
    // cout << "-------\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in", "r", stdin);
    freopen("G.A.ptc", "w", stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
