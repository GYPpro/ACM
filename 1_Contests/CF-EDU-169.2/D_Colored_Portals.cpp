// #define D

// #define set unordered_set

#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define fi first
#define se second
const int INF = 11451810;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define a(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;
#define map unordered_map

 
const inline int a2m(const int &a,const int &b){
    if(a == 0 && b == 1) return 0;
    if(a == 0 && b == 2) return 1;
    if(a == 0 && b == 3) return 2;
    if(a == 1 && b == 2) return 3;
    if(a == 1 && b == 3) return 4;
    if(a == 2 && b == 3) return 5;
}
 
const inline int rev(const int &a){
    switch (a)
    {
    case 0: return 5;
    case 1: return 4;
    case 2: return 3;
    case 3: return 2;
    case 4: return 1;
    case 5: return 0;
    default:
        break;
    }
    return 0;
}

class SparseTable {
  using VT = vector<int>;
  using VVT = vector<VT>;
  using func_type = function<int(const int &, const int &)>;

  VVT ST;
  int len;

  static int default_func(const int &t1, const int &t2) { return max(t1, t2); }

    vector<int> preLog;

  func_type op;

 public:
 
  void build(const vector<int> &v, func_type _func = default_func) {
    op = _func;
    len = v.size();
    int l1 = ceil(log2(len)) + 1;
    ST.assign(len, VT(l1, 0));
    for (int i = 0; i < len; ++i) {
      ST[i][0] = v[i];
    }
    for (int j = 1; j < l1; ++j) {
      int pj = (1 << (j - 1));
      for (int i = 0; i + pj < len; ++i) {
        ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
      }
    }
    preLog.resize(len+1);
    lop(i,1,len+1) preLog[i] = floor(log2(i));
  }

  int getsum(int l, int r) {
    if(r < l) return 0;
    l = max(0,l),r = min(len-1,r);
    if(r == 0) return 0;
    int lt = r - l + 1;
    int q = preLog[lt];
    return op(ST[l][q], ST[r - (1 << q) + 1][q]);
  }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    map<char,int> mp = {
        {'B',0},
        {'G',1},
        {'R',2},
        {'Y',3}
    };

    // vector<pair<int,int>> arr(n);
    vector<int> t(n+1);
    lop(i,0,n)
    {
        char c1,c2;
        cin >> c1 >> c2;
        // arr[i].fi = mp[c1],arr[i].se = mp[c2];
        t[i+1] = a2m(mp[c1],mp[c2]);
    }

    vector<SparseTable> segs(6);
    vector<vector<int>> buildtmp(6,vector<int>(n+1,0));
    lop(i,0,6)
    {
        lop(j,1,n+1) if(t[j] == i) buildtmp[i][j] = 1;
    }
    lop(i,0,6) segs[i].build(buildtmp[i]);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(l > r) swap(l,r);
        if(l == r){ cout << 0 << "\n";continue;}
        function<bool(int)> check = [&](int k) -> bool {
            if(k < r-l) return 0;
            k = (k-(r-l))/2;
            lop(i,0,6)
            {
                if(
                    i == rev(t[l]) || 
                    ((i == t[l]  && t[r] == rev(t[l]) )) 
                    ) continue; 
                
                if(segs[i].getsum(l-k,l-1) > 0 || segs[i].getsum(l+1,r+k) > 0) return 1;
            }
            return 0;
        };
        int sl = 0, sr = 4e5;  
        while (sl + 1 < sr) {      
            int mid = (sl + sr) >> 1;  
            if (check(mid))       
            sr = mid;           
            else
            sl = mid; 
        }
        if(sr >= 4e5) cout << "-1\n";
        else cout << sr << "\n";
    }
    return;
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

    return 0;
}
