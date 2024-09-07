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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    int cntd = 0;
    for(auto x:arr) if(x%2) cntd ++;
    vector<vector<int>> mx(2);
    for(auto x:arr) mx[x%2].pb(x);
    sort(all(mx[0])),sort(all(mx[1]));
    if(cntd == 0 || cntd == n){cout << 0 << "\n";return;}
    if(mx[0].size() < 2) {
        // cout << "?\n";
        if(mx[0][mx[0].size()-1] > mx[1][mx[1].size()-1])
            cntd --;
    } else 
    {
        int sum  = mx[1][mx[1].size()-1];
        for(int i = 0;i < mx[0].size();i ++){ 
            if(mx[0][i] > sum)
            {
                cntd --;
                sum += mx[0][mx[0].size()-1];
                sum += mx[0][i];
            }
            else sum += mx[0][i];
        } 
    }
        // if(mx[0][mx[0].size()-1] > mx[1][mx[1].size()-1]+mx[0][mx[0].size()-2])
            // cntd --;
    // for(auto x:arr) mx[x%2] = max(mx[x%2],x);
    // if(mx[1] < mx[0]) cntd--;
    cout <<max(0LL, n - cntd) << "\n";
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

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
