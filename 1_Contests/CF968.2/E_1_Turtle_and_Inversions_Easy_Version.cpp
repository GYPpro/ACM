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
    auto push =  [&](int i,int k) -> void {
        int t = arr[i+k-1];
        lop(t,i,i+k) arr[t+1] = arr[t];
        arr[i] = t;
    };
    lop(i,0,n) arr[i] = n-i;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        push(l,r-l+1);
    }
    int cnt = 0;
    lop(i,0,n)
        lop(j,i+1,n)
            if(arr[j] < arr[i]) cnt ++;
    cout << cnt << "\n";
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
