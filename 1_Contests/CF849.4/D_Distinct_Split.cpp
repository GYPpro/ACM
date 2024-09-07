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
    vector<vector<int>> prfx(26,vector<int>(n+1));
    vector<vector<int>> serfx(26,vector<int>(n+1));
    for(int i = n-1;i >= 0;i --)
    {
        lop(j,0,26) serfx[j][i] = serfx[j][i+1];
        serfx[s[i]-'a'][i] = serfx[s[i]-'a'][i+1] | 1; 
    }
    int ans = 0;
    lop(j,0,26) ans += serfx[j][0];
    prfx[s[0]-'a'][0] = 1;
    lop(i,1,n)
    {
        int tmp = 0;
        lop(j,0,26) prfx[j][i] = prfx[j][i-1];
        prfx[s[i]-'a'][i] = prfx[s[i]-'a'][i-1] | 1;
        lop(j,0,26) tmp += prfx[j][i-1];
        lop(j,0,26) tmp += serfx[j][i];
        ans = max(ans,tmp); 
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
