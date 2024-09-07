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
    int n,k;
    cin >> n >> k;
    vector<int> X(n+1);
    vector<int> A(n+1);
    lop(i,1,n+1) cin >> X[i];
    lop(i,1,n+1) cin >> A[i];
    // vector<vector<int>> orderedRing(n+1,vector<int>(0));
    // vector<set<int>> ifCNJ(n+1);
    // vector<int> vst(n+1);
    // function<int(int,int)> dfs = [&](int p,int c) -> int {
    //     // cout << "vst:" << p << "\n";
    //     if(vst[p]) return 0;
    //     vst[p] = 1;
    //     if(ifCNJ[c].find(p) != ifCNJ[c].end()) return 0;
    //     orderedRing[c].pb(p);
    //     ifCNJ[c].insert(p);
    //     dfs(X[p],c);
    //     return 0;
    // };
    // lop(i,1,n+1) dfs(X[i],i);
    // map<int,pii> TF;
    // lop(i,1,n+1)
    //     lop(j,0,orderedRing[i].size()) TF[orderedRing[i][j]] = {i,j};
    // vector<int> ans(n+1);

    // // for(auto x:orderedRing)
    // //     lop(i,0,x.size()) cout << x[i] << " \n"[i == x.size()-1];
    // // for(auto [u,v]:TF) cout << u << "," << v.fi << ":" << v.se << " ";cout << "\n";

    // lop(i,1,n+1){
    //     if(TF.find(i) == TF.end()) {
    //         int t = k;
    //         int p = X[i];
    //         while(TF.find(p) == TF.end()) {
    //             t --;
    //             p = X[p];
    //             // cout << p << "\n";
    //         }
    //         ans[i] = A[ orderedRing[TF[p].fi][ (TF[p].se+t) % ((int)orderedRing[TF[p].fi].size()-1) +1]];
    //     } else ans[i] = A[ orderedRing[TF[i].fi][ (TF[i].se+k) % ((int)orderedRing[TF[i].fi].size())]];
    // }

    // lop(i,1,n+1) cout << ans[i] << " ";cout << "\n";
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
