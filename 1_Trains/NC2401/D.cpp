#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

// #define map unordered_map
// #define set unordered_set
// #define pq priority_queue
#include <map>
#include <set>

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
const int INF = 1145141919810LL;
const int mod = 2097152LL;
void sort(auto &x) { sort(x.begin(), x.end()); }
using namespace std;

// 使用树状数组维护：区间中每个数出现的个数，21个树状数组，第i个：数的前i位
// 查询时，查询区间数的个数和即可

template <typename T, bool P = true>
class BIT
{
private:
    std::vector<T> c;

public:
    void init(int n)
    {
        std::vector<T>(n + 1, 0).swap(c);
    }
    void update(int p, const T &v)
    {
        if constexpr (P)
        {
            for (size_t i = p; i < c.size(); i += i & -i)
            {
                c[i] += v;
            }
        }
        else
        {
            for (size_t i = p; i > 0; i -= i & -i)
            {
                c[i] += v;
            }
        }
    }
    T subquery(int p) const
    {
        T res(0);
        if constexpr (P)
        {
            for (size_t i = p; i > 0; i -= i & -i)
            {
                res += c[i];
            }
        }
        else
        {
            for (size_t i = p; i < c.size(); i += i & -i)
            {
                res += c[i];
            }
        }
        return res;
    }

    T get(int l, int r)
    {
        return subquery(r + 1) - subquery(l);
    }
};

void solve()
{
    int q;
    cin >> q;

    vector<BIT<int>> bits(21);
    for (int i = 0; i < 21; i++)
        bits[i].init(1 << (i + 1));

    // int qn = 0;
    vector<int> at(1);

    while (q--)
    {
        int t, v;
        cin >> t >> v;
        v %= mod;

        auto insert = [&](int a) -> void
        {
            // qn += a;
            at.push_back(at[at.size() - 1] + a);
            a = at[at.size() - 2];
            // cout << a << " ";
            for (int i = 0; i < 21; i++)
                bits[i].update((-a & ((1 << (i + 1)) - 1)) + 1, 1);
                            //  -x & ((1 << (b + 1)) - 1)
        };

        auto remove = [&]() -> void
        {
            int rmd = at[at.size() - 2];
            // cout << rmd << " ";
            at.pop_back();
            for (int i = 0; i < 21; i++)
                bits[i].update((-rmd & ((1 << (i + 1)) - 1)) + 1, -1);
                            //  -  x & ((1 << (b + 1)) - 1)cout << "ud" << ((-rmd & ((1 << (i + 1)) - 1)) + 1) << " v " << -1 << "\n"
        };

        auto getBinAns = [&](int f) -> vector<int>
        {
            // cout << "getf " << f << "\n";
            vector<int> rt;
            for (int i = 0; i < 21; i++)
            {
                int t = (f >> i) % 2;
                int r = f & ((1 << (i + 1)) - 1);
                if (r <= (1 << i))
                    rt.pb(bits[i].get((1 << i) - r, (1 << (i + 1)) - 1 - r) & 1); //,cout << bits[i].get((1 << i) - r, (1 << (i + 1)) - 1 - r) << "a\n"
                else
                    rt.pb((at.size() -1 - bits[i].get((1 << (i + 1)) - r, (3 << i) - 1 - r)) & 1); //,cout << (at.size() -1 - bits[i].get((1 << (i + 1)) - r, (3 << i) - 1 - r)) << "b\n"
            }
            return rt;
        };

        while (t--)
            remove();
        insert(v);
        auto rt = getBinAns(at[at.size() - 1]);
        int ans = 0;
        for (int i = 0; i < rt.size(); i++)
            ans += (1 << i) * rt[i];
        // for(auto x:rt) cout << x << " ";
        cout << ans << "\n";
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}