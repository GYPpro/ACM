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
    auto check = [&]() -> bool {
        lop(i,0,arr.size()) if(arr[i] == i+1) return 1;
        return 0;
    };
    int ans = 0;
    while(!check())
    {
        multiset<int> tbm;
        for(int i = (int)arr.size()-(int)2;i >= 0;i --)
        {
            if(arr[i] == i+1) tbm.insert(i),tbm.insert(i+1),i--,ans ++;
        }
        vector<int> tn;
        lop(i,0,arr.size()) if(tbm.find(i) != tbm.end()) continue;
        else tn.pb(arr[i]); 
        arr = tn;
        for(auto x:arr) cout << x << " ";cout << "\n";
        for(auto x:tbm) cout << x << " ";
        system("pause");
    }
    cout << ans << "\n";
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
