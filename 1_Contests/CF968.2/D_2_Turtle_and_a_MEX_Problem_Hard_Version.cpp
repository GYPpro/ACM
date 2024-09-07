// #define D

// #define set unordered_set

#pragma GCC optimize(2)

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

void solve()
{
    int n,m;
    cin >> n >> m;
    m;
    vector<set<int>> mtx(n+1);
    lop(i,0,n)
    {
        int li;
        cin >> li;
        while(li --) {
            int t;
            cin >> t;
            mtx[i].insert(t);
        }
    }

    auto getMEX2 = [&](int i) -> pii {
        int MEX = 0;
        int t = 0;
        pii rt;
        for(;;)
        {
            if(mtx[i].find(MEX) != mtx[i].end()) MEX ++;
            else if(t == 0) {
                rt.fi = MEX;
                MEX ++;
                t = 1;
                if(mtx[i].find(MEX) != mtx[i].end()) MEX ++;
            } else return {rt.fi,MEX};
        }
        // return MEX;
    };
    map<int,vector<int>> cnj;
    // map<pii,int> edgecnt;
    map<int,int> vst;
    int orimx = 0;
    const int E = -1;
    lop(i,0,n)
    {
        auto rt = getMEX2(i);
        // cnj[E].pb({rt.fi});
        // edgecnt[{rt.fi,rt.se}] ++;
        vst[rt.fi] = E;
        vst[rt.se] = E;
        orimx = max(orimx,rt.fi);
        cnj[rt.fi].pb({rt.se});
    }
    function<int(int,int)> dfs = [&](int p,int f) -> int {
        // cout << "dfs:" << p << " " ;
        if(vst[p] != E) return vst[p];
        int mx = p;
        for(auto x:cnj[p])
        {
            if(x == f) continue;
            mx = max(mx,dfs(x,p));
        }
        return vst[p] = mx;
    };
    // dfs(cnj;
    // for(auto x:cnj) vst[x.fi] = E;
    for(auto x:cnj) {
        if(vst[x.fi] == E) dfs(x.fi,E);
    }
    // for(auto x:vst) cout << x.fi << " " << x.se << " | ";cout << "\n";

    // int sum = 0;

    // lop(i,0,n) cout << getMEX2(i).fi << " " << getMEX2(i).se << " | " ;cout << "\n";
    int mx = 0;
    int ecmx = 0;
    for(auto x:vst) if(cnj[x.fi].size() >= 2) ecmx = max(ecmx,x.se);
    for(auto x:vst) mx = max(mx,max(x.fi,x.se));
    ecmx = max(orimx,ecmx);
    // int low = 0;
    int ans = 0;

    auto f = [&](int x) -> int {
        if(vst.find(x) != vst.end())
        {
            return max(vst[x],max(x,ecmx));
        } else return max(x,ecmx);
    };

    lop(i,0,min(m+1,mx+1))
    {
        // cout << i << " " << f(i) << "\n";
        ans += f(i);
    }

    if(m > mx)  ans += m * (m+1)/2 - mx * (mx+1)/2;
    cout << ans << "\n";

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
