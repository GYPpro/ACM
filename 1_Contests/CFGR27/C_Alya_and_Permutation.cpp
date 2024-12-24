// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    iota(all(arr),0);
    // int p = 1;
    if(n == 5) {
        cout << "5\n2 1 3 4 5\n";
        return;
    }
    if(n%2) n--;
    // if(n%2){
        if(__builtin_popcountl(n) == 1) {
            n -= 2;
        }
        int t = 1;
        while(t < n) t <<= 1;
        t >>= 1;
        // swap(arr[n],arr[t-1]);
        arr[n] = t-1;
        for(int i = n-1;i >= t-1;i --) arr[i] = i+1;
        swap(arr[n-1],arr[n-2]);
    // } else {
        // n --;
    // }
    // for(int i = 1;i <= n/2 && p < n;i ++) arr[p] = i,p += 2;
    // p = 0;
    // for(int i = n;i >= n/2 && p < n;i --) arr[p] = i,p += 2;
    int k = 0;
    for(int i = 1;i < arr.size();i ++) 
        if(i % 2 == 0) k |= arr[i];
        else k &= arr[i];
    cout << k << "\n"; 
    for(int i = 1;i < arr.size();i ++) cout << arr[i] << " ";cout << "\n";
}

void check(){
    int n;
    cin >> n;
    int k = 0;
    lop(i,1,n+1)
    {
        int t;
        cin >> t;
        if(i%2) k &= t;
        else k |= t;
    }
    cout << k << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    // while(T--) check();
    return 0;
}
