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
    int n,m;
    cin >> n >> m;
    vector<int> arr(n+1);
    lop(i,1,n+1) {
        char t;
        cin >> t;
        arr[i] = (t == 'P');
    }
    vector<int> ans(n+1);
    lop(i,1,n+1){ 
        int t = m-i+1;
        if(t <= 0){ ans[i] = arr[i] ;continue;}
        int tar = i;
        if(t%2){
            tar -= i-1;
            tar += t/2;
        } else tar += t/2;
        ans[tar] = arr[i] ^ (t%2);
    }
    lop(i,1,n+1) cout << ans[i] << " ";
    cout << "\n";
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
