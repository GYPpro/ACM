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
        // int n;
        // cin >> n;
        string s;
        cin >> s;
        int n = s.size();
        vector<int> arr(n);
        lop(i,0,n)
            arr[i] = s[i] - '0';
        // for(auto &x:arr)
        //     cin >> x;
        vector<int> div(n+1);
        lop(i,1,n+1)
            div[i] = div[i-1] + (arr[i-1] == 0?-1:1);
        // for(auto x:div) cout << x<< " ";cout << "\n";
        map<int,vector<int>> cnt;
        lop(i,1,n-1) cnt[div[i]].pb(i);
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