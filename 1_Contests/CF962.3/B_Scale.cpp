// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int k,n;
        // cin >> k >> n;
        cin >> n >> k;
        vector<vector<char>> mtx(n,vector<char>(n));
        for(auto &x:mtx)
            for(auto &y:x)
                cin >> y;
        vector<vector<char>> ans(n/k,vector<char>(n/k));
        for(int i = 0;i * k < n;i ++)
            for(int j = 0;j * k < n;j ++)
                ans[i][j] = mtx[i*k][j*k];
        for(auto &x:ans)
        {
            for(auto &y:x)
                cout << y ;
            cout << "\n";
        }
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}