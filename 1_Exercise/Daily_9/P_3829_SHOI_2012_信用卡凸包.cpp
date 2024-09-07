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

using ld = long double;
using pld = pair<ld,ld>;
const ld pi = acosl(-1);

//Rotating_Calipers
template<typename VALUE_TYPE>
class Rotating_Calipers
{
public:
    using vec_pv = vector<pair<VALUE_TYPE, VALUE_TYPE>>;
    vec_pv p;

    static VALUE_TYPE cross(pair<VALUE_TYPE, VALUE_TYPE> p1, pair<VALUE_TYPE, VALUE_TYPE> p2, pair<VALUE_TYPE, VALUE_TYPE> p0)
    {
        pair<VALUE_TYPE, VALUE_TYPE>
            t1 = {p1.fi - p0.fi, p1.se - p0.se},
            t2 = {p2.fi - p0.fi, p2.se - p0.se};
        return t1.fi * t2.se - t1.se * t2.fi;
    }

    static VALUE_TYPE dis(const pair<VALUE_TYPE, VALUE_TYPE> &p1,const pair<VALUE_TYPE, VALUE_TYPE> &p2){
        return (p1.fi - p2.fi) * (p1.fi - p2.fi) + (p1.se - p2.se) * (p1.se - p2.se);
    };

public:
    
    Rotating_Calipers() {}

    Rotating_Calipers(vec_pv _A) {
        build(_A);
    }

    void build(const vec_pv & _A) {
        p = ConvexHull(_A);
    }

    VALUE_TYPE getPerimeter() {
        VALUE_TYPE sum = 0;
        p.pb(p[0]);
        for(int i = 0;i < (int)p.size() - 1;i ++)
        {
            sum += sqrtl(dis(p[i],p[i+1]));
        }
        p.pop_back();
        return sum;
    }

    static vec_pv ConvexHull(vec_pv A, VALUE_TYPE flag = 1)
    {
        int n = A.size();
        if (n <= 2) return A; 
        vec_pv ans(n * 2);
        sort(A.begin(), A.end(),
        [](pair<VALUE_TYPE,VALUE_TYPE> a,pair<VALUE_TYPE,VALUE_TYPE> b) -> bool {
            if(fabs(a.fi - b.fi) < 1e-10)
                return a.se < b.se;
            else return a.fi < b.fi;}    );
        int now = -1;
        for (int i = 0; i < n; i++)
        { // 维护下凸包
            while (now > 0 && cross(A[i], ans[now], ans[now - 1]) < flag) now--;
            ans[++now] = A[i];
        }
        int pre = now;
        for (int i = n - 2; i >= 0; i--)
        { // 维护上凸包
            while (now > pre && cross(A[i], ans[now], ans[now - 1]) < flag) now--;
            ans[++now] = A[i];
        }
        ans.resize(now);
        return ans;
    }

    VALUE_TYPE getDiameter() {
        int j = 1;
        VALUE_TYPE ans = 0;
        int m = p.size();
        p.push_back(p[0]);
        for(int i = 0;i < m;i ++)
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
    ld a,b,r;
    // cin >> a >> b >> r;
    cin >> b >> a >> r;
    a /= 2.0,b /= 2.0;
    a -= r,b -= r;
    ld s = sqrtl(a*a+b*b);
    vector<pld> rotCons;
    lop(i,0,n)
    {
        ld x,y,th;
        cin >> x >> y >> th;
        ld th1 = atanl(b/a);
        ld th2 = 2 * pi-th1;
        ld th3 = pi-th1;
        ld th4 = pi+th1;
        th1 += th;
        th2 += th;
        th3 += th;
        th4 += th;
        rotCons.pb({x + cosl(th1) * s , y + sinl(th1) * s });
        // cout << x + cos(th1) * s << " " <<  y + sin(th1) * s << "\n"; 
        rotCons.pb({x + cosl(th2) * s , y + sinl(th2) * s });
        // cout << x + cos(th2) * s << " " <<  y + sin(th2) * s << "\n"; 
        rotCons.pb({x + cosl(th3) * s , y + sinl(th3) * s });
        // cout << x + cos(th3) * s << " " <<  y + sin(th3) * s << "\n"; 
        rotCons.pb({x + cosl(th4) * s , y + sinl(th4) * s });
        // cout << x + cos(th4) * s << " " <<  y + sin(th4) * s << "\n"; 
        // cout << "--------------------   \n";
    }
    Rotating_Calipers<ld> rc(rotCons);
    // cout << setprecision(15) << rc.getPerimeter() + pi * r * 2.0 << "\n"; 
    cout << format("{:.2f}",rc.getPerimeter() + pi * r * 2.0) << "\n";
    // for(auto x:rc.p) cout << x.fi << " " << x.se << "\n";
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
