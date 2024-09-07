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

void mlist()
{
    vector<int> dates = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    auto acdate = [&](int a,int b,int c) -> bool {
        if(b == 2) if(c > dates[b]+(a%4 == 0)) return 0;
        if(b > 12) return 0;
        if(c > dates[b]) return 0;
        return 1;
    };

    map<array<int,3>,int> rec;
    function<int(int,int,int)> dfs = [&](int a,int b,int c) -> int {
        // cout << a << " " << b << " " << c << " to \t ";
        if(!acdate(a,b,c)) return -INF;
        // if(c > dates[b]+(a%4 == 0 && b == 2)) {c-=dates[b]+(a%4 == 0 && b == 2);b ++;}
        // if(b > 12) {a ++;b -= 12;}
        // cout << a << " " << b << " " << c << "\t\n";
        if(rec.find({a,b,c}) != rec.end()) return rec[{a,b,c}];
        if(a >= 2024 && b >= 8 && c >= 2) return -INF;
        int l = dfs(a,b+1,c);
        int r = dfs(a,b,c+1);
        bool rt = (l == 0 || r == 0);
        // cout << a << "," << b << "," << c << " :\t " << rt << "\n";
        return rec[{a,b,c}] = rt;
    };
    rec[{2024,8,1}] = 0,rec[{2024,7,1}] = 1,rec[{2024,7,31}] = 1;
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(dfs(a,b,c)) cout << "YES\n";
        else cout << "NO\n";
    }
    // dfs(2023,1,1);
    // rec{[]}
}

void solve()
{
    
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

    mlist();

    for (int i = 0; i < T; i++) solve();

    system("pause");

    return 0;
}
