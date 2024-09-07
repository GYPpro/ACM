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
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        int bindigitmex = 0;
        int maxn = 0;
        for(auto x:arr) maxn = max(maxn,x);
        int t = maxn;
        while(t)
        {
            bindigitmex++;
            t >>= 1;
        }
        // cout << (1 << bindigitmex-1) << "\n";
        for(int j = bindigitmex-1;j >= 0;j --)
        {
            for(auto &x:arr) x = abs(x - (1 << j));
        }
        map<int,int> cnt;
        for(auto x:arr) cnt[x]++;
        if(cnt.size() <= 1) {
            if(cnt.begin()->first == 0) {
                cout << bindigitmex  << "\n";
                for(int j = bindigitmex-1;j >= 0;j --) cout << (1 << j) << " ";
                cout << "\n";
            } else {
                cout << bindigitmex +1 << "\n";
                for(int j = bindigitmex-1;j >= 0;j --) cout << (1 << j) << " ";
                cout << 1 << "\n";
            }
        } else cout << "-1\n";
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