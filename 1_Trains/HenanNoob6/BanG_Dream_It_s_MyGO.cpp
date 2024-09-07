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

int n, m, total;
int deg[200001], u[200001], v[200001];
bool vis[200001];

struct Edge {
  int to, nxt;
} edge[200001];

int cntEdge, head[100001];

void addEdge(int u, int v) {
  edge[++cntEdge] = {v, head[u]}, head[u] = cntEdge;
}

int getsring() {
//   scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
     deg[u[i]]++, deg[v[i]]++;
  for (int i = 1; i <= m; i++) {
    if ((deg[u[i]] == deg[v[i]] && u[i] > v[i]) || deg[u[i]] < deg[v[i]])
      swap(u[i], v[i]);
    addEdge(u[i], v[i]);
  }
  for (int u = 1; u <= n; u++) {
    for (int i = head[u]; i; i = edge[i].nxt) vis[edge[i].to] = true;
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      for (int j = head[v]; j; j = edge[j].nxt) {
        int w = edge[j].to;
        if (vis[w]) total++;
      }
    }
    for (int i = head[u]; i; i = edge[i].nxt) vis[edge[i].to] = false;
  }
  return total;
}

void solve()
{
    cin >> n >> m;
    vector<vector<int>> cnj(n+1);
    set<pii> ttledges;
    lop(i,1,m+1)
    {
        int tu,tv;
        cin >> tu >> tv;
        u[i] = tu,v[i] = tv;
        cnj[tu].pb(tv),cnj[tv].pb(tu);
        ttledges.insert(ord(tu,tv));
    }
    int ans = 0;
    auto C = [](int _n) -> int {
        if(_n < 3) return 0;
        return ((_n) * (_n-1) * (_n-2))/6;
    };
    ans -= getsring()*2;
    // cout << ans << "\n";
    lop(i,1,m+1) ans += C(deg[i]);
    // cout << ans << "\n";
    for(auto x:ttledges) ans += (deg[x.fi]-1) * (deg[x.se]-1);
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
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
