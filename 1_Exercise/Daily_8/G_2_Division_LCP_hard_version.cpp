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

    auto check = [&](int k) -> int
    {
        // int t = kmp.find_occr()
        string subs;
        // while(subs.size() < k) subs.
        lop(i, 0, k) subs.pb(s[i]);
        return underGape(k, kmp.find_occr(subs)) ;
    };
    // vector<pii> cnts;
    map<int,int> cnts;
    map<int,int> rcnt;
    for(int i = 1;i <= sqrt(n);i ++)
    {
        // int cur = n/i;
        int cur = i;
        // if(cnts.find(cur) != cnts.end()) continue;
        int t = check(cur);
        cnts[cur] = t;
        rcnt[t] = max(rcnt[t],cur);
    }

    // int l = 0, r = n;
    // while (l < r)
    // {
    //     int mid = l + r + 1 >> 1;
    //     if (check(mid))
    //         l = mid;
    //     else
    //         r = mid - 1;
    // }
    // cout << l << "\n"; 
    // for(auto x:rcnt) cout << x.fi << " " << x.se << "\n";
    int outs = 0;
    vector<int> anss;
    // vector<pii> tbp;

    for(auto x:rcnt)
    {
        while(outs < x.fi)
        {
            // cout << x.se << " ";
            anss.pb(x.se);
            outs ++;
        }
    }
    while(++outs <= n) 
        anss.pb(0);
        
    int ewes;
        // cout << 0 << " ";
    auto check2 = [&](int k) -> int
    {
        // int t = kmp.find_occr()
        string subs;
        // while(subs.size() < k) subs.
        lop(i, 0, k) subs.pb(s[i]);
        return underGape(k, kmp.find_occr(subs)) >= ewes;
    };

    for(int i = 1;i < sqrt(n);i ++)
    {
        
        ewes = i;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            
            if (check2(mid))
                l = mid;
            else
                r = mid - 1;
        }
        // cout << l << "\n";
        anss[i-1]=l;
    }

    // cout << "\n";
    lop(i,ll,rr+1) cout << anss[i-1] << " ";cout << "\n";
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
