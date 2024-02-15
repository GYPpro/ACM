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

class solution{
    private:

    public:
    void solve()
    {
        int n,m;
        cin >> n>> m;
        vector<vector<int>> mtx( m ,vector<int> (n));
        for(auto &x:mtx)
            for(auto &y:x)
                cin >> y;
        if(m <= 1){
            cout << "YES\n";
            return;
        }
        bool flag2 = 1;
        vector<int> at0;
        for(int i = 1;i < n;i ++) if(mtx[0][i] != mtx[1][0]) at0.pb(mtx[0][i]);
        vector<int> at1;
        for(int i = 1;i < n;i ++) if(mtx[1][i] != mtx[0][0]) at1.pb(mtx[1][i]);
        for(int i = 0;i < at0.size();i ++)
            if(at0[i] != at1[i])
            {
                flag2 = 0;
                break;
            }
        if(m <= 2) if(!flag2)
            {
                cout << "NO\n";
                return;
            } else {
                cout << "YES\n";
                return;
            }
        else if(!flag2)
            {
                cout << "NO\n";
                return;
            }
        int l1 = 0,r1 = 0,
            l2 = 0,r2 = 0;
        for(int i = 1;i < n;i ++)
        {
            if(mtx[1][i] == mtx[0][0])
            {
                if(i > 1) l1 = mtx[1][i-1];
                if(i < n - 1) r1 = mtx[1][i+1];
            }
        }
        for(int i = 1;i < n;i ++)
        {
            if(mtx[2][i] == mtx[0][0])
            {
                if(i > 1) l2 = mtx[2][i-1];
                if(i < n - 1) r2 = mtx[2][i+1];
            }
        }

        int ltr1 = 0,rtr1 = n,
            ltr2 = 0,rtr2 = n;
        for(int i = 1;i < n;i ++)
            if(mtx[0][i] == l1)ltr1 = i;
        for(int i = 1;i < n;i ++)
            if(mtx[0][i] == r1)rtr1 = i;
        for(int i = 1;i < n;i ++)
            if(mtx[0][i] == l2)ltr2 = i;
        for(int i = 1;i < n;i ++)
            if(mtx[0][i] == r2)rtr2 = i;
        
        int l = max(ltr1,ltr2);
        int r = min(rtr1,rtr2);

        // cout << l << " " << r << "\n";
        if(l != r-1)
        {
            cout << "NO\n";
            return;
        }
        vector<int> prmt;
        if(l == 0) prmt.pb(mtx[0][0]);
        for(int i = 1;i < n;i ++)
        {
            prmt.pb(mtx[0][i]);
            if(i == l) prmt.pb(mtx[0][0]);
        }

        bool flagn = 1;
        for(auto x:mtx)
        {
            int sbv = 1;
            for(int i = 1;i < n;i ++)
            {
                if(x[i] != prmt[i-sbv])
                {
                    if(sbv) sbv --;
                    else {
                        flagn = 0;
                        break;
                    }
                }
            }
            if(!flagn) break;
        }
        if(flagn) cout << "YES\n";
        else cout << "NO\n";
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