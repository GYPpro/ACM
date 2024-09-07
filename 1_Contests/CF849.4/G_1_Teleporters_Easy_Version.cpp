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
    int n,c;
    cin >> n >> c;
    vector<int> arr(n+1);
    // for(auto &x:arr) cin >> x;
    lop(i,1,n+1) cin >> arr[i];
    lop(i,1,n+1) arr[i] += i;
    arr[0] = INF;
    sort(all(arr));
    int sum = 0;
    int cnt = 0;
    lop(i,0,n)
    {
        sum += arr[i];
        if(sum > c) break;
        cnt ++;
    }
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
