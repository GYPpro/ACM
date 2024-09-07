#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>

const int m1 = 998244353;
const int m2 = 1e9+7;
const int b1 = 257;
const int b2 = 229;

int inv1,inv2;

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

using namespace std;

class solution
{
private:

public:
    void solve()
    {

        // int n;
        string a,b;
        cin >> a >> b;
        set<pii> Ahashs;
        int n = max(a.size(),b.size())+1;
        int cap = a.size();
        vector<int> prfb1(n);prfb1[0] = 1;
        for(int i = 1;i <= n;i ++) prfb1[i] = prfb1[i-1]*b1 % m1;

        vector<int> prfb2(n);prfb2[0] = 1;
        for(int i = 1;i <= n;i ++) prfb2[i] = prfb2[i-1]*b2 % m2;
        pii inids = {0,0};
        auto tm = [](pii & f) -> void {
            f.fi %= m1;
            f.se %= m2;
        };
        for(int i = 0;i < a.size();i ++)
            inids.first += a[i] * prfb1[i],inids.second += a[i]*prfb2[i],tm(inids);
        Ahashs.insert(inids);
        for(int i = 0;i < a.size();i ++) {
            inids.first -= a[a.size()-i-1] * prfb1[a.size()-1];
            inids.second -= a[a.size()-i-1] * prfb2[a.size()-1];
            tm(inids);
            inids.first *= b1,inids.second *= b2;
            tm(inids);
            inids.first += a[a.size()-i-1]; 
            inids.second += a[a.size()-i-1]; 
            tm(inids);
            Ahashs.insert(inids);
        }
        inids = {0,0};
        for(int i = 0;i < a.size();i ++)
            inids.first += b[i] * prfb1[i],inids.second += b[i]*prfb2[i],tm(inids);
         
        auto pop = [&](int i) -> void {
            inids.first -= a[i];
            inids.first *= inv1;
            inids.second -= a[i];
            inids.second *= inv2;
            tm(inids);
        };

        auto push = [&](char c) -> void {
            inids.first += c * prfb1[cap-1];
            inids.second += c * prfb2[cap-1];
            tm(inids);
        };
        
        int ans = 0;
        
        for(int i = 0;i + cap < b.size();i ++)
        {
            if(Ahashs.find(inids) != Ahashs.end()) ans ++;
            pop(0),push(b[i+cap]);
        }
        cout << ans << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tmp;

    exgcd(b1,m1,inv1,tmp);
    exgcd(b2,m2,inv2,tmp);

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