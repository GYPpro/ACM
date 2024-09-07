// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<double,double>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
#define puv pair<U,V>
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

template <int MOD>
class mInt
{
public:
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
#define int long long

const int N = 1 << 21;
static const int mod1 = 1E9 + 7, base1 = 127;
static const int mod2 = 1E9 + 9, base2 = 131;
using U = mInt<mod1>;
using V = mInt<mod2>;
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
class hstring
{
public:
    vector<U> hash1;
    vector<V> hash2;
    string s;

    hstring() : hash1{1},hash2{1} { }

    hstring(string s_) : s(s_), hash1{1}, hash2{1}
    {
        build();
    }

    void build()
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
    { //修改 idx 位为 x
        int n = s.size() - 1;
        U ans1 = hash1.back() + val1[n - idx] * (x - s[idx]);
        V ans2 = hash2.back() + val2[n - idx] * (x - s[idx]);
        return {ans1, ans2};
    }

    hstring operator=(string s)
    {
        this->s = s;
        this->build();
        return *this;
    }

    friend ostream & operator<< (ostream & OUT,hstring &s)
    {
        OUT << s.s;
        return OUT;
    }

    friend istream & operator>> (istream & IN,hstring &s)
    {
        IN >> s.s;
        s.build();
        return IN;
    }

    operator pair<U, V>()
    {
        return this->get();
    }
};

class DS {
private:
    map<puv,vector<puv>> tablet;
    vector<puv> args;
    vector<bool> deleted; //[aligns]
    
    vector<int> privDeletedList,privInsertList;

public:
    DS(vector<puv> _args){
        args = _args;
        for(auto x:args) tablet[x] = vector<puv>();
    }

    void abort()
    {
        for(auto x:privDeletedList) deleted[x] = 0;
        for(auto x:privInsertList) deleted[x] = 1;
    }

    void commit()
    {
        privDeletedList.clear();
        privInsertList.clear();
    }

    void insert(vector<puv> insList)
    {
        lop(i,0,insList.size())
            tablet[args[i]].pb(insList[i]);
        privInsertList.pb(tablet[args[0]].size()-1);
        deleted.pb(0);
    }

    vector<puv> select_in(puv OFeild,puv condFeild,vector<puv> condVals)
    {

#ifdef D
        cout << "use select_in:" << OFeild.fi << " " << OFeild.se << "," << condFeild.fi << " " << condFeild.se << "," << condVals.size() << "\n";
#endif

        set<puv> condValSet;
        vector<puv> rtVal;
        for(auto x:condVals) condValSet.insert(x);
        lop(i,0,tablet[condFeild].size())
            if(deleted[i]) continue;
            else if(condValSet.find(tablet[condFeild][i]) != condValSet.end())
                rtVal.pb(tablet[OFeild][i]);
        return rtVal;
    }

    int delete_in(puv condFeild,vector<puv> condVals)
    {
        set<puv> condValSet;
        int deletedSum = 0;
        for(auto x:condVals) condValSet.insert(x);
        lop(i,0,tablet[condFeild].size()) 
            if(deleted[i]) continue;
            else if(condValSet.find(tablet[condFeild][i]) != condValSet.end())
            {
                deletedSum ++;
                deleted[i] = 1;
                privDeletedList.push_back(i);
            }
        return deletedSum;
    }

    void __DEBUG_PRINT_DATAS()
    {
        for(auto x:args) cout << x.fi << " " << x.se << "\n";
        for(auto x:args)
        {
            cout << x.fi << " " << x.se << " :";
            for(auto y:tablet[x]) cout << y.fi << " " << y.se << " ,";
            cout << "\n";
        }
        cout << "\n";
    }

};

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<hstring> args(n);
    for(auto &x:args) cin >> x;
    vector<puv> hashedArgs;
    for(auto x:args) hashedArgs.pb(x);
    DS db(hashedArgs);
    map<puv,string> rhash;
    while(q--)
    {
        string op;
        cin >> op;

        auto sub = [&](int l,int r,string &s) -> string{
            string rt;
            lop(i,l,r+1) rt.pb(s[i]);
            return s;
        };

        auto toNextSplit = [&](int &l,string &s) -> hstring{
            string rt;
            while(s[l] == ',' || s[l] == '(' || s[l] == ')') l++;
            while(1)
            {
                if(s[l] == ',' || s[l] == '(' || s[l] == ')') break;
                rt.pb(s[l]);
                l ++;
            } l ++;
            #ifdef D
            cout << "|" << rt << ":" << hstring(rt).get().fi << " " << hstring(rt).get().se << "|";
            #endif
            rhash[hstring(rt)] = rt;
            return hstring(rt);
        };
        
        vector<puv> listtoPrint;
        int inttoPrint = 0;
        int flag = 0;// 0:None 1:List 2:Int

        auto opGnc = [&](auto self,int l) -> vector<puv> {
            #ifdef D
            db.__DEBUG_PRINT_DATAS();
            #endif
            string func = toNextSplit(l,op).s;
            if(func == "begin"){
                111;
            } else if(func == "commit") {
                db.commit();
            } else if(func == "abort") {
                db.abort();
            } else if(func == "insert") {
                vector<puv> vals;
                lop(i,0,n) vals.push_back(toNextSplit(l,op));
                db.insert(vals);
            } else if(func == "select") {
                puv val1 = toNextSplit(l,op),
                    val2 = toNextSplit(l,op),
                    val3 = toNextSplit(l,op);
                listtoPrint = db.select_in( val1, val2, {val3});
                flag = 1;
            } else if(func == "select_in") {
                puv val1 = toNextSplit(l,op),
                    val2 = toNextSplit(l,op);
                listtoPrint = db.select_in( val1,val2,self(self,l));
                flag = 1;
            } else if(func == "delete") {
                puv val1 = toNextSplit(l,op),
                    val2 = toNextSplit(l,op);
                inttoPrint = db.delete_in(val1,{val2});
                flag = 2;
            } else if(func == "delete_in") {
                puv val1 = toNextSplit(l,op);
                inttoPrint = db.delete_in( val1, self(self,l));
                flag = 2;
            }
            return listtoPrint;
        };

        opGnc(opGnc,0);
#ifdef D
        cout << "----\n";
        cout << "flag:" << flag << "\n";
#endif
        switch (flag)
        {
        case 0:
            {
                111;
            } break;
        case 1:
            {
                cout << listtoPrint.size() << "\n";
                if(listtoPrint.size() == 0) continue;
                vector<string> outtmp;
                for(auto x:listtoPrint) outtmp.pb(rhash[x]);
                cout << outtmp[0] << "\n" << outtmp[(outtmp.size()+1)/2 -1] << "\n" << outtmp[outtmp.size()-1] << "\n";
            } break;
        case 2:
            {
                cout << inttoPrint << "\n";
            } break;
        
        default:
            break;
        }
#ifdef D
        cout << "----\n";
#endif
    }
}

void test()
{
    map<puv,int> mp;
    char op;
    while(1){cin >> op;
    switch (op)
    {
    case 'i':
        {
            U a;
            V b;
            int c;
            cin >> a >> b >> c;
            mp[{a,b}] = c;
            
        }
        break;
    case 'c':
        {
            U a;
            V b;
            cin >> a >> b;
            cout << mp[{a,b}] << "\n";
        }
        break;
    
    default:
        break;
    }}
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    init(5050);
    for (int i = 0; i < T; i++) solve();
    // for (int i = 0; i < T; i++) test();

    // system("pause");

    return 0;
}