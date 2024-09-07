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
    int n;
    string l,r;
    cin >> n;
    n /= 2;
    cin >> l >> r;
    auto s2i128 = [&](string s) -> __int128 {
        __int128 t = 0;
        __int128 p = 1;
        // lop(i,0,s.size())
        for(int i = s.size()-1;i >= 0;i --)
        {
            t += p * (__int128)(s[i]-'0');
            p *= 10LL;
        }
        return t;
    };
    auto i1282s = [&](__int128 t) -> string{
        string rt;
        while(t){
            rt.pb('0'+t%10);
            t /= 10;
        }
        reverse(all(rt));
        if(rt.size() == 0) rt = "0";
        return rt;
    };

    auto subsqrt = [&](__int128 t) -> __int128{
        if(t == 0) return 0;
        __int128 l = 0, r = 1e16;   // 因为是左闭右开的，所以 10^9 要加 1
        auto check = [&](__int128 cur) -> bool{
            // cout << i1282s(cur) << ":" << (cur * cur >= t) << "\n";
            return cur * cur >= t;
        };
        while (l + 1 < r) {       // 如果两点不相邻
            // cout << i1282s(r) << " ";
            __int128 mid =  l + (r-l)/2;  // 取中间值
            if (check(mid))         // 如果可行
            r = mid;              // 升高锯片高度
            else
            l = mid;  // 否则降低锯片高度
        }
        return r;
    };

    string l1,l2,r1,r2;
    lop(i,0,n) l1.pb(l[i]);
    lop(i,n,2*n) l2.pb(l[i]);
    lop(i,0,n) r1.pb(r[i]);
    lop(i,n,2*n) r2.pb(r[i]);

    // cout << l1 << " " << l2 << " " << r1 << " " << r2 << "\n";
    __int128 dl1,dl2,dr1,dr2;
    dl1 = s2i128(l1);
    dl2 = s2i128(l2);
    dr1 = s2i128(r1);
    dr2 = s2i128(r2);

    __int128 MEX = 1;
    __int128 ans = 0;
    lop(i,0,l2.size()) MEX *= 10;
    // cout << (int)MEX << "\n";
    ans += (subsqrt(dr1-1)-subsqrt(dl1+1)) * (subsqrt(MEX));
    // cout << i1282s(ans)<< "\n";
    // cout << i1282s(subsqrt(dl2))<< "\n";
    if(subsqrt(dl1) * subsqrt(dl1)== dl1){
        ans += (subsqrt(MEX)) - subsqrt(dl2);
    }
    // cout << i1282s(subsqrt(dr1))<< "\n";
    // cout << i1282s(ans) << "\n"; 
    if(subsqrt(dr1) * subsqrt(dr1)== dr1){
        ans += subsqrt(dr2)+1;
    }
    
    cout << i1282s(ans) << "\n"; 

    // cout << (int)s2i128(l) << "\n";
    // cout << i1282s(subsqrt(s2i128(l))) << " " << i1282s(subsqrt(s2i128(r))) << "\n";
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
