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
#define all(x) x.begin(), x.end()

using namespace std;

// bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n,l,d;
        cin >> n >> l >> d;
        int t;cin >> t;
        vector<int> arr(n-1);
        for(auto &x:arr) cin >> x;
        // vector<int> cur1;
        int cnt = 0;
        sort(all(arr));
        if(n < 4) {cout << "No\n";return;}
        if(t < l){ // arr[0] t arr[1] | arr[n-1]
            if(arr[1] >= l) {cout << "No\n";return;}
            if(arr[n-2]-min(t,arr[0]) <= d) {cout << "No\n";return;}
        } else { //t >= l arr[0] arr[1] arr[2] | t
            if(arr[2] >= l) {cout << "No\n";return;}
            if(t - arr[0] <= d) {cout << "No\n";return;}
        }
        // if(res[2] - res[0] > d) {cout << "Yes\n";return;}
        cout << "Yes\n";
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