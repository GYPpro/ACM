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
    map<array<int,3>,int> rec;
    function<int(int,int,int)> dfs = [&](int a,int b,int c) -> int {
        if(c > dates[b]+(a%4 == 0 && b == 2)) {c-=dates[b]+(a%4 == 0 && b == 2);b ++;}
        if(b > 12) {a ++;b -= 12;}
        if(rec.find({a,b,c}) != rec.end()) return rec[{a,b,c}];
        if(a >= 2024 && b >= 8 && c >= 2) return -INF;
        int l = dfs(a,b+1,c);
        int r = dfs(a,b,c+1);
        if(c > dates[b%12+1]) l = -INF;
        bool rt = (l == 0 || r == 0);
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
    
    // system("pause");

    return 0;
}
