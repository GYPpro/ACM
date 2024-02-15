#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution
{
private:
public:
    class VTS
    {
    public:
        string s;
        int l, r;
        int al, ar;
        bool alw = 1;
        vector<int> op;
        VTS(string _s)
        {
            s = _s;
            l = 0;
            r = s.size() - 1;
            al = l;
            ar = r;
        }
        void addat(int n)
        {
            string _s;
            for (int i = 0; i < n; i++)
                _s.push_back(s[i]);
            _s.push_back('0');
            _s.push_back('1');
            for (int i = n; i <= r; i++)
                _s.push_back(s[i]);
            r += 2;
            s = _s;
            // al += 2;
            ar += 2;
        }
        bool rw()
        {
            if (al > ar)
                return 0;
            if (op.size() > 300)
            {
                op.clear();
                alw = 0;
                return 0;
            }
            if (s[al] == s[ar])
            {
                if (s[al] == '0')
                {
                    op.push_back(ar + 1);
                    addat(ar + 1);
                }
                else
                {
                    op.push_back(al);
                    addat(al);
                }
            }
            al++;
            ar--;
            return 1;
        }
        void printOp()
        {
            if ((!alw) || (!ifPrm()))
            {
                cout << "-1\n";
                return;
            }
            cout << op.size() << "\n";
            for (int i = 0; i < op.size(); i++)
                cout << op[i] << " ";
            cout << "\n";
        }
        bool ifPrm()
        {
            for (int i = 0; i < s.size() / 2 + 1; i++)
                if (s[i] == s[s.size() - i - 1])
                    return 0;
            return 1;
        }
    };

    void solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> cnt;

        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        if (cnt['0'] != cnt['1'])
        {
            cout << "-1\n";
            return;
        }
        VTS vts = VTS(s);
        if (vts.ifPrm())
        {
            cout << "0\n\n";
            return;
        }
        while (vts.rw())
        {
        };
        vts.printOp();
        return;
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