// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

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
struct Zmod
{
    int x;
    Zmod(int x = 0) : x(norm(x % MOD)) {}
    int val() const { return x; }
    int norm(int x) const { return (x + MOD) % MOD; }
    Zmod operator-() const
    {
        int val = norm(MOD - x);
        return Zmod(val);
    }
    Zmod &operator++() { return x = norm(x + 1), *this; }
    Zmod operator++(signed)
    {
        Zmod res = *this;
        ++*this;
        return res;
    }
    Zmod &operator--() { return x = norm(x - 1), *this; }
    Zmod operator--(signed)
    {
        Zmod res = *this;
        --*this;
        return res;
    }
    Zmod inv() const
    {
        assert(x != 0);
        return mypow(*this, MOD - 2);
    }
    Zmod &operator*=(const Zmod &i) { return x = x * i.x % MOD, *this; }
    Zmod &operator+=(const Zmod &i) { return x = norm(x + i.x), *this; }
    Zmod &operator-=(const Zmod &i) { return x = norm(x - i.x), *this; }
    Zmod &operator/=(const Zmod &i) { return *this *= i.inv(); }
    Zmod &operator%=(const int &i) { return x %= i, *this; }
    friend Zmod operator*(const Zmod &i, const Zmod &j)
    {
        Zmod res = i;
        res *= j;
        return res;
    }
    friend Zmod operator+(const Zmod &i, const Zmod &j)
    {
        Zmod res = i;
        res += j;
        return res;
    }
    friend Zmod operator-(const Zmod &i, const Zmod &j)
    {
        Zmod res = i;
        res -= j;
        return res;
    }
    friend Zmod operator/(const Zmod &i, const Zmod &j)
    {
        Zmod res = i;
        res /= j;
        return res;
    }
    friend Zmod operator%(const Zmod &i, const int &j)
    {
        Zmod res = i;
        res %= j;
        return res;
    }
    friend auto &operator>>(istream &it, Zmod &j)
    {
        int v;
        it >> v;
        j = Zmod(v);
        return it;
    }
    friend auto &operator<<(ostream &o, const Zmod &j) { return o << j.x; }
    bool operator<(const Zmod &i) const { return x < i.x; }
    bool operator>(const Zmod &i) const { return x > i.x; }
    bool operator==(const Zmod &i) const { return x == i.x; }
    bool operator!=(const Zmod &i) const { return x != i.x; }
};
#define int long long
// using Z = Zmod<998244353>;

const int N = 1 << 21;
static const int mod1 = 1E9 + 7, base1 = 127;
static const int mod2 = 1E9 + 9, base2 = 131;
using U = Zmod<mod1>;
using V = Zmod<mod2>;
vector<U> val1;
vector<V> val2;
void init(int n = N)
{
    val1.resize(n + 1), val2.resize(n + 2);
    val1[0] = 1, val2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        val1[i] = val1[i - 1] * base1;
        val2[i] = val2[i - 1] * base2;
    }
}
struct String
{
    vector<U> hash1;
    vector<V> hash2;
    string s;
    String(string s_) : s(s_), hash1{1}, hash2{1}
    {
        for (auto it : s)
        {
            hash1.push_back(hash1.back() * base1 + it);
            hash2.push_back(hash2.back() * base2 + it);
        }
    }
    pair<U, V> get()
    { // 输出整串的哈希值
        return {hash1.back(), hash2.back()};
    }
    pair<U, V> substring(int l, int r)
    { // 输出子串的哈希值
        if (l > r)
            swap(l, r);
        U ans1 = hash1[r + 1] - hash1[l] * val1[r - l + 1];
        V ans2 = hash2[r + 1] - hash2[l] * val2[r - l + 1];
        return {ans1, ans2};
    }
    pair<U, V> modify(int idx, char x)
    { // 修改 idx 位为 x
        int n = s.size() - 1;
        U ans1 = hash1.back() + val1[n - idx] * (x - s[idx]);
        V ans2 = hash2.back() + val2[n - idx] * (x - s[idx]);
        return {ans1, ans2};
    }
};

string compress(vector<string> in)
{ // 前后缀压缩
    vector<U> hash1{1};
    vector<V> hash2{1};
    string ans = "#";
    for (auto s : in)
    {
        s = "#" + s;
        int st = 0;
        U chk1 = 0;
        V chk2 = 0;
        for (int j = 1; j < s.size() && j < ans.size(); j++)
        {
            chk1 = chk1 * base1 + s[j];
            chk2 = chk2 * base2 + s[j];
            if ((hash1.back() == hash1[ans.size() - 1 - j] * val1[j]+ chk1) &&
                (hash2.back() == hash2[ans.size() - 1 - j] * val2[j]+ chk2))
            {
                st = j;
            }
        }
        for (int j = st + 1; j < s.size(); j++)
        {
            ans += s[j];
            hash1.push_back(hash1.back() * base1 + s[j]);
            hash2.push_back(hash2.back() * base2 + s[j]);
        }
    }
    return ans.substr(1);
}
// vector<int> prefix_function(string s)
// {
//     int n = (int)s.length();
//     vector<int> pi(n);
//     for (int i = 1; i < n; i++)
//         for (int j = pi[i - 1] + 1; j >= 0; j--) // improved: j=i => j=pi[i-1]+1
//             if (s.substr(0, j) == s.substr(i - j + 1, j))
//             {
//                 pi[i] = j;
//                 break;
//             }
//     return pi;
// }

// string revese(string _s)
// {
//     string s = _s;
//     int l = 0, r = s.size() - 1;
//     while (r > l)
//     {
//         swap(s[l], s[r]);
//         l++, r--;
//     }
//     return s;
// }

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    cout << compress(a);
    // lop(i,1,n)
    // {
    //     string st = a[i] + a[i-1];
    //     auto rt = prefix_function(st);
    //     for(int j = 0;j < rt[rt.size()-1] && a[i-1].size();j ++) a[i-1].pop_back();
    //     if(a[i].size() <= rt[rt.size()-1]) {a[i] = a[i-1]+a[i];a[i-1] = "";}
    // }
    // for(auto x:a)cout << x;cout << "\n";
    // cout << ans + a[n-1] << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
init();
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
