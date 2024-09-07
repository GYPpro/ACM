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
    string s;
    cin >> s;
    if(((int)sqrt(n)) * (int)sqrt(n) == n) {
        int t = sqrt(n);
        lop(i,0,t)
            lop(j,0,t)
                {
                    char tar = '0' + ((i == 0 || i == t-1) || (j == 0 || j == t-1) );
                    if(s[i+t*j] == tar) continue;
                    else {
                        cout << "No\n";
                        return;
                    }
                }
        cout << "Yes\n";
    } else cout << "No\n";
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
