// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

// import std as *

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
namespace myDS{
    class vector {
    // ...
    };
};

// myDS::vector;
// std::vector;

void solve()
{
    int n,k;
    cin >> n >> k;
    // vector<int> a(n),b(n);
    // for(auto &x:a) cin >> x;
    // for(auto &x:b) cin >> x;
    vector<pii> arr(n);
    for(auto &x:arr) cin >> x.fi;
    for(auto &x:arr) cin >> x.se;
    sort(all(arr));
    auto improve = [&](vector<pii> s,int k) -> int {
        int cod = (s.size()-1)/2;
        // int serfix = 0;
        // int mex = cod;
        // while(s[mex].se) mex ++;
        
        auto check = [&](int f) -> bool {
            vector<pii> sefx;
            for(auto x:s) if(x.se) sefx.pb(x);
            
            int NED = (s.size())/2+1;
            for(auto x:s) if(x.se == 0 && x.fi >= f) NED --;
            sort(all(sefx));
            int fsum = 0;
            if(NED <= 0) return 1;
            if(sefx.size() < NED) return 0;
            lop(i,max(0LL,(int)sefx.size()-NED),sefx.size())
            {
                if(sefx[i].fi < f) fsum += f-sefx[i].fi;
            }
            // int t = k;
            // int ssum = 0;
            // int i = cod;
            // int sums = 0;
            // while(s[i].fi < f && i <= s.size()){
            //     if(s[i].se == 0) return 0;
            //     else ssum += f-s[i].first;
            //     i ++;
            // }
            // // cout .
            return fsum <= k;
        };
        
        int l = 1, r = 1e9 + 1;   // 因为是左闭右开的，所以 10^9 要加 1
        while (l + 1 < r) {       // 如果两点不相邻
            int mid = (l + r) / 2;  // 取中间值
            if (check(mid))         // 如果可行
            l = mid;              // 升高锯片高度
            else
            r = mid;  // 否则降低锯片高度
        }
        // cout << l << " ";
        return l;
        // return 0;
    };

    int ans1 = 0;
    int maxi1 = INF;

    lop(i,0,n) 
    {
        if(arr[i].se == 0) continue;
        if(arr[i].fi >= ans1) {
            ans1 = arr[i].fi,maxi1 = i;
        }
    }
    if(maxi1 != INF) ans1 += k;
    // bool f = 0;
    vector<pii> gnct1;
    // for(auto x:arr) 
    lop(i,0,n) if(i == maxi1) continue;
    else gnct1.pb(arr[i]);
    ans1 += improve(gnct1,0);

    int ans0 = 0;
    int maxi0 = 0;
    lop(i,0,n) 
    {
        if(arr[i].se == 1) continue;
        if(arr[i].fi >= ans0) {
            ans0 = arr[i].fi,maxi0 = i;
        }
    }
    vector<pii> gnct0;
    // for(auto x:arr) 
    lop(i,0,n) if(i == maxi0) continue;
    else gnct0.pb(arr[i]);
    ans0 += improve(gnct0,k);
    
    cout << max(ans0,ans1) << "\n"; 
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
