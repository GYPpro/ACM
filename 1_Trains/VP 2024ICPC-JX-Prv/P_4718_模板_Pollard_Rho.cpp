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


template<typename NUMBER_TYPE>
class Pollard_Rho
{
public:

    vector<NUMBER_TYPE> B;

    NUMBER_TYPE mul(NUMBER_TYPE a, NUMBER_TYPE b, NUMBER_TYPE m)
    {
        NUMBER_TYPE r = a * b - m * (NUMBER_TYPE)(1.L / m * a * b);
        return r - m * (r >= m) + m * (r < 0);
    }

    NUMBER_TYPE mypow(NUMBER_TYPE a, NUMBER_TYPE b, NUMBER_TYPE m)
    {
        NUMBER_TYPE res = 1 % m;
        for (; b; b >>= 1, a = mul(a, a, m)) 
            if (b & 1) 
                res = mul(res, a, m);
        return res;
    }

    bool MR(NUMBER_TYPE n)
    {
        if (n <= 1)
            return 0;
        for (NUMBER_TYPE p : B)
        {
            if (n == p)
                return 1;
            if (n % p == 0)
                return 0;
        }
        NUMBER_TYPE m = (n - 1) >> __builtin_ctz(n - 1);
        for (NUMBER_TYPE p : B)
        {
            NUMBER_TYPE t = m, a = mypow(p, m, n);
            while (t != n - 1 && a != 1 && a != n - 1)
            {
                a = mul(a, a, n);
                t *= 2;
            }
            if (a != n - 1 && t % 2 == 0)
                return 0;
        }
        return 1;
    }

    inline const NUMBER_TYPE getfecsum(NUMBER_TYPE _n)
    {
        NUMBER_TYPE sum = 0;
        while (_n)
        {
            sum += _n % 10;
            _n /= 10;
        }
        return sum;
    };

    NUMBER_TYPE PR(NUMBER_TYPE n)
    {
        for (NUMBER_TYPE p : B) 
            if (n % p == 0)
                return p;
        auto f = [&](NUMBER_TYPE x) -> NUMBER_TYPE {
            x = mul(x, x, n) + 1;
            return x >= n ? x - n : x;
        };
        NUMBER_TYPE x = 0, y = 0, tot = 0, p = 1, q, g;
        for (NUMBER_TYPE i = 0; (i & 255) || (g = gcd(p, n)) == 1; i++, x = f(x), y = f(f(y)))
        {
            if (x == y)
            {
                x = tot++;
                y = f(x);
            }
            q = mul(p, abs(x - y), n);
            if (q) p = q;
        }
        return g;
    }

    vector<NUMBER_TYPE> fac(NUMBER_TYPE n)
    {
        if (n <= 1)
            return {};
        if (MR(n))
            return {n};
        NUMBER_TYPE d = PR(n);
        auto v1 = fac(d), v2 = fac(n / d);
        auto i1 = v1.begin(), i2 = v2.begin();
        vector<NUMBER_TYPE> ans;
        while (i1 != v1.end() || i2 != v2.end()) 
            if (i1 == v1.end()) 
                ans.pb(*i2++); 
            else if (i2 == v2.end()) 
                    ans.pb(*i1++); 
                else if (*i1 < *i2) 
                        ans.pb(*i1++); 
                    else 
                        ans.pb(*i2++);
        return ans;
    }

public:

    Pollard_Rho(){
        B = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    }

    vector<NUMBER_TYPE> fac_pri(NUMBER_TYPE n)
    {
        return fac(n);
    }
};
 
 Pollard_Rho<int> pr;

void solve()
{
    int n;
    cin >> n;
    if(pr.MR(n)) cout << "Prime\n";
    else cout << pr.fac_pri(n).back() << "\n";
}

signed main()
{
#ifndef D
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