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

struct ST {
    const int n, k;
    vector<int> in1;
    vector<vector<int>> Max;
    ST(int n) : n(n), in1(n + 1), k(__lg(n)) {
        Max.resize(k + 1, vector<int>(n + 1));
    }
    void init() {
        for (int i = 1; i <= n; i++) {
            Max[0][i] = in1[i];
        }
        for (int i = 0, t = 1; i < k; i++, t <<= 1) {
            const int T = n - (t << 1) + 1;
            for (int j = 1; j <= T; j++) {
                Max[i + 1][j] = max(Max[i][j], Max[i][j + t]);
            }
        }
    }
    int getMax(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int k = __lg(r - l + 1);
        return max(Max[k][l], Max[k][r - (1 << k) + 1]);
    }
 };

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    ST st(n+1);
    st.in1 = arr;
    st.init();
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << st.getMax(l,r) << "\n";
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
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
