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
using ld = long double;

using pld = pair<ld,ld>;
using lld = pair<pld,pld>;
#define x fi
#define y se
const ld EPS = 1e-6;

template<typename T>
bool eq(T a,T b) {
    if(fabs(a-b) <= EPS) return  1;
    else return 0;
}

ld cross(pld a,pld b) {
    return a.x * b.y - a.y * b.x;
}

ld dot(pld a,pld b) {
    return a.x * b.x + a.y * b.y;
}

pld mkvec(pld a,pld b){
    return {b.x-a.x,b.y-a.y};
}

pld rt90(pld a){
    return {-a.y,a.x};
}

lld midsg(pld a,pld b) {
    pld vec = rt90(mkvec(a,b));
    pld ftr = {(a.x+b.x)/2.0,(a.y+b.y)/2.0};
    return {ftr,{ftr.x +vec.x,ftr.y +vec.y}};    
}

pld insc(lld l1,lld l2) {
    ld v = cross(mkvec(l2.fi,l2.se),mkvec(l2.fi,l1.fi))/
           cross(mkvec(l2.fi,l2.se),mkvec(l1.se,l1.fi));
    return {l1.fi.x + mkvec(l1.fi,l1.se).x * v,l1.fi.y + mkvec(l1.fi,l1.se).y * v};
}

pld trac(pld a,pld b,pld c) {
    // vector<pld> rt(3);
    // rt[0] = insc(midsg(a,b),midsg(b,c));
    // rt[1] = insc(midsg(a,b),midsg(b,c));
    // rt[2] = insc(midsg(a,c),midsg(b,c));
    
    // // cout << rt[0].x << " " << rt[0].y << "\n";
    // for(int i = 1;i < 3;i ++)
    // {
    //     // cout << rt[i].x << " " << rt[i].y << "\n";
    //     assert(eq(rt[i].x,rt[i-1].x) && eq(rt[i].y,rt[i-1].y));
    // }
    return insc(midsg(a,b),midsg(b,c));
};

template<typename T>
T pw(T a) {
    return a * a;
}

ld dis(pld a,pld b){
    return sqrtl(pw(b.y-a.y)+pw(b.x-a.x));
}

ld pi = acosl(-1);

ld abs(pld v) {
    return sqrtl(pw(v.x)+pw(v.y));
}

ld acos(pld v1,pld v2){
    // cout << dot(v1,v2)/(abs(v1)*abs(v2)) << " " << acosl(dot(v1,v2)/(abs(v1)*abs(v2))) << "\n";
    ld tv = dot(v1,v2)/(abs(v1)*abs(v2));
    if(tv < -1) tv += 1e-16;
    if(tv > 1) tv -= 1e-16;
    return
        acosl(tv);
}

bool ifmod(ld a,ld b) {// a > b
    // ld t = a/b;
    // cout << "begin checking:" << a << " " << b << "\n";
    // cout << "check:" << t << "for" << (fabs(t-(ld)((int)(t+1e-7))) < EPS) << " \n";
    // if(fabs(t-(ld)((int)(t+1e-6))) < EPS) return 1;
    for(int i = 1;i <= 100;i ++) {
            // cout << "check:" << a << " " << b*(ld)i << "\n";
            if(eq(a,b*(ld)i)) return 1;
            // else return 0;
        }
    return 0;
    // if(min(fabs(t-(ld)((int)(t))),fabs(t-(ld)((int)(t)+1))) < EPS) return 1;
}

void solve()
{
    pld a,b,c;
    cin >> a.x >> a.y
        >> b.x >> b.y
        >> c.x >> c.y;
    // cout << acosl(-1);
    pld pid = trac(a,b,c);
    cout << fixed << setprecision(8);
    // cout << pid.x << " " << pid.y << "\n";
    ld r = dis(pid,a);
    ld d1 = acos(mkvec(pid,a),mkvec(pid,b)),
       d2 = acos(mkvec(pid,a),mkvec(pid,c)),
       d3 = acos(mkvec(pid,b),mkvec(pid,c));
    // cout << d1 << " " << d2 << " " << d3 << "\n";
    for(int i = 3;i <= 101;i ++)
    {
        ld deg = (ld)(2.) * pi / (ld)i;
        // cout << i << ": " << deg << "\n";
        bool flag = (ifmod(d1,deg)+ifmod(d2,deg)+ifmod(d3,deg) > 2);
        // cout << i << ":";
        // if(!ifmod(acos(mkvec(pid,a),mkvec(pid,b)),deg)) flag = 0;
        // // cout << "mkvec(pid,a):" << mkvec(pid,a).fi << " " << mkvec(pid,a).se << "-" << acos(mkvec(pid,a),mkvec(pid,b)) << "\n"; 
        // if(!ifmod(acos(mkvec(pid,b),mkvec(pid,c)),deg)) flag = 0;
        // // cout << "mkvec(pid,b):" << mkvec(pid,b).fi << " " << mkvec(pid,b).se << "-" << acos(mkvec(pid,b),mkvec(pid,c)) << "\n"; 
        // if(!ifmod(acos(mkvec(pid,a),mkvec(pid,c)),deg)) flag = 0;
        // cout << "mkvec(pid,c):" << mkvec(pid,c).fi << " " << mkvec(pid,c).se << "-" << acos(mkvec(pid,c),mkvec(pid,a)) << "\n"; cout << "\n";
        if(flag){
            // cout << i << " ";
            cout << r * r * sinl(deg/2.0) * cosl(deg/2.0) * i << "\n";
            return;
        }
    }
    assert(0);
    // cout << "1145141919810LL\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
// #ifndef FC
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cout.tie(0);
// #endif
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
