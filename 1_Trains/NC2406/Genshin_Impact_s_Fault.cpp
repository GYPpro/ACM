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
    string s;
    cin >> s;
    // cout << s << "\n";
    bool ifup = 0;
    int sum4 = 0,sum5 = 0;
    bool check = 1;
    lop(i,0,s.size())
    {
        if(s[i] == '3') sum4 ++,sum5 ++;
        if(s[i] == '4') sum4 = 0,sum5 ++;
        if(s[i] == '5') {
            sum5 = 0;
            sum4 = 0;
            if(ifup) {
                check = 0;
                break;
            }
            else ifup = 1;
        }
        if(s[i] == 'U') sum5 = 0,sum4 = 0,ifup = 0;
        if(min(sum4,sum5) > 9 || sum5 > 89) {check = 0;break;}
    }
    if(check) cout << "valid\n";
    else cout << "invalid\n";
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
