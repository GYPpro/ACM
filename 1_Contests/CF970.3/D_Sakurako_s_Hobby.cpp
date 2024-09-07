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
    vector<vector<int>> rings;
    vector<vector<int>> cnj(n+1);
    vector<int> q(n+1);
    lop(i,1,n+1) cin >> q[i];
    string s;
    cin >> s;
    vector<int> vst(n+1);
        vector<int> rt;
    function<void(int)> getR = [&](int f) -> void {
        if(vst[f]) return;
        vst[f] = 1;
        rt.pb(f);
        getR(q[f]);
    };

    lop(i,1,n+1) if(!vst[i]) getR(i),rings.pb(rt),rt.clear();

    vector<int> ans(n+1);

    for(auto x:rings)
    {
        int cnt = 0;
        for(auto y:x) cnt += s[y-1] == '0';
        for(auto y:x) ans[y] = cnt;
    }

    lop(i,1,n+1) cout << ans[i] << " ";cout <<"\n";

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
