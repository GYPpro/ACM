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
    int n,m,q;
    cin >>  n >> m >>  q;
    int r1 = 0,l2 = m,r2 = m,l3 = n+1;

    auto cal = [&]() ->  int {
        int nl2 = min(l2,l3);
        int nr1 = min(r1,nl2-1);
        int nr2 = min(r2,l3-1);
        int nl3 = l3;
        return abs(nr1-1+1) + abs(nr2-nl2+1) + abs(n-nl3+1);
    };

    auto prt = [&]() -> void {
        int nl2 = min(l2,l3);
        int nr1 = min(r1,nl2-1);
        int nr2 = min(r2,l3-1);
        int nl3 = l3;
        int i = 1;
        cout << "\n";
        for(;i <= nr1;i ++) cout << 1 << " ";
        for(;i < nl2;i ++) cout << 0 << " ";
        for(;i <= nr2;i ++) cout << 1 << " ";
        for(;i < nl3;i ++) cout << 0 << " ";
        for(;i <= n;i ++) cout << 1 << " ";
        cout << "\n";
    };
        // prt();

    while(q--)
    {
        int c;
        cin >> c;
        
        if(c == l2 && c == r2) {
            l2 = INF,r2 = INF;
            r1 ++,l3 --;
            cout << cal() << " ";
            // prt();
            continue;
        }

        int f = 0;
        if(c <= r1) f = 1;
        if(c >= l2 && c <= r2) f = 1;
        if(c >= l3) f = 1;

        if(f){
            if(r1 < c) r1 ++;
            if(l2 > c && (abs(r2-l2 + 1) >= 1)) l2 --;
            if(r2 < c && (abs(r2-l2 + 1) >= 1)) r2 ++;
            if(l3 > c) l3 --;
            // cout << r1 << " " << l2 << " " << r2 << " " << l3 << " -1\n";
        } else { 
            if(r1 < c && r1) r1 ++;
            if(l2 > c && (abs(r2-l2 + 1) >= 1)) l2 --;
            if(r2 < c && (abs(r2-l2 + 1) >= 1)) r2 ++;
            if(l3 > c && l3 != n+1) l3 --;
            // cout << r1 << " " << l2 << " " << r2 << " " << l3 << " -0\n";
        }
        cout << cal() << " ";
        // prt();
        // }
        
    }cout << "\n";

}

void lst()
{
    int n;
    cin >> n;
    vector<vector<int>> sa;
    vector<int> tmp(n);
    // iota(all(tmp),1);
    int m;
    cin >> m;
    m --;
    tmp[m] = 1;
    sa.push_back(tmp);
    auto imp = [&](vector<int> a,int x) -> vector<int> {
        vector<int> ne;
        ne.push_back(a[x]);
        for(int i = 0;i < a.size();i ++) if(i == x) continue;
        else ne.push_back(a[i]);
        return ne;
    };
    auto bmp = [&](vector<int> a,int x) -> vector<int> {
        vector<int> ne;
        for(int i = 0;i < a.size();i ++) if(i == x) continue;
        else ne.push_back(a[i]);
        ne.push_back(a[x]);
        return ne;
    };

    vector<int> vst(n);vst[m] = 1;

    while(1){
        for(auto x:vst) cout << x << " ";cout << "\n";
        int t;
        cin >> t;
        if(t == 0) {
            sa.clear();
            sa.push_back(tmp);
            fill(all(vst),0),vst[m] = 1;
            // for(auto x:vst) cout << x << " ";cout << "\n";
            continue;
        }
        vector<vector<int>> nw;
        for(auto a:sa){
            nw.push_back(imp(a,t-1));
            nw.push_back(bmp(a,t-1));
        }
        fill(all(vst),0);
        for(auto a:nw)
        {
            for(int i = 0;i < n;i ++) if(a[i] == 1) vst[i] = 1;
            // for(auto x:a) cout << x << " ";cout  << "\n";
        }
        sa = nw;
    }

}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // lst();
    cin >> T;
    while(T--) solve();
    return 0;
}


/*
a b c
-- a b c
--- b a c
---- c b a
---- b a c
--- a c b
---- b a c
---- a c b

-- b c a
--- c b a
---- a c b
---- c b a
--- b a c
---- c b a
---- b a c


---- c b a
---- b a c
---- a c b
---- c b a
---- b a c
---- a c b
---- c b a
---- b a c
*/