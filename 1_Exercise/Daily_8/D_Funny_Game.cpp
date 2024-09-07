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

class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        for(int i = 0;i < n;i ++) f[i] = i;
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        DSU dsu(n+1);
        vector<pii> ansl;
        auto MERGE = [&](int curn) -> void {
            map<int,set<int>> cnt;
            lop(i,0,n) cnt[arr[i]%curn].insert(dsu.find(i));
            int curmodint = 0;
            for(auto x:cnt)
                if(x.se.size() >= 2) {curmodint = x.fi;break;}
            vector<int> tbm;
            lop(i,0,n){
                if(tbm.size() >= 2) break;
                if(tbm.size()) if(dsu.find(tbm[0]) == dsu.find(i)) continue;
                if(arr[i]%curn == curmodint) tbm.pb(i);
            }
            ansl.pb({tbm[0],tbm[1]});
            dsu.merge(tbm[0],tbm[1]);
        };
        for(int i = n-1;i >= 1;i --) MERGE(i);
        cout << "YES\n";
        for(int i = n-2;i >= 0;i --) cout << ansl[i].fi+1 << " " << ansl[i].se+1 << "\n";
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