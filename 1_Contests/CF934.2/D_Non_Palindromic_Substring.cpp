#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution
{
private:
public:
    void solve()
    {
        int n, q;
        cin >> n >> q;
        string s;
        // for (auto &x : s)
        //     cin >> x;
        cin >> s;
        vector<int> ceq(n);
        vector<int> abab(n);
        char pv = s[0];
        for (int i = 1; i < n; i++)
        {
            if (pv != s[i])
                ceq[i] = ceq[i - 1] + 1;
            else ceq[i] = ceq[i - 1];
            pv = s[i];
        }
        pv = s[0];
        abab[0] = 1;
        abab[n-1] = 1;
        for (int i = 2; i < n; i++)
        {
            if (pv != s[i])
                abab[i - 1] = 1;
            pv = s[i - 1];
        }
        int flag = 2;
        for(int i = 0;i < n;i ++)
        {
            if(abab[i] == 1) flag ++;
            else abab[i] = flag;
        }
        // stack<int> prdtmp;
        // prdtmp.push(arr[0]);
        // int flag = 0;
        // int thl = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     if (prdtmp.top() == arr[i])
        //     {
        //         thl++;
        //         prd[i] = flag + 1;
        //         prd[i - 2 * thl + 1] = flag + 1;
        //         prdtmp.pop();
        //     }
        //     else
        //     {
        //         flag = !flag;
        //         thl = 0;
        //     }
        // }

        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            {
                k++;
            }
            d1[i] = --k;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
            {
                k++;
            }
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }
        
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            l --;
            r --;
            int len = r-l+1;
            int tmpans = len*(len+1LL)/2LL -1LL;

            int amt = len/2LL;

            if(abab[l+1] == abab[r-1] && abab[r-1] != 1) tmpans = amt * 2ll + amt*(amt-1);

            else if(len % 2) 
                if( (d1[ (l+r) /2LL] *2 +1) >= len) tmpans -= len;
                else ;
            else 
                if( (d2[ (l+r) /2LL +1] *2) >= len) tmpans -= len;
                else ;


            if(ceq[l] == ceq[r]) tmpans = 0;
            cout << tmpans << "\n";
        }
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