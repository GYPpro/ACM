#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int inf = 1E9;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::array<int, 5> dp;
    dp.fill(-inf);
    dp[0] = 0;
    
    const std::string t = "narek";
    
    for (int i = 0; i < n; i++) {
        auto ndp = dp;
        for (int x = 0; x < 5; x++) {
            int y = x;
            int res = dp[x];
            for (auto c : s[i]) {
                if (c == t[y]) {
                    y++;
                    if (y == 5) {
                        y = 0;
                        res += 5;
                    }
                } else if (t.find(c) != -1) {
                    res--;
                }
            }
            ndp[y] = std::max(ndp[y], res);
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = std::max(ans, dp[i] - i);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef FC
    freopen("C.A.in","r",stdin);
    freopen("C.A.std","w",stdout);
#endif
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}