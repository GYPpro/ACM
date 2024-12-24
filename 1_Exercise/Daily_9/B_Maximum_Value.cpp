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

int a[(int)3e6+5];

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    sort(all(arr));
    // set<int>
    for(auto x:arr) a[x] = x;
    int prf = 0;
    for(int i = 0;i < 3e6+2;i ++)
        if(a[i]) swap(prf, a[i]);
        else a[i] = prf;
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int MEX = prf*2;
    int maxans = 0;
    for(auto it:arr)
    {
        int cur = it * 2;
        while(cur <= MEX) {
            maxans = max(maxans,a[cur]%it);
            // cout << a[cur] << " " << it << " : " << a[cur] % it << "\n";
            cur += it;
        }
    }
    // lop(i,1,10) cout << i << " " << a[i] << "\n";
    cout << maxans << "\n";
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
