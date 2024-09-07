#include <bits/stdc++.h>
using namespace std;
#define I64 long long
#define pii pair<I64, I64>
const I64 INF = 1145141919810LL;
using namespace std;

class myTimer{
    map<string,std::chrono::_V2::system_clock::time_point> stamps;
public:
    void addStamp(const string &s)
    {
        stamps[s] = chrono::system_clock::now();
    }
    void printDurStamp(const string &s,char ifUpdate = 'Y')
    {
        std::chrono::_V2::system_clock::time_point cur = chrono::system_clock::now();
        std::chrono::nanoseconds dur = cur - stamps[s];
        I64 msec = 100.0L * dur.count() * chrono::microseconds::period::num / chrono::microseconds::period::den; //ms 360000
        // cout << msec/360000LL << "." << msec/6000 << "." << msec/100 << ":" << msec%100 << " miliSec passed since last stampes:"
        cout << std::format(" >> {:2d}.{:2d}.{2d}:{2d} mili sec since last stamps:{:11s} << \n",
            msec/360000LL, (msec/6000)%360000, (msec/100)%6000, msec%100 , s );
        if(ifUpdate == 'Y') updateStamp(s);
    }
    void updateStamp(const string &s)
    {
        stamps[s] = chrono::system_clock::now();
    }
    void eraseStamp(const string &s)
    {
        stamps.erase(s);
    }
};

template<typename NUMBER_TYPE>
class Pollard_Rho
{
private:

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
 
 
template<typename NUMBER_TYPE>
class Brute_Force{
public:
    Brute_Force(){
        
    }

};


int main()
{
    
}