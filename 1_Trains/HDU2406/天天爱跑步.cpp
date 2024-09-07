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
    vector<vector<int>> cnj(n+1);
    lop(i,1,n+1)
    {
        int u,v;
        cin >> u >> v;
        cnj[u].pb(v); 
        cnj[v].pb(u); 
    }
    deque<int> ring;
    vector<int> vst(n+1);
    int flag = 0;
    auto findRing = [&](auto self,int p,int f ) -> void {
        ring.push_back(p);
        if(vst[p]) {vst[p] = 2;flag = 1;return;}
        vst[p] = 1;
        for(auto x:cnj[p])
        {
            if(x != f) {
                self(self,x,p);
            }
        }
        if(vst[p] == 2) flag = 2;
        if(flag == 0) ring.pop_back();
        else if(flag == 2) ring.pop_front();
    };
    findRing(findRing,1,0);
    for(auto x:ring) cout << x <<" " ;cout << "\n";
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
