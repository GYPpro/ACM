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
    int n,p;
    cin >> n >> p;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    if(n == 1) {
        if(arr[0] == 2) p--;
        cout << p-1 << "\n";
        return;
    }
    map<int,int> vst,up;
    for(auto x:arr) vst[x] ++;
    int ptr = arr.size()-2;
    while(ptr >= 0 && arr[ptr] == p-1) ptr --;
    // cout << ptr << "\n";
    if(ptr < 0) up[1] ++;
    else up[arr[ptr]+1] ++;
    // vst[arr[arr.size()-2]+1] ++;
    // if(arr[arr.size()-2]+1 == p){
    //     if(n >= 3) vst[arr[arr.size()-3]+1] ++;
    //     else vst[1] ++;
    // }
    int cnt = 0;
    int c = arr.back() + p;
    while(vst[c%p]) {
        c --;
        cnt ++;
    }
    //c
    c %= p;
    int cur = max(0LL, p-cnt);
    if(c < arr.back()){
        // cout << c << " ";
        c =  arr.back() + p;
        cnt = 0;
        vst[0] = up[0] = 0;
        while(vst[c%p] || up[c%p]) {
            c --;
            cnt ++;
        }
        // cout << c << " ";
        // cout << ans + (p-cnt) << "\n";
        // c=  arr.bac) + p;
        // while(vst[c%p] || up)
    }
    // if(up[c%p]) cout << min(max(0LL,p-cnt),max(0LL,p-arr.back))
    // cout << cnt << "\n";
    cout <<min(cur,max(0LL, p-cnt)) << "\n";
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
    return 0;
}
