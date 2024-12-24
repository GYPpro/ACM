// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++)
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map
const int N = 1e6+3;
// vector<int> phi(1e6+5);
vector<int> pri;
vector<bool> not_prime(N);
vector<int> phi(N);
vector<int> pre;

void eula(int n = 1e6) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        phi[i * pri_j] = phi[i] * pri_j;
        break;
      }
      phi[i * pri_j] = phi[i] * phi[pri_j];
    }
  }
}

void solve()
{
    int n,k;
    cin >> n >> k;

    if(k <= n) {
        cout << 1 << "\n";
        return;
    }

    auto H  = [&](int i) {
        int res = 0; 
        int l = 1, r;
        while (l <= i) {
            r = n / (n / l);
            r = min(i,r);
            res += 1LL * (pre[r]-pre[l-1]) * (n / l);
            l = r + 1;
        }
        return res * 2 - n;
    };

    int l = 0,r = n;
    while(l < r) {
        int mid = l + r  + 1 >> 1;
        if(H(mid) > k) r = mid - 1;
        else l =  mid;
    }
    int plsd = H(r);
    int cost = pre[r] * 2 -1;
    int av = n/(r+1);
    if(plsd == k) cout << cost << "\n" ;
    else cout << cost + (k-plsd+av-1)/av << "\n";
}

signed main()
{
    eula();
    pre = phi;
    for(int i = 1;i < pre.size();i ++) pre[i] += pre[i-1];

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
