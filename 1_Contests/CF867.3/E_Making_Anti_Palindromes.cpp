#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second

void sort(auto &x)
{
    sort(x.begin(), x.end());
};

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.se > b.se;
}

class solution
{
private:
public:
    void solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2)
        {
            cout << "-1" << "\n";
            return;
        }

        map<pair<int, int>, int> free;
        map<int, int> refcnt;
        for (int i = 0; i < n / 2; i++)
            if (s[i] == s[n - i - 1])
                refcnt[s[i]]++;
            else
                free[{s[n - i - 1], s[i]}]++;
        pair<int, int> cur = {0, 0};
        int ttans = 0;
        vector<pair<int,int>> getcnt;
        for(auto x:refcnt) getcnt.pb(x);
        sort(getcnt.begin(),getcnt.end(),comp);
        for (auto x : getcnt)
        {
            if (cur.se)
            {
                if (cur.se > x.se)
                {
                    cur.se -= x.se;
                    ttans += x.se;
                    free[{cur.fi, x.fi}] += x.se;
                    free[{x.fi, cur.fi}] += x.se;
                }
                else
                {
                    free[{cur.fi, x.fi}] += cur.se;
                    free[{x.fi, cur.fi}] += cur.se;
                    ttans += cur.se;
                    cur = {x.fi, x.se - cur.se};
                }
            }
            else
                cur = x;
        }
        if (cur.se)
        {
            int sum = 0;
            for (int i = 'a'; i <= 'z'; i++)
                for (int j = 'a'; j <= 'z'; j++)
                    if (i != cur.fi && j != cur.fi)
                        sum += free[{i, j}];
            if (sum >= cur.se)
            {
                int allsum = 0;
                for(auto x:getcnt) allsum += x.se;
                if(allsum - getcnt[0].second * 2 < 0) cout << getcnt[0].second << "\n";
                else cout << allsum/2 + allsum%2 << "\n";
            }
            else
                cout << "-1\n";
        }
        else
            cout << ttans << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}