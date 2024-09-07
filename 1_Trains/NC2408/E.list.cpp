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
    auto getfecsum = [](int _n) -> int{
        int sum = 0;
        while(_n)
        {
            sum += _n%10;
            _n /= 10;
        }
        return sum;
    };
    map<int,vector<int>> cnt;
int solve(int n)
{
    int ans = 0;
    lop(m,1,n)
    {
        if(n%m == getfecsum(m)) cnt[m].pb(n);
    }
    return ans;
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

    // for (int i = 0; i < T; i++) cout << bitset<10>(getfecsum(i)) << " " <<getfecsum(i) << "-"<< i << " : " << solve(i) << " "  << "\n";
    lop(i,0,T) solve(i);
    for(auto [u,v]:cnt)
    {
        cout << u << " : ";
        for(auto x:v) cout << x << " ";
        cout << "\n";
    }

    system("pause");

    return 0;
}
