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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> gncing(n+1);
    
    auto print = [&]() -> void {
        int sum = 0;
        lop(i,0,n) sum += gncing[i];
        if(sum % k != 0) return;
        lop(i,0,n) cout << gncing[i] << " \n"[i == n-1];
    };

    function<void(int)> dfs = [&](int l )-> void{
        if(l >= n) print();
        else {
            lop(i,1,a[l]+1)
            {
                gncing[l] = i;
                dfs(l+1);
            }
        }
    };
    dfs(0);
}
 
signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
