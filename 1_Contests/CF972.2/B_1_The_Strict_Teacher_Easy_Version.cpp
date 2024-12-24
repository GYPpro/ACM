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
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> tec(m);
    for(auto &x:tec) cin >> x;
    set<int> st;
    for(auto x:tec) st.insert(x);
    st.insert(-INF);
    st.insert(INF);
    while(q--)
    {
        int t;
        cin >> t;
        auto it = st.lower_bound(t);
        int rd = *it;
        int ld = *(--it);
        // cout << rd << " " << ld << "\n";/*  */
        if(rd == INF) cout << abs(n-(*(--st.rbegin())))<< "\n";
        else if(ld == -INF) cout << abs(*(++st.begin()))-1<< "\n";
        else cout << abs(rd-ld)/2 << "\n";
        // cout << min({abs(rd-ld)/2,abs(n-(*(--st.rbegin()))),abs(*(++st.begin()))}) << "\n";
    }
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
