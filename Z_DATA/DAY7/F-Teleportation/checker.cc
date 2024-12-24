#include "testlib.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
 
using i64 = long long;
using i128 = __int128_t;
 
struct BigInt {
    static constexpr i64 base = 1'000'000'000'000'000'000ll;
    static constexpr int len = 12;
 
    static BigInt from_int(i64 num) {
        BigInt x = {};
        x.v[0] = num % base;
        x.v[1] = num / base % base;
        return x;
    }
 
    static BigInt from_string(const std::string& str) {
        BigInt x = {};
        for (int i = 0; 18 * i < str.size(); i++) {
            int r = int(str.size()) - 18 * i;
            int l = max(r - 18, 0);
            i64 y = 0;
            for (int j = l; j < r; j++) {
                y = y * 10 + str[j] - '0';
            }
 
            x.v[i] = y;
        }
        return x;
    }
 
    std::string to_string() const {
        std::stringstream ss;
        
        bool first = true;
        for (int i = len - 1; i >= 0; i--) {
            if (first) {
                if (v[i]) {
                    first = false;
                    ss << v[i];
                }
            } else {
                ss << setfill('0') << setw(18) << v[i];
            }
        }
 
        if (first) {
            ss << '0';
        }
 
        return ss.str();
    }
 
    bool operator >= (const BigInt& x) const {
        for (int i = len - 1; i >= 0; i--) {
            if (v[i] < x.v[i]) {
                return false;
            } else if (v[i] > x.v[i]) {
                return true;
            }
        }
        return true;
    }
 
    bool operator <= (const BigInt& x) const {
        return x >= *this;
    }
 
    bool operator == (const BigInt& x) const {
        for (int i = 0; i < len; i++) {
            if (v[i] != x.v[i]) {
                return false;
            }
        }
        return true;
    }
 
    bool operator != (const BigInt& x) const {
        return !(x == *this);
    }
    
    BigInt operator + (const BigInt& x) const {
        BigInt res = {};
        i64 c = 0;
        for (int i = 0; i < len; i++) {
            res.v[i] = v[i] + x.v[i] + c;
            c = 0;
            if (res.v[i] >= base) {
                c = 1;
                res.v[i] -= base;
            }
        }
        return res;
    }
 
    // should ensure that *this >= x
    BigInt operator - (const BigInt& x) const {
        BigInt res = {};
        i64 c = 0;
        for (int i = 0; i < len; i++) {
            res.v[i] = v[i] - x.v[i] + c;
            c = 0;
            if (res.v[i] < 0) {
                c = -1;
                res.v[i] += base;
            }
        }
        return res;
    }
 
    BigInt operator * (const BigInt &x) const {
        BigInt res = {};
 
        for (int i = 0; i < len; i++) {
            for (int j = 0; i + j < len; j++) {
                i128 tmp = i128(v[i]) * x.v[j];
                for (int k = i + j; k < len && tmp; k++) {
                    res.v[k] += tmp % base;
                    tmp /= base;
                    if (res.v[k] >= base) {
                        tmp++;
                        res.v[k] -= base;
                    }
                }
            }
        }
 
        return res;
    }
 
    BigInt operator % (const BigInt &x) const {
 
        BigInt r = *this;
 
        vector<BigInt> pows = {x};
        BigInt y = x;
        while (y = y + y, y <= r) {
            pows.push_back(y);
        }
 
        for (int i = int(pows.size()) - 1; i >= 0; i--) {
            // cerr << "-- " << pows[i].to_string() << " " << r.to_string() << endl;
            if (r >= pows[i]) {
                r = r - pows[i];
            }
        }
 
        return r;
    }
 
    i64 v[len];
};
 
void check_valid_num(const std::string& num) {
    if (num.size() == 0) {
        quitf(_wa, "number too short");
    }
    if (num.size() > 101) {
        quitf(_wa, "number too long");
    }
    for (int i = 0; i < int(num.size()); i++) {
        if (num[i] < '0' || num[i] > '9') {
            quitf(_wa, "not a positive integer");
        }
    }
    if (num[0] == '0') {
        quitf(_wa, "leading zero");
    }
}
 
void check_valid_range(const std::string& num) {
    // valid range is [3, 10^100]
    if (num.size() == 1 && num[0] < '3') {
        quitf(_wa, "number smaller than 3");
    }
 
    if (num.size() == 101) {
        // 100..0 (100 zeros)
        for (int i = 0; i < int(num.size()); i++) {
            if (num[i] > '0' + (i == 0)) {
                quitf(_wa, "number larger than 10^100");
            }
        }
    }
}
 
int main(int argc, char *argv[]) {
    setName("teletransport checker");
 
    registerTestlibCmd(argc, argv);
 
    int t = inf.readInt();
    for (int cas = 1; cas <= t; cas++) {
        //setTestCase(cas);
 
        int x = inf.readInt();
        int y = inf.readInt();
 
        int m = ouf.readInt(1, 150, "m");
 
        vector<string> v;
        for (int i = 0; i <= m; i++) {
            std::string num = ouf.readWord("[0-9]{1,101}", "v_i");
            check_valid_num(num);
            check_valid_range(num);
            v.push_back(num);
        }
 
        if (v[0] != to_string(x)) {
            quitf(_wa, "the first number should be x (%s != %d)", v[0].c_str(), x);
        }
 
        if (v.back() != to_string(y)) {
            quitf(_wa, "the last number should be y (%s != %d)", v.back().c_str(), y);
        }
 
        vector<BigInt> nums(m + 1);
        for (int i = 0; i <= m; i++) {
            nums[i] = BigInt::from_string(v[i]);
        }
 
        for (int i = 0; i < m; i++) {
            BigInt s = nums[i] + nums[i + 1];
            BigInt p = nums[i] * nums[i + 1];
            BigInt r = p % s;
            // cerr << nums[i].to_string() << " " << nums[i + 1].to_string() << " " << s.to_string() << " " << p.to_string() << " " << r.to_string() << endl;
            if (r != BigInt::from_int(0)) {
                quitf(_wa, "can not go from v[%d] %s to v[%d] %s", i, v[i].c_str(), i + 1, v[i + 1].c_str());
            }
        }
 
    }
 
    quitf(_ok, "the answer is valid");
 
    return 0;
}