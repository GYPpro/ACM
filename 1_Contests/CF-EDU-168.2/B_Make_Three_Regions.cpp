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
        int n;
        cin >> n;
        vector<string> mtx(2);
        for(auto &x:mtx) cin >> x;
        vector<string> cmp1 = {"...","x.x"};
        vector<string> cmp2 = {"x.x","..."};
        int cnt = 0;
        lop(i,0,n-2)
        {
            string submtx1,submtx2;
            for(int j = i;j < i+3;j ++)
                submtx1.pb(mtx[0][j]),submtx2.pb(mtx[1][j]);
            if(
                (cmp1[0] == submtx1 && cmp1[1] == submtx2) ||
                (cmp1[1] == submtx1 && cmp1[0] == submtx2))
                 cnt++;
        }
        cout << cnt << "\n";
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