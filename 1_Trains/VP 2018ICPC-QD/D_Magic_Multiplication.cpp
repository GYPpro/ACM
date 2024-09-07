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
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define pii pair<int,int>
#define se second

void sort(auto &x)
{
    sort(x.begin(), x.end());
};

using namespace std;

class solution
{
private:
public:
    void solve()
    {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> c;
        for(auto x:s) c.pb(x-'0');

        auto getNXT = [&](int f,int n) -> pii {
            // cout << "getnxt :" << f << " " << c[f] << " " << n << "\n"; 
            if(n < 0) return {-1,-1};
            if(f >= c.size()) return {-1,-1};
            if(n == 0) {
                if(c[f] == 0) return {0,f+1};
                else return {-1,-1};
            } else if(c[f]%n == 0) return {c[f],f+1};
            else if(f +1 >= c.size()) return {-1,-1};
            else if((c[f]*10 + c[f+1])%n == 0 && (c[f]*10 + c[f+1])/n < 10) return {c[f]*10 + c[f+1],f+2};
            else return {-1,-1};
        };

        // vector<int> a,b;
        vector<int> a(1);
        vector<int> b;
        auto checkline = [&](int f,int a) -> pii {
            int id = f;
            int TTL = 0;
            while(TTL < m) {
                auto rt = getNXT(id,a);
                if(rt.first == -1) return {0,-1};
                // cout << id << " " << TTL << " " << rt.first << "\n";
                if(a * b[TTL] != rt.first) return {0,-1};
                TTL ++;
                id = rt.second;
            } return {1,id};
        }; 
        auto check = [&](int a0) -> bool {
            a.clear();
            a.pb(a0);
            b.clear();
            int id = 0;
            while(b.size() < m) {
                auto rt = getNXT(id,a0);
                if(rt.first == -1) return 0;
                b.pb(rt.first/a0);
                id = rt.second;
            }
            // for(auto x:a) cout << x;cout << "\n";
            // for(auto x:b) cout << x << " ";cout << "--" << a0 << "\n";
            while(a.size() < n) {
                // cout << "--" << a.size() << " " << id << "--\n";
                auto rt = getNXT(id,b[0]);
                if(rt.first == -1) return 0;
                a.pb(b[0] == 0 ? rt.first : rt.first/b[0]);
                // cout << rt.first << " " << rt.second << "\n";
                // cout << "gnc a[" << a.size()-1 << "]: " << a[a.size()-1] << "\n";
                auto rt2 = checkline(id,a[a.size()-1]);
                // cout << "checked " << id << " " << a[a.size()-1] << " :" <<rt2.first << " " << rt2.second << "\n";
                if(rt2.first) id = rt2.second;
                else return 0;
            }
            // cout << a.size() << " " << b.size() << "\n";
            if(id < c.size()) return 0;
            if(a.size() != n || b.size() != m) return 0;
            // cout << id << "\n";
            return 1;
        };
        for(int i = 1;i < 10;i++) {
            if(check(i)){
                for(auto x:a) cout << x;cout << " ";
                for(auto x:b) cout << x;cout << "\n";
                return;
            }
        }
        cout << "Impossible\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

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