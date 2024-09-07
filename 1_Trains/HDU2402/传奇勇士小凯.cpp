// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;
class MTP{
    public:
        int a,b; // a/b
        int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
        MTP(){};
        MTP(int c){a = c,b = 1;};
        MTP(int _a,int _b){a = _a,b = _b;gcd();};

        void gcd()
        {
            int t = gcd(a,b);
            a /= t,b /= t;
        }

        MTP operator+(MTP c)
        {
            int t = c.b * b;
            this->a = this->a * c.b + c.a * this->b;
            b = t;
            gcd();
            return *this;
        }
        MTP operator+(int _c)
        {
            MTP c(_c);
            int t = c.b * b;
            this->a = this->a * c.b + c.a * this->b;
            b = t;
            gcd();
            return *this;
        }
        bool operator==(MTP c)
        {
            this->gcd();
            c.gcd();
            if(a == c.a || b == c.b) return 1;
            else return 0;
        }
        double getdigit()
        {
            return (double)a/(double)b;
        }
        bool operator>(MTP c)
        {
            double ta = (double)a/(double)b;
            double tc = (double)c.a/(double)c.b;
            return ta > tc;
        }
        bool operator<(MTP c)
        {
            double ta = (double)a/(double)b;
            double tc = (double)c.a/(double)c.b;
            return ta < tc;
        }
        MTP operator*(MTP c)
        {
            // int t = c.b * b;
            // this->a = this->a * c.b + c.a * this->b;
        }
};
MTP max(MTP a,MTP b)
{
    if(a > b) return a;
    else return b;
}
bool comp(int a,int b) {return a < b;}
class solution
{
private:

public:
    void solve()
    {
        int n;
        cin >> n;
        vector<vector<int>> cnj(n+1);
        vector<int> vst(n+1);
        vector<MTP> wei(n+1);
        for(int i = 1;i < n;i ++)
        {
            int u,v;
            cin >> u >> v;
            cnj[u].pb(v);
            cnj[v].pb(u);
        }
        for(int i = 1;i <= n;i ++){
            int t;
            cin >> t;
            wei[i] = MTP(15,t);
            // cout << t << " " <<  wei[i].a << " " << wei[i].b << " " << wei[i].getdigit() << "\n";
        }
        // cout << "\n";
        auto dfs = [&](auto self,int p,int f) -> MTP {
            if(vst[p]) return MTP(1);
            vst[p] = 1;
            MTP t(0);
            for(auto x:cnj[p])
            {
                if(x != f) t = max(t,self(self,x,p));
            }
            // vst[p] = 0;
            return t + wei[p];
        };
        auto rt = dfs(dfs,1,0);
        rt.gcd();
        cout << rt.a << "/" << rt.b << "\n";
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}