// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_msetl = tree<int, null_type, less_equal<int>, rb_tree_tag,
                     tree_order_statistics_node_update>;
using ord_msetg = tree<int, null_type, greater_equal<int>, rb_tree_tag,
                     tree_order_statistics_node_update>;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
// #define set unordered_set
// #define map unordered_map
const int mod = 1e9 + 7;

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
// #undef int long long
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

using mi = mInt<(int)(1e9+7)>;
// using Z = Zmod<998244353>;
mi ksm(int k)
{
    mi ans = 1;
    mi a = 2;
    while (k)
    {
        if (k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans; 
}
// int b[100005];
// map<int, int> vis, vis1, vis2;
// set<int> s;

int input()
{
    string s;
    cin >> s;
    int rt = 0;
    int t = 10000;
    for(auto x:s) if(x == '.') continue;
    else rt += (x-'0')*t,t/=10;
    return rt;
}

void solve()
{
    // vis1.clear();
    // vis2.clear();
    // s.clear();
    // vis.clear();
    int n, q;
    cin >> n >> q;
    vector<int> b(n);
    for(auto &x:b) x = input();
    ord_msetg sg;
    ord_msetl sl;
    map<int,int> cnt;
    for(auto x:b) cnt[x] ++,sg.insert(x),sl.insert(x);
    while (q--)
    {
        mi ans = 0;
        int p = input();
        // cout <<
        int self = cnt[p],gt = (int)sg.order_of_key(p),lt = (int)sl.order_of_key(p);
        // cout << self << " " << gt << " " << lt << "\n";
        cout << (ksm(lt)-mi(1))*(ksm(gt)-mi(1))+(ksm(self)-mi(1))*ksm(lt)*ksm(gt) << "\n";
        // int fa = *(s.lower_bound(p));
    }
}

signed main()
{
#ifdef FC
    freopen("G.A.in", "r", stdin);
    freopen("G.A.ptc", "w", stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
