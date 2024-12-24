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

// ##IGNORE##
template <class T>
T mypow(T n, int k, T r = 1)
{
    for (; k; k >>= 1, n *= n)
    {
        if (k & 1)
            r *= n;
    }
    return r;
}
template <int MOD>
struct mInt
{
    int x;
    mInt(int x = 0) : x(norm(x % MOD)) {}
    int val() const { return x; }
    int norm(int x) const { return (x + MOD) % MOD; }
    mInt operator-() const
    {
        int val = norm(MOD - x);
        return mInt(val);
    }
    mInt &operator++() { return x = norm(x + 1), *this; }
    mInt operator++(signed)
    {
        mInt res = *this;
        ++*this;
        return res;
    }
    mInt &operator--() { return x = norm(x - 1), *this; }
    mInt operator--(signed)
    {
        mInt res = *this;
        --*this;
        return res;
    }
    mInt inv() const
    {
        assert(x != 0);
        return mypow(*this, MOD - 2);
    }
    mInt &operator*=(const mInt &i) { return x = x * i.x % MOD, *this; }
    mInt &operator+=(const mInt &i) { return x = norm(x + i.x), *this; }
    mInt &operator-=(const mInt &i) { return x = norm(x - i.x), *this; }
    mInt &operator/=(const mInt &i) { return *this *= i.inv(); }
    mInt &operator%=(const int &i) { return x %= i, *this; }
    friend mInt operator*(const mInt &i, const mInt &j)
    {
        mInt res = i;
        res *= j;
        return res;
    }
    friend mInt operator+(const mInt &i, const mInt &j)
    {
        mInt res = i;
        res += j;
        return res;
    }
    friend mInt operator-(const mInt &i, const mInt &j)
    {
        mInt res = i;
        res -= j;
        return res;
    }
    friend mInt operator/(const mInt &i, const mInt &j)
    {
        mInt res = i;
        res /= j;
        return res;
    }
    friend mInt operator%(const mInt &i, const int &j)
    {
        mInt res = i;
        res %= j;
        return res;
    }
    friend auto &operator>>(istream &it, mInt &j)
    {
        int v;
        it >> v;
        j = mInt(v);
        return it;
    }
    friend auto &operator<<(ostream &o, const mInt &j) { return o << j.x; }
    bool operator<(const mInt &i) const { return x < i.x; }
    bool operator>(const mInt &i) const { return x > i.x; }
    bool operator==(const mInt &i) const { return x == i.x; }
    bool operator!=(const mInt &i) const { return x != i.x; }
};
// #define int long long
using mi = mInt<(int)1e9+7>;

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
        } else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};

void exgcd(int a,int b,int &x,int &y)
{
    if(b == 0) {
        x = 1,y = 0;
        return;
    }
    exgcd(b,a%b,y,x);
    y -= a/b * x;
}

using F = Frac<mi>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> s1(n),s2(n);
    for(auto &x:s1) cin >> x;
    for(auto &x:s2) cin >> x;
    F p(0,1),cp(1,1);
    lop(i,0,n)
    {
        // cout << p.num << "/" << p.den << "\n";
        // cout << cp.num << "/" << cp.den << "\n";
        if(s1[i] == 0 && s2[i] == 0) {
            int ttl = m * m;
            int gt = (m*m-m)/2;
            p += cp * F(gt,ttl);
            cp *= F(m,ttl);
        } else if(s1[i] == 0) {
            int ttl = m;
            int gt = m-s2[i];
            p += cp*F(gt,ttl);
            cp *= F(1,ttl);
        } else if(s2[i] == 0) {
            int ttl = m;
            int gt = s1[i]-1;
            p += cp * F(gt,ttl);
            cp *= F(1,ttl);
        } else if(s1[i] < s2[i]) {break;}
        else if(s1[i] > s2[i]) {p += cp;break;}
        else {continue;}
    }
    int inv,mod=1e9+7,y;
    cout << p.num * p.den.inv() << "\n";
    // cout << p.num << "/" << p.den << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;/*  */

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
