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


class DSU {
    std::vector<int> f, siz;
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        // std::iota(f.begin(), f.end(), 0);
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

bool cmp(pair<int,pii>a ,pair<int,pii>b)
{
    return a.fi > b.fi;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,pii>> q;
    map<pii,int> edgesum;
    set<int> nodelist;
    lop(i,0,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edgesum[ord(a,b)] = max(edgesum[ord(a,b)],c);
        nodelist.insert(a);
        nodelist.insert(b);
    }
    for(auto x:edgesum) q.push_back({x.se,x.fi});
    DSU dsu(n+1);
    int cnt = nodelist.size();
    sort(all(q),cmp);
    int it = 0;
    int maxn = 0;
    vector<int> B(n+1);
    while(it < q.size())
    {
        
        if(dsu.find(q[it].se.fi) == dsu.find(q[it].se.se)) {cout << q[it].fi << "\n";return;};
        if(B[q[it].se.fi]) dsu.merge(q[it].se.se,B[q[it].se.fi]);
        else B[q[it].se.fi] = q[it].se.se;
        if(B[q[it].se.se]) dsu.merge(q[it].se.fi,B[q[it].se.se]);
        else B[q[it].se.se] = q[it].se.fi;
            // cout << q[it].se.fi << " " << q[it].se.se << q[it].fi << "\n";
        it ++;
        // cnt --;
        // {
        //     cnt --;
        //     dsu.merge(q[it].se.fi,q[it].se.se);
        //     maxn = max(q[it].fi,maxn);
        // }
        // it ++;
    }
    // for(auto x:edgesum) if(dsu.find(x.fi.fi) == dsu.find(x.fi.se)) maxn = max(x.se,maxn);
    cout << 0 << "\n";
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

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
