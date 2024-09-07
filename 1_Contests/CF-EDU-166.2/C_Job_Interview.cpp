#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

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

class solution
{
private:
public:
    void solve()
    {
        int a, b;
        cin >> a >> b;
        int n = a + b;
        vector<int> ta(n + 1);
        vector<int> tb(n + 1);
        for (auto &x : ta)
            cin >> x;
        for (auto &x : tb)
            cin >> x;
        vector<int> cel(n + 1);

        // cel=1:a cel=0:b

        int cursum = 0;

        auto anti = [&](int _i) -> int
        {
            int ftt = 0;
            if (cel[_i])
            {
                ftt -= ta[_i];
                ftt += tb[_i];
                // cel[_i] = !cel[_i];
                return ftt;
            }
            else
            {
                ftt += ta[_i];
                ftt -= tb[_i];
                return ftt;
            }
        };

        int deadpoint = -1;
        int forcespoint = -1;

        auto ifForces = [&](int _i) -> bool
        {
            if (cel[_i])
            {
                if (ta[_i] < tb[_i])
                    return 1;
                else
                    return 0;
            }
            else
            {
                if (ta[_i] > tb[_i])
                    return 1;
                else
                    return 0;
            }
        };

        int capa = a, capb = b;

        for (int i = 0; i < n; i++)
        {
            // cout << cursum << " ";
            if (!capa)
            {
                if(deadpoint  == -1) deadpoint = i;
                cursum += tb[i];
                capb--;
                cel[i] = 0;
                
            if(i >= deadpoint) if(ifForces(i)) if(forcespoint  ==  -1) forcespoint = i;
                continue;
            }
            if (!capb)
            {
                if(deadpoint == -1) deadpoint = i;
                cursum += ta[i];
                capa--;
                cel[i] = 1;
                
            if(i >= deadpoint) if(ifForces(i)) if(forcespoint == -1) forcespoint = i;
                continue;
            }
            if (ta[i] > tb[i])
            {
                capa--;
                cursum += ta[i];
                cel[i] = 1;
            }
            else
            {
                capb--;
                cursum += tb[i];
                cel[i] = 0;
            }
        }
            // cout << cursum << " ";
        cursum += cel[n - 1] ? ta[n] : tb[n];
        cel[n] = cel[n-1];
            // cout << cursum << " ";
        // cout <<"\n" <<  cursum << "\n";
        // cout << deadpoint  << "  " << forcespoint << " -=-\n";
        vector<int> ans;
        if(forcespoint == -1) forcespoint = n;
        for(int i = n;i >= 0;i --)
        {
            if(i < forcespoint){
                if(cel[i] ^ cel[forcespoint])
                 ans.pb( cursum - (cel[i]?ta[i]:tb[i]) + anti(forcespoint) );
                else 
                ans.pb(cursum - (cel[i]?ta[i]:tb[i]));
                
            } else {
                ans.pb(cursum - (cel[i]?ta[i]:tb[i]));
            }
        }
    
        // for(auto  x:cel) cout << x  << "  ";
        // cout << "\n";

        for(int i = n ;i >= 0;i --)
        {
            cout << ans[i]  << " ";
        }
        cout << "\n";

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