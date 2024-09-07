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
    int k,a,b;
    // if(a > b) swap(a,b);//a < b
    cin >> k >> a >> b;
    if(k <= min(b,a)) cout << "Yes\nNo\n";
    else {
        if(((k+a-1))/a == (k+b-1)/b) {
            if((((k+a-1))/a)%2) cout << "Yes\nNo\n";
            else cout << "No\nYes\n";
        } else cout << "Yes\nYes\n";
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
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
