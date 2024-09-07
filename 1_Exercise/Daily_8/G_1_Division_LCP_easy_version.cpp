// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
using namespace std;

class KMP
{
private:
    string s;
    string inis;

public:
    vector<int> pi;
    KMP(string _s)
    {
        s = _s;
        inis = s;
    }
    void prefix_function()
    {
        pi.clear();
        int n = (int)s.length();
        pi.resize(n);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return;
    }
    vector<int> find_occr(string p)
    {
        s = inis;
        s = p + "#" + s;
        prefix_function();
        vector<int> v;
        for (int i = p.size() + 1; i < s.size(); i++)
            if (pi[i] == p.size())
                v.push_back(i - 2 * p.size());
        return v;
    }
};

void solve()
{
    int n, ll, rr;
    cin >> n >> ll >> rr;
    string s;
    cin >> s;
    KMP kmp(s);
    auto underGape = [&](int g, vector<int> cur)
    {
        int cnt = 1;
        int prv = 0;
        sort(all(cur));
        lop(i, 0, cur.size())
        {
            if (cur[i] >= prv + g)
                prv = cur[i], cnt++;
        }
        return cnt;
    };

    auto check = [&](int k) -> bool
    {
        // int t = kmp.find_occr()
        string subs;
        // while(subs.size() < k) subs.
        lop(i, 0, k) subs.pb(s[i]);
        return underGape(k, kmp.find_occr(subs)) >= ll;
    };

    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << "\n";
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

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
