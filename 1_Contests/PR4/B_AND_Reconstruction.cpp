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
        // n--;
        vector<int> a(n+1);
        lop(i,1,n) cin >> a[i];
        vector<int> orsum(n+2);
        lop(i,1,n+1) orsum[i] = a[i] | a[i-1];

        // lop(i,0,n-1) cout << orsum[i] << " "; cout << "\n";
        // for(auto x:orsum) cout << x << " "; cout << "\n";

        // for(auto x:a) cout << x << " "; cout << "\n";
        lop(i,1,n)  if((orsum[i] & orsum[i+1]) != a[i]) {cout << -1 << "\n"; return;}
        lop(i,1,n+1) cout << orsum[i] << " "; cout << "\n";
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