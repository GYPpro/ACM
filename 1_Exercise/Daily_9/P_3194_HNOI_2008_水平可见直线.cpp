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

using ld = long double;
using pis = array<int,3>;

bool comp(pis a,pis b) {
    if(a[0] == b[0]) return a[1] > b[1];
    else return a[0] > b[0];
};

ld getCovex(pis a,pis b) {
    // return (1.0L * (a[1] - b[1]) / (b[0]-a[0]));
    return (1.0L)*( (ld)a[1] - b[1] ) / (1.0L)*( (ld)b[0] - a[0] );
};

void solve()
{
    int n;
    cin >> n;
    vector<array<int,3>> linesI;
    lop(i,0,n)
    {
        int k,x;
        cin >> k >> x;
        linesI.pb({k,x,i+1});
    }
    vector<pis> lines;
    for(auto x:linesI) lines.pb(pis({x[0],x[1],x[2]}));
    sort(all(lines),comp);
    // for(auto x:lines) cout << x[0] << " " << x[1] << "\n";
    vector<pis> st;
    vector<int> ans;
    

    lop(i,0,n)
    {
        if(i > 0) if(lines[i][0] == lines[i-1][0]) continue;

        if(st.size() > 1) 
            while( st.size() > 1 && 
                   getCovex(st.back(),lines[i]) >= getCovex(st.back(),st[st.size()-2])
            ) st.pop_back(),ans.pop_back();
        st.pb(lines[i]);
        ans.pb(lines[i][2]);
    }
    // ans.resize(st.size());
    sort(all(ans));
    // lop(i,0,st.size()) cout << ans[i] << " ";cout << "\n";
    for(auto x:ans) cout << x << " ";
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
