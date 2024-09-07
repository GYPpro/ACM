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
    // freopen("01.in","r",stdin);
    int maxn = 1e6+5;
    vector<int> c3(maxn);
    auto mods = [](int _n) -> int  {
        int cnt = 0;
        while(_n)
        {
            _n /= 3;
            cnt ++;
        }
        return cnt;
    };
    lop(i,0,maxn) c3[i] = mods(i);
    int q;
    cin >> q;
    vector<int> prf(maxn);
    lop(i,1,maxn) prf[i] = prf[i-1] + c3[i];
    // lop(i,1,10) cout << prf[i] << " " << c3[i] << "\n";
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << prf[r]-prf[l-1] + c3[l] << "\n";
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
    freopen("01.in","r",stdin);
    freopen("01.out","w",stdout);
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
