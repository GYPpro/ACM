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

const int mod = 1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<int> FIB(n+10);
    FIB[1] = 1,FIB[2] = 2,FIB[3] = 4;
    lop(i,4,n+1) FIB[i] = (FIB[i-1] + FIB[i-2] + FIB[i-3]) % mod;
    cout << FIB[n] << "\n";
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

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
