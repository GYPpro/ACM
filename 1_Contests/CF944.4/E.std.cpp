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
const double INF = 1e18;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;
#define double long double

template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream &operator<<(std::ostream &os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) {
            return os << x.num / g;
        } else   {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};
 
using F = Frac<int>;

void solve()
{
    int _,n,q;
    cin >> _ >> n >> q;
    vector<pii> dots(n+1); // [xlis,time]
    set<pair<int,F>,greater<pair<int,F>>> vtrs;
    map<int,int> xls2idx;
    lop(i,1,n+1) 
        cin >> dots[i].fi,xls2idx[dots[i].fi] = i;
    lop(i,1,n+1)    
        cin >> dots[i].se;
    
    lop(i,0,n)
    {
        pair<int,F> pbt;
        pbt.fi = dots[i].fi;
        // pbt.se = (double) ( dots[i+1].fi - dots[i].fi) / (dots[i+1].se - dots[i].se);
        pbt.se = F(( dots[i+1].fi - dots[i].fi),(dots[i+1].se - dots[i].se));
        vtrs.insert(pbt);
    }
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 0) {cout << 0 << " ";continue;}
        auto rt = *vtrs.lower_bound({k,F(INF,1)});
        F ans = F((k - rt.fi),1);
        ans /= rt.se;
        ans += F(dots[xls2idx[rt.fi]].se,1);
        // cout << (int)((double)(k - rt.fi)/rt.se + dots[xls2idx[rt.fi]].se) << " ";
        cout << (int)((double) ans.num/(double)ans.den )<< " ";
    }
    cout << "\n";
    
}

signed main()
{
#ifdef FC
    freopen("E.A.in","r",stdin);
    freopen("E.A.std","w",stdout);
#endif

#ifndef FC
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
