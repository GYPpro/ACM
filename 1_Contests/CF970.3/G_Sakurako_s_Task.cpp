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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    int t = arr[0];
    lop(i,1,n) if(arr[i] == 0) continue; else t = __gcd(t,arr[i]);
    if(t == 0) {cout << k << "\n";return;}
    if(n == 1) {
        cout << k - 1 + (arr[0] < k) << "\n";
        return;
    }
    int curc = 0;
    int curm = 1;
    int curMEX = 0;
    k --;
    n --;
    lop(i,0,n)
    {
        // curc += t-1;
        int cst =  t-1;
        if(k >= cst) curm += t,k -= cst;
        else {
            // curm --;
            break;
        }
        // if(curc)
    }
    cout << curm + k << "\n";
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
