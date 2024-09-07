#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 100;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1), son(n + 1), cnt(n + 1), sz(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<int> e[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    function<void(int, int)> init = [&](int id, int fa)
    {
        sz[id] = 1;
        for (auto x : e[id])
        {
            if (x == fa)
                continue;
            init(x, id);
            sz[id] += sz[x];
            if (sz[x] > sz[son[id]])
            {
                son[id] = x;
            }
        }
    };
    init(1, 0);
    int mx = 0, sum = 0;
    function<void(int, int, int)> get_ans = [&](int id, int fa, int sn) -> void
    {
        cnt[c[id]]++;
        if (cnt[c[id]] > mx)
        {
            mx = cnt[c[id]];
            sum = c[id];
        }
        else if (cnt[c[id]] == mx)
            sum += c[id];
        for (auto x : e[id])
        {
            if (x == fa || x == sn)
                continue;
            get_ans(x, id, sn);
        }
    };
    function<void(int, int)> clear = [&](int id, int fa)
    {
        cnt[c[id]]--;
        for (auto x : e[id])
        {
            if (x == fa)
                continue;
            clear(x, id);
        }
    };
    function<void(int, int)> dfs = [&](int id, int fa)
    {
        for (auto x : e[id])
        {
            if (x == fa || x == son[id])
                continue;
            dfs(x, id);
            clear(x, id);
            sum = mx = 0;
        }
        if (son[id])
            dfs(son[id], id);
        get_ans(id, fa, son[id]);
        ans[id] = sum;
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //	cin>>t;
    while (t--)
        solve();
}