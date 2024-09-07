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

// Version 2
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
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
        lop(i,0,n) cin >> arr[i];
        if(n == 1)
        {
            cout << 0 << "\n";
            return;
        }
        vector<int> div(n-1);
        lop(i,0,n-1) div[i] = abs(arr[i] - arr[i+1]);
        int t = div[0];
        lop(i,1,n-1) t = gcd(t,div[i]);
        cout << t << "\n";
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