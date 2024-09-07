// #define D
#include <bits/stdc++.h>
using namespace std;

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}

template <typename T>
class SegTreeLazyRangeSet {
  vector<T> tree, lazy;
  vector<T> *arr;
  vector<bool> ifLazy;
  int n, root, n4, end;

  void maintain(int cl, int cr, int p) {
    int cm = cl + (cr - cl) / 2;
    if (cl != cr && ifLazy[p]) {
      lazy[p * 2] = lazy[p],ifLazy[p*2] = 1;
      lazy[p * 2 + 1] = lazy[p],ifLazy[p*2+1] = 1;
      tree[p * 2] = lazy[p] * (cm - cl + 1);
      tree[p * 2 + 1] = lazy[p] * (cr - cm);
      lazy[p] = 0;
      ifLazy[p] = 0;
    }
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    maintain(cl, cr, p);
    if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
    if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
    return sum;
  }

  void range_set(int l, int r, T val, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      lazy[p] = val;
      ifLazy[p] = 1;
      tree[p] = (cr - cl + 1) * val;
      return;
    }
    int m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m) range_set(l, r, val, cl, m, p * 2);
    if (r > m) range_set(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void build(int s, int t, int p) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

 public:
  explicit SegTreeLazyRangeSet<T>(vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = vector<T>(n4, 0);
    lazy = vector<T>(n4, 0);
    ifLazy = vector<bool>(n4,0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(int p, int depth = 0) {
    if (p > n4 || tree[p] == 0) return;
    show(p * 2, depth + 1);
    for (int i = 0; i < depth; ++i) putchar('\t');
    printf("%d:%d\n", tree[p], lazy[p]);
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

  void range_set(int l, int r, T val) { range_set(l, r, val, 0, end, root); }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    using segi = SegTreeLazyRangeSet<int>;
    vector<vector<int>> buildtmps(27,vector<int>(n+1));
    vector<segi> segs;
    lop(i,1,n+1) buildtmps[s[i-1]-'a'][i] = 1;
    lop(i,0,27) segs.pb(segi(buildtmps[i]));


    string ans;
    // lop(i,1,n+1)
    // {
    //     lop(j,0,27) 
    //         if(segs[j].range_sum(i,i)) {
    //             ans.pb('a'+j);
    //             break;
    //         }
    // }
    // cout << ans << "\n";

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int op;
        cin >> op;
        if(op == 1) {// 增序
            int curg = l;
            lop(i,0,27) 
            {
                int t = segs[i].range_sum(l,r);
                if(t == 0) continue;
                segs[i].range_set(l,r,0);
                // cout << "set:" << (char)('a' + i) << " " << l << " " << r << " -> " << 0 << "\n";
                segs[i].range_set(curg,curg+t-1,1);
                // cout << "set:" << (char)('a' + i) << " " << curg << " " << curg+t-1 << " -> " << 1 << "\n";
                // l = curg+t;
                curg += t;
            }
        } else {
            int curg = r;
            lop(i,0,27)
            {
                int t = segs[i].range_sum(l,r);
                if(t == 0)continue;
                segs[i].range_set(l,r,0);
                segs[i].range_set(curg-t+1,curg,1);
                curg -= t;
            }
        }
    // string ans;
    }
        ans.clear();
        lop(i,1,n+1)
        {
            lop(j,0,27) 
                if(segs[j].range_sum(i,i)) {
                    ans.pb('a'+j);
                    // cout << "find 1 at:" << i << " " << (char)('a'+j) << " " << segs[j].range_sum(i,i) << "\n";
                    break;
                }
        }
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
