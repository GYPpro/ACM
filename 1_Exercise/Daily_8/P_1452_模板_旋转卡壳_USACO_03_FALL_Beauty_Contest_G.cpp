// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)
// #define
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
using namespace std;



template<typename VALUE_TYPE = int>
class Rotating_Calipers
{
public:
    using vec_dot = vector<pair<VALUE_TYPE, VALUE_TYPE>>;
    using dot = pair<VALUE_TYPE,VALUE_TYPE>;
    vec_dot p;


    static VALUE_TYPE cross(dot p1, dot p2, dot p0)
    {
        dot t1 = {p1.fi - p0.fi, p1.se - p0.se},
            t2 = {p2.fi - p0.fi, p2.se - p0.se};
        return t1.fi * t2.se - t1.se * t2.fi;
    }

    static VALUE_TYPE dis(const dot &p1,const dot &p2){
        return (p1.fi - p2.fi) * (p1.fi - p2.fi) + (p1.se - p2.se) * (p1.se - p2.se);
    };

public:
    
    Rotating_Calipers() {}

    Rotating_Calipers(vec_dot _A) {
        build(_A);
    }

    void build(const vec_dot & _A) {
        p = ConvexHull(_A);
    }

    static vec_dot ConvexHull(vec_dot A, signed flag = 1)
    {
        signed n = A.size();
        if (n <= 2) return A; 
        vec_dot ans(n * 2);
        sort(A.begin(), A.end());
        signed now = -1;
        for (signed i = 0; i < n; i++)
        { // 维护下凸包
            while (now > 0 && cross(A[i], ans[now], ans[now - 1]) < flag) now--;
            ans[++now] = A[i];
        }
        signed pre = now;
        for (int i = n - 2; i >= 0; i--)
        { // 维护上凸包
            while (now > pre && cross(A[i], ans[now], ans[now - 1]) < flag) now--;
            ans[++now] = A[i];
        }
        ans.resize(now);
        return ans;
    }

    VALUE_TYPE getDiameter() {
        signed j = 1;
        VALUE_TYPE ans = 0;
        signed m = p.size();
        p.push_back(p[0]);
        for(signed i = 0;i < m;i ++)
        {
            while( cross(p[i+1],p[j],p[i]) > cross(p[i+1],p[j+1],p[i]) ) j = (j+1)%m;
            ans = max(ans, max( dis(p[i],p[j]) , dis(p[i+1],p[j]) ) );
        }
        p.pop_back();
        return ans;
    }

};



void solve()
{
    int n;
    cin >> n;
    vector<pii> p(n);
    lop(i,0,n)
    {
        cin >> p[i].fi >> p[i].se;
    }
    Rotating_Calipers rc(p);
    // for(auto x:rc.p) cout << x.fi << "," << x.se << " | ";cout << "\n";
    cout << rc.getDiameter() << "\n";
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

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
