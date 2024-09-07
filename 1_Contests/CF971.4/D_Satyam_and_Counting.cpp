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
    set<int> x0,x1;
    lop(i,0,n)
    {
        int x,y;
        cin >> x >> y;
        if(y) //y == 1
            x1.insert(x);
        else x0.insert(x);
    }
    int ans = 0;
    // int ans = x0.size() * x1.size();
    for(auto x:x0)
    {
        if(x0.find(x+2) != x0.end() && x1.find(x+1) != x1.end()) ans ++;
        if(x1.find(x) != x1.end()) ans += (int)x0.size()-1;
    }
    for(auto x:x1)
    {
        if(x1.find(x+2) != x1.end() && x0.find(x+1) != x0.end()) ans ++;
        if(x0.find(x) != x0.end()) ans += (int)x1.size()-1;
    }
    cout << ans << "\n";
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
