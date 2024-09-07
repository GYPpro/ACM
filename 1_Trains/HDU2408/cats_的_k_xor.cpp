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
    int a,b,c;
    cin >> a >> b >> c;
    // if(a == b  && b == c && c == 0) {cout << -1 << "\n";return;}
    // vector<int> future_category
    int facsum = 0;
    int t = a + b - c;
    if(t == 0) {cout << -1 << "\n";return;}
    if(t < 0) {cout << 0 << "\n";return;}
    int sum = 0;
    auto check = [&](int k) -> bool {
        if (k == 1) return 0;
        auto dis = [&](int a) -> vector<int>{
            vector<int> rt;
            while(a)
            {
                rt.pb(a%k);
                a /= k;
            }
            return rt;
        };

        vector<int> fa = dis(a),fb = dis(b),fc = dis(c);
        // if(fc.size() < )
        while(fc.size() < max(fa.size(),fb.size())) fc.pb(0);
        lop(i,0,fc.size())
        {
            // int ta = 
            int ta = 0,tb = 0;
            if(i < fa.size()) ta = fa[i];
            if(i < fb.size()) tb = fb[i];
            if(fc[i] == (ta+tb)%k) continue;
            else return 0;
        }
        // int
        // cout << k << " ";
        return 1;
    };
    for(int i = 1;i * i <= t ;i ++)
    {
        if(t%i == 0) {
            if(check(i)) sum ++;
            if(t/i != i && check(t/i)) sum ++;
            // cout << i << " ";
            // while(t%i == 0) t /= i;
        }
    }
    cout << sum<< "\n";
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
