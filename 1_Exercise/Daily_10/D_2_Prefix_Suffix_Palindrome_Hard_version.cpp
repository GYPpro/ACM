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
    string s;
    cin >> s;
    int l = 0,r = s.size()-1;
    string anss;
    while(l<r){
        if(s[l] == s[r]){
            anss.push_back(s[l]);
            l ++,r --;
        }
        else break;
    }
    // cout << anss << "\n"; 
    s = s.substr(l,r-l+1);
    
    int n = s.size();
    vector<int> d1(n); //奇数长度
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n); //偶数长度
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    // cout << "s:" << s << "\n";
    // cout << "d2:";
    // for(auto x:d2) cout << x << " ";cout << "\n";
    int mx = 0;
    pii mi;
    for(int i = 0;i < n;i ++)
    {
        if(i-d1[i]+1 == 0 || i+d1[i]-1 == n-1 ) {
            if(d1[i]*2-1 > mx){
                mx = d1[i]*2-1;
                mi = {i-d1[i]+1,i+d1[i]-1};
            }
        }
        if(i-d2[i] == 0 || i+d2[i]-1 == n-1) {
            if(d2[i]*2 > mx) {
                mx = d2[i]*2;
                mi = {i-d2[i],i+d2[i]-1};
            }
        }
    }
    string mid = s.substr(mi.fi,mi.se-mi.fi+1);

    // cout << s << "\n";
    // cout << mid << "\n";
    string tmp = anss;
    reverse(all(tmp));
    anss += mid;
    anss += tmp;
    cout << anss << "\n";


    // s = s.substr()

    // vector<int> mp(n+1),mf(n+1);
    // for(int i = 0;i < n;i ++)
    // {
    //     int lrg = i-d1[i]+2;
    //     int rrg = i+d1[i];
    //     // int ltg = 
    //     mp[lrg] = max(mp[lrg],(d1[i]-1)*2+1);
    //     mp[rrg] = max(mp[rrg],(d1[i]-1)*2+1);
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
