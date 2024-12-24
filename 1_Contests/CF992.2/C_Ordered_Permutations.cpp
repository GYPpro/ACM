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

void  lister(){
    int n;
    cin >> n;
    vector<int> arr(n);
    iota(all(arr),1);
    map<int,vector<vector<int>>> cnt;
    do  {
        int ctr = 0;
        // for(auto x:arr) cout << x << " ";cout <<  "\n";
        for(int i = 0;i < n;i ++)
            for(int  j = 0;j  < n;j ++)
            {
                if(i >  j) continue;
                int MI = INF;
                for(int k = i;k <= j;k ++) MI = min(MI,arr[k]);
                ctr += MI;
                // cout << MI << " :" << i << " " << j << "\n";
            }
        cnt[ctr].pb(arr);
        // break;
    }
    while (next_permutation(all(arr)));
    auto [k,v] = *cnt.rbegin();
    for(auto ar:v){
        // cout << k << ":";
        for(auto  x:ar)  cout << x  << " ";cout  << "\n";
    }
    // cout << v.size()  << "\n";
}

void check(){
    auto  sv = [&](int n,int k) ->  void {
        
        
        // cin  >> n >> k;
        deque<int> res;
        k  --;
        auto sep = [&](int cn)  -> int {
            if(cn >= 60) return 1e14;
            else return  1LL << (cn-2);
        };
        if(k > sep(n)*2) {cout << "-1\n";return;}

        function<void(int,int)> addT = [&](int cur,int dep) -> void {
            if(dep == n){
                res.push_back(dep);
                return;
            }
            // cout <<  "addT:" <<  cur << " " << dep << " " << sep(n-dep+1) << "\n";
            addT(cur % (sep(n-dep+1)),dep+1); 
            if(cur >= sep(n-dep+1)) res.push_back(dep);
            else res.push_front(dep);
            // addT(cur%dep,dep-1);
            // if(cur>sep(n-dep)) res.push_front(dep);
            // else res.push_back(dep);
        };
        addT(k,1);
        for(auto x:res) cout << x << " ";cout << "\n";
    };
    int t;
    cin >> t;
    for(int i = 0;i < (1LL << (t-1));i ++) {
        sv(t,i+1);
    }
}

void solve()
{
    int n,k;
    cin  >> n >> k;
    if(n == 1){
        if(k == 1) cout << "1\n";
        else cout <<  "-1\n";
        return;
    }
    deque<int> res;
    k  --;
    auto sep = [&](int cn)  -> int {
        cn = min(cn,50LL);
        return  1LL << (cn-2);
    };
    if(k >= sep(n)*2) {cout << "-1\n";return;}

    function<void(int,int)> addT = [&](int cur,int dep) -> void {
        if(dep == n){
            res.push_back(dep);
            return;
        }
        // cout <<  "addT:" <<  cur << " " << dep << " " << sep(n-dep+1) << "\n";
        addT(cur % (sep(n-dep+1)),dep+1); 

        if(cur >= sep(n-dep+1)) res.push_back(dep);
        else res.push_front(dep);
        // addT(cur%dep,dep-1);
        // if(cur>sep(n-dep)) res.push_front(dep);
        // else res.push_back(dep);
    };
    addT(k,1);
    for(auto x:res) cout << x << " ";cout << "\n";
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
    // while(T--) lister();
    // while(T--) check();
    return 0;
}
