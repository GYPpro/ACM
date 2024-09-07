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

void solve()
{
    int n;
    cin >> n;
    // vector<set<int>> cnj(n+1);
    set<pii> edges;
    int edgecnt = 0;
    vector<int> vst(n+1);
    map<pii,int> rec;
    auto addedge = [&](int a,int b) -> void {
        bool f = 0;
        edges.insert(ord(a,b));
        // vst[a] = vst[b] = 1;
        // if(cnj[a].find(b) != cnj[a].end()) cnj[a].insert(b),f = 1;
        // if(cnj[b].find(a) != cnj[b].end()) cnj[b].insert(a),f = 1;
        // edgecnt += f;
    };
    // set<int> NTLIST;
    lop(i,2,n+1)
    {
        int t;
        auto ask = [&](int a,int b)
        {
            // if(rec.find(ord(a,b)) != rec.end()) return rec[ord(a,b)];
            cout << "? " << a << " " << b << "\n";
            cin >> t;
            // return rec[ord(a,b)] = t;
            return t;
        };
        // vector<int> curLine;
        function<void(int,int)> dfs = [&](int a,int b) -> void{
            vst[a] = vst[b] = 1;
            auto rt = ask(a,b);
            
            if(rt == a || rt == b){addedge(a,b); return;}
            // int m = a + b >> 1;
            if(!vst[rt]) dfs(a,rt);
            dfs(rt,b);
        };
        dfs(1,i);
        // curLine.pb(1),curLine.pb(i);
        // for(auto x:curLine) cout << x << " ";cout << "\n";
        // lop(ii,0,(int)curLine.size()-1) addedge(curLine[ii],curLine[ii+1]);
    }
    cout << "! ";
    for(auto x:edges) cout << x.fi << " " << x.se << " ";
    cout << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
