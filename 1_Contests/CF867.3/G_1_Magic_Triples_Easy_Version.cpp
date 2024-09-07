#include <iostream>

#define map unordered_map
#define set unordered_set

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

vector<int> init(int n)
{
    vector<int> pri;
    vector<bool> vis(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    return pri;
}

auto pri = init(1e5+2);

struct BigIntTiny {
    int sign;
    std::vector<int> v;

    BigIntTiny() : sign(1) {}
    BigIntTiny(const std::string &s) { *this = s; }
    BigIntTiny(int v) {
        char buf[21];
        sprintf(buf, "%d", v);
        *this = buf;
    }
    void zip(int unzip) {
        if (unzip == 0) {
            for (int i = 0; i < (int)v.size(); i++)
                v[i] = get_pos(i * 4) + get_pos(i * 4 + 1) * 10 + get_pos(i * 4 + 2) * 100 + get_pos(i * 4 + 3) * 1000;
        } else
            for (int i = (v.resize(v.size() * 4), (int)v.size() - 1), a; i >= 0; i--)
                a = (i % 4 >= 2) ? v[i / 4] / 100 : v[i / 4] % 100, v[i] = (i & 1) ? a / 10 : a % 10;
        setsign(1, 1);
    }

    int get_pos(unsigned pos) const { return pos >= v.size() ? 0 : v[pos]; }
    BigIntTiny &setsign(int newsign, int rev) {
        for (int i = (int)v.size() - 1; i > 0 && v[i] == 0; i--)
            v.erase(v.begin() + i);
        sign = (v.size() == 0 || (v.size() == 1 && v[0] == 0)) ? 1 : (rev ? newsign * sign : newsign);
        return *this;
    }
    std::string to_str() const {
        BigIntTiny b = *this;
        std::string s;
        for (int i = (b.zip(1), 0); i < (int)b.v.size(); ++i)
            s += char(*(b.v.rbegin() + i) + '0');
        return (sign < 0 ? "-" : "") + (s.empty() ? std::string("0") : s);
    }
    bool absless(const BigIntTiny &b) const {
        if (v.size() != b.v.size()) return v.size() < b.v.size();
        for (int i = (int)v.size() - 1; i >= 0; i--)
            if (v[i] != b.v[i]) return v[i] < b.v[i];
        return false;
    }
    BigIntTiny operator-() const {
        BigIntTiny c = *this;
        c.sign = (v.size() > 1 || v[0]) ? -c.sign : 1;
        return c;
    }
    BigIntTiny &operator=(const std::string &s) {
        if (s[0] == '-')
            *this = s.substr(1);
        else {
            for (int i = (v.clear(), 0); i < (int)s.size(); ++i)
                v.push_back(*(s.rbegin() + i) - '0');
            zip(0);
        }
        return setsign(s[0] == '-' ? -1 : 1, sign = 1);
    }
    bool operator<(const BigIntTiny &b) const {
        return sign != b.sign ? sign < b.sign : (sign == 1 ? absless(b) : b.absless(*this));
    }
    bool operator==(const BigIntTiny &b) const { return v == b.v && sign == b.sign; }
    BigIntTiny &operator+=(const BigIntTiny &b) {
        if (sign != b.sign) return *this = (*this) - -b;
        v.resize(std::max(v.size(), b.v.size()) + 1);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
            carry += v[i] + b.get_pos(i);
            v[i] = carry % 10000, carry /= 10000;
        }
        return setsign(sign, 0);
    }
    BigIntTiny operator+(const BigIntTiny &b) const {
        BigIntTiny c = *this;
        return c += b;
    }
    void add_mul(const BigIntTiny &b, int mul) {
        v.resize(std::max(v.size(), b.v.size()) + 2);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
            carry += v[i] + b.get_pos(i) * mul;
            v[i] = carry % 10000, carry /= 10000;
        }
    }
    BigIntTiny operator-(const BigIntTiny &b) const {
        if (b.v.empty() || b.v.size() == 1 && b.v[0] == 0) return *this;
        if (sign != b.sign) return (*this) + -b;
        if (absless(b)) return -(b - *this);
        BigIntTiny c;
        for (int i = 0, borrow = 0; i < (int)v.size(); i++) {
            borrow += v[i] - b.get_pos(i);
            c.v.push_back(borrow);
            c.v.back() -= 10000 * (borrow >>= 31);
        }
        return c.setsign(sign, 0);
    }
    BigIntTiny operator*(const BigIntTiny &b) const {
        if (b < *this) return b * *this;
        BigIntTiny c, d = b;
        for (int i = 0; i < (int)v.size(); i++, d.v.insert(d.v.begin(), 0))
            c.add_mul(d, v[i]);
        return c.setsign(sign * b.sign, 0);
    }
    BigIntTiny operator/(const BigIntTiny &b) const {
        BigIntTiny c, d;
        BigIntTiny e=b;
        e.sign=1;

        d.v.resize(v.size());
        double db = 1.0 / (b.v.back() + (b.get_pos((unsigned)b.v.size() - 2) / 1e4) +
                           (b.get_pos((unsigned)b.v.size() - 3) + 1) / 1e8);
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            c.v.insert(c.v.begin(), v[i]);
            int m = (int)((c.get_pos((int)e.v.size()) * 10000 + c.get_pos((int)e.v.size() - 1)) * db);
            c = c - e * m, c.setsign(c.sign, 0), d.v[i] += m;
            while (!(c < e))
                c = c - e, d.v[i] += 1;
        }
        return d.setsign(sign * b.sign, 0);
    }
    BigIntTiny operator%(const BigIntTiny &b) const { return *this - *this / b * b; }
    bool operator>(const BigIntTiny &b) const { return b < *this; }
    bool operator<=(const BigIntTiny &b) const { return !(b < *this); }
    bool operator>=(const BigIntTiny &b) const { return !(*this < b); }
    bool operator!=(const BigIntTiny &b) const { return !(*this == b); }
};

class solution
{
private:

    // BigIntTiny A(int n,int m)
    // {
    //     BigIntTiny t = 1;
    //     for(int i = n-m;i <= n;i ++) t = t * (i?BigIntTiny(i):BigIntTiny(1));
    //     return t;
    // }

public:
    void solve()
    {
        int n;
        cin >> n;
        map<int,int> cnt;
        int maxn = 0;
        FI {
            int t;
            cin >> t;
            maxn = max(maxn,t);
            cnt[t] ++;
        }
        int ans = 0;
        
            map<int,int> factor;
            vector<pair<int,int>> amt;
            vector<int> at;
            set<int> pwf;
        for(auto x:cnt)
        {
            factor.clear();
            amt.clear();
            at.clear();
            pwf.clear();
            if(!x.se) continue;
            int t = x.fi;
            if(x.se >= 3) ans += x.se * (x.se -1LL) * (x.se -2LL);

            int p = 0;
            while(t > 1 && p < pri.size() && pri[p] * pri[p] <=  t)
            {
                // if(t % pri[p] == 0)
                // {
                //     factor[pri[p]] ++;
                //     t /= pri[p];
                    
                // } else p ++;
                while(t%pri[p] == 0)
                {
                    factor[pri[p]] ++;
                    t /= pri[p];
                }
                p ++;
            }
            for(auto xx:factor) amt.pb({xx.first,xx.se / 2});
            for(auto xx:amt)
                for(int i = 0;i < xx.second;i ++)
                    at.pb(xx.first);
            if(!at.size()) continue;
            for(int i = 0;i < (1<<at.size()) ;i ++)
            {
                int _t = 1;
                int _f = i;
                int idx = 0;
                while (_f)
                {
                    if(_f %2) _t *= at[idx];
                    _f /= 2;
                    idx ++;
                }
                pwf.insert(_t * _t);
            }

            // for(auto x:pwf) cout << x << " ";
            // cout << "\n";

            // // for(int i = 0;x.fi * pri[i] * pri[i] <= maxn && i < pri.size();i ++)
            // // {
            // //     int wad = pri[i];
            // //     do ans += cnt[wad * x.fi] * cnt[wad * x.fi * pri[i]] * x.se;
            // //     while ((wad *= pri[i] )<= maxn);
            // // }
            // for(int i = 2;i * i * x.fi <= maxn;i ++)
            //     if(cnt.find(i * i * x.fi) != cnt.end() && cnt.find(i * x.fi) != cnt.end())
            //         ans += cnt[i * i * x.fi] * cnt[i * x.fi] * x.se;
            pwf.erase(1);
            for(auto xx:pwf)
                if(cnt.find(x.fi / sqrt((long double)xx)) != cnt.end() && cnt.find(x.fi/xx) != cnt.end())
                    ans += cnt[x.fi / sqrt((long double)xx)] * cnt[x.fi/xx] * x.se;
        }
        cout << ans << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    cin >> T;
    // for(auto x:pri) cout << x << " ";
    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}