// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

vector<int> pri;
vector<int> vis;

void init(int n)
{
    vis.resize(n+1,0);
    // pri.pb(2);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]){
            pri.push_back(i);
            vis[i] = pri.size();
        }
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            if(vis[pri[j] * i] == 0) vis[pri[j] * i] = vis[pri[j]];
            if (i % pri[j] == 0)
                break;
        }
    }
    // return pri;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x; 
    int ans = 0;
    for(auto x:arr) ans ^= ((x%2 == 0) ? 0 : vis[x]);
    if(ans != 0) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    init(1e7+5);
    // lop(i,1,80) cout << i << ":"<< vis[i] << "\n";
    vis[3] = 2;
    vis[1] = 1;
    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
