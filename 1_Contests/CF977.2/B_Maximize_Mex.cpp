// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_pii = tree<int, null_type, less<int>, rb_tree_tag,
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
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    map<int,int> freeval; 
    sort(all(arr));
    int MEX = 0;
    int p = 0;
    while(p < n) 
    {
        if(arr[p] == MEX) p ++,MEX ++;
        else {
            if(MEX > arr[p]) freeval[arr[p]%x] ++,p ++;
            else if(freeval[MEX%x] > 0) freeval[MEX%x] --,MEX ++;
            else break;
        }
    }
    while(freeval[MEX%x] > 0) freeval[MEX%x] --,MEX ++;
    cout << MEX << "\n";
    // for(auto x:arr)
    // {
    //     if(x != MEX) {
            
    //     } else MEX ++;
    // }
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
