// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

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
#define ld long double


int cmp(ld x, ld y){
    if(fabs(x-y)<=1e-12) return 0;
    if(x>y) return 1;
    else return -1;
};

ld dis(const ld &ax,const ld &ay,const ld &bx,const ld &by){
    return sqrtl((bx - ax) * (bx - ax) + (by - ay) * ( by - ay));
};

bool atline(const int &xa,const int &ya,const int &xb,const int &yb,const int &xp,const int &yp){
    if(xp > max(xa,xb) || xp < min(xa,xb)) return 0;
    if(yp > max(ya,yb) || yp < min(ya,yb)) return 0;
    int devx1 = xa - xp,devx2 = xp-xb;
    int devy1 = ya - yp,devy2 = yp-yb;
    // cout << devx1 << " " << devx2 << " " << devy1 << " " << devy2 << "\n";
    if(devx1 * devy2 == devx2 * devy1) return 1;
    else return 0;
};

int ix1,iy1,ix2,iy2,ix3,iy3,ixp,iyp;

void solve()
{
    // cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&ix1,&iy1,&ix2,&iy2,&ix3,&iy3,&ixp,&iyp);
    // printf("%lld %lld %lld %lld %lld %lld %lld %lld",x1,x2,y1,y2,x3,y3,xp,yp);

    ld x1 = ix1,
       x2 = ix2,
       y1 = iy1,
       y2 = iy2,
       x3 = ix3,
       y3 = iy3,
       xp = ixp,
       yp = iyp;
    // auto 

    // auto atline = [](ld xa,ld ya,ld xb,ld yb,ld xp,ld yp) -> bool {
    //     if(xp > max(xa,xb) || xp < min(xa,xb)) return 0;
    //     if(yp > max(ya,yb) || yp < min(ya,yb)) return 0;
    //     ld devx1 = xa - xp,devx2 = xp-xb;
    //     ld devy1 = ya - yp,devy2 = yp-yb;
    //     // cout << devx1 << " " << devx2 << " " << devy1 << " " << devy2 << "\n";
    //     if(fabs(devx1 * devy2 - devx2 * devy1) <= 1e-14) return 1;
    //     else return 0;
    // };

    //从xa出发，往xb找p


    // ld a = dis(x1,y1,x2,y2),b = dis(x2,y2,x3,y3),c = dis(x3,y3,x1,y1);
    bool f = 0;
    if(atline(ix1,iy1,ix2,iy2,ixp,iyp)) f = 1;
    else if(atline(ix1,iy1,ix3,iy3,ixp,iyp)) {
        // cout << "swapac\n";
        f = 1;
        swap(x2,x3),swap(y2,y3);
        swap(ix2,ix3),swap(iy2,iy3);
    }
    else if(atline(ix2,iy2,ix3,iy3,ixp,iyp))
    {
        // cout << "swapab\n";
        f = 1;
        swap(x1,x3),swap(y1,y3);
        swap(ix1,ix3),swap(iy1,iy3);
    } 
    if(!f){
        // cout << "-1\n";
        printf("-1\n");
        return;
    }
    // cout << x1 << " " << y1 << " :1\n";
    // cout << x2 << " " << y2 << " :2\n";
    // cout << x3 << " " << y3 << " :3\n";
    ld a = dis(x1,y1,x2,y2),b = dis(x2,y2,x3,y3),c = dis(x3,y3,x1,y1);
    // ld tba = a * a,tbb = b * b,tbc = c * c;
    // ld cosa = (tbb + tbc - tba) / (2.0 * b * c);
    // ld cosb = (tba + tbc - tbb) / (2.0 * a * c);
    // ld cosc = (tba + tbb - tbc) / (2.0 * a * b);
    // ld sina = sqrt(1.0-cosa * cosa);
    // ld sinb = sqrt(1.0-cosb * cosb);
    // ld sinc = sqrt(1.0-cosc * cosc);
    // ld S = 0.25 * a * b * sinc;
    
    // atline(x1,y1,x2,y2,xp,yp) == 1

    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    // cout << atline(x1,y1,x2,y2,xp,yp) << "\n";
    // cout << cosa << " " << sina << " : " << a << "\n";
    // cout << cosb << " " << sinb << " : " << b << "\n";
    // cout << cosc << " " << sinc << " : " << c << "\n";

    // cout << S << "\n";
    pair<bool,pair<ld,ld>> rt;
    auto getdot = [&](ld xa,ld ya,ld xb,ld yb,ld p) -> void{
        // cout << "from " << xa << " " << ya << " to:" << xb << " " << yb << " tar:" << p << "\n";
        // cout << dis(xa,ya,xb,yb) << "\n";
        if(cmp( dis(xa,ya,xb,yb) , p) < 0)rt = {0,{0,0}};
        else {
            ld prst = p / dis(xa,ya,xb,yb);
            prst = fabs(prst);
            if(prst < 1e-9) {rt.fi = 0;return;}
            if(prst > 1.0+(1e-9)) {rt.fi = 0;return;}
            rt = {1, { xa + prst * (xb - xa) , ya + prst * (yb - ya) } };
        }
        return;
    };
    ld cst = 2.0;
    getdot(x2,y2,x3,y3, (a * b) / ( cst * dis(x2,y2,xp,yp))  );
    if(rt.fi) {
        // cout << setprecision(12) << rt.se.fi << " " << rt.se.se << "\n";
        printf("%.7Lf %.7Lf\n",rt.se.fi,rt.se.se);
    }else {
        getdot(x1,y1,x3,y3, (a * c) / (cst * dis(x1,y1,xp,yp)) );
        // cout << setprecision(12) <<  rt.se.fi << " " << rt.se.se << "\n";
        printf("%.7Lf %.7Lf\n",rt.se.fi,rt.se.se);
    }
    return;
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    scanf("%lld",&T);

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
