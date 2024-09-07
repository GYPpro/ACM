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
        vector<vector<int>> cnj(n+1);
        vector<int> minn(n+1);
        vector<int> a(n+1);
        lop(i,1,n+1) cin >> a[i];
        lop(i,1,n)
        {
            int v;
            cin >> v;
            cnj[i+1].pb(v);
            cnj[v].pb(i+1);
        }
        auto dfs = [&](auto self,int p,int f)-> int {
            int t = a[p];
            int minsumt = INT_MAX;
            for(auto x:cnj[p])
            {
                if(x != f) minsumt = min(minsumt,self(self,x,p));
            }
            if(minsumt == INT_MAX) return a[p];
            if(minsumt < a[p]) return minsumt;
            else return (a[p]+minsumt)/2;
        };
        int minsumt = INT_MAX;
        for(auto x:cnj[1]) minsumt = min(minsumt,dfs(dfs,x,1));
        cout << minsumt + a[1] << "\n";
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