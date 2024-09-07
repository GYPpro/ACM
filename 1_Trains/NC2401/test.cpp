#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

// #define map unordered_map
// #define set unordered_set
// #define pq priority_queue
#include <map>
#include <set>

// #define D

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
const int INF = 1145141919810LL;
const int mod = 2097152LL;
void sort(auto &x) { sort(x.begin(), x.end()); }
using namespace std;

void solve()
{
        int t, v;
        cin >> t >> v;

#ifdef D
        cout << t << " " << v << "\n";
#endif

        cout << t + v << "\n";


    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}