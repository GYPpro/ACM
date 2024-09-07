// #define D

// #define set unordered_set

#pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
#define map unordered_map
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
using i128 = __int128;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<ordered_set> cnt(12);
    lop(i, 0, n)
    {
        i128 t = arr[i];
        i128 s = 1;
        int r = 1;
        while (s < 1e11)
        {
            // cnt[{r, ((t % k)) % k}]++;
            // cnt[r][((t % k)) % k] ++;
            cnt[r].insert(((t % k)) % k);
            t *= 10;
            s *= 10;
            r++;
        }
    }
    int ans = 0;
    auto getdit = [&](int _c) -> int
    {
        int t = 0;
        while (_c)
        {
            _c /= 10;
            t++;
        }
        return t;
    };
    
    auto check = [&](int _c) -> int {
        i128 t = _c;
        int f = getdit(_c);
        t *= (i128)pow(10,f);
        // cout << _c << " " << (int)(t + (i128)_c) << "\n";
        return (t + (i128)_c)%k == 0;
    };

    for(auto &x:cnt) sort(all(x));

    lop(i, 0, n)
    {
        // ans += cnt[{getdit(arr[i]) + 1, (k - (arr[i] % k)) % k}]; 
        // ans += cnt[getdit(arr[i])+1][(k - (arr[i] % k)) % k];
        // int l = lower_bound(all(cnt[getdit(arr[i])+1]),(k - (arr[i] % k)) % k) - cnt[getdit(arr[i])+1].begin();
        // int r = upper_bound(all(cnt[getdit(arr[i])+1]),(k - (arr[i] % k)) % k) - cnt[getdit(arr[i])+1].begin();
        // ans += r-l;
        ans += cnt[getdit(arr[i])+1].order_of_key((k - (arr[i] % k)) % k+1)-cnt[getdit(arr[i])+1].order_of_key(getdit(arr[i])+1);
        ans -= check(arr[i]);
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

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
