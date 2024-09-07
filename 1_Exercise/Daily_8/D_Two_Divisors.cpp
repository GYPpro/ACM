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

vector<int> pri;
vector<bool> vis((int)1e7+3, 0); 
void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    // return pri;
}

vector<int> priv_pri((int)1e7+2,-1);
void init2(int n){
    for(int i = 2;i <= n;i ++)
    {
        if(priv_pri[i] != -1) continue;
        for(int j = 1;j * i <= n;j ++)
        {
            if(priv_pri[ i * j ] == -1) priv_pri[ i * j ]= i;
        }
    }
};


vector<int> getfactor(int n){
    vector<int> ansls;
    while(n != 1) {
        ansls.pb(priv_pri[n]);
        int t = priv_pri[n];
        while(n%t == 0) n /= t;
    }
    if(n != 1) ansls.pb(n);
    return ansls;
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> anss;
    while(n--){
        int t;
        cin >> t;
        auto rt = getfactor(t);
        // cout << t << " : ";
        // for(auto x:rt) cout << x << " ";cout << "\n";
        if(rt.size() <= 1) {
            anss.pb({-1,-1});
        } else {
            int a = rt[0];
            int b = 1;
            lop(i,1,rt.size()) b *= rt[i];
            anss.pb({a,b});
        }
    }
    for(auto x:anss) cout << x.fi << " ";cout << "\n";
    for(auto x:anss) cout << x.se << " ";cout << "\n";
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
    init2(1e7+3);

    // lop(i,1,30) cout << i << " : " << priv_pri[i] << "\n";cout << "\n";

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
