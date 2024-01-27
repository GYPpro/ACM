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
        int n;
        cin >> n;
        if(n == 1) cout << "1\n";
        else if(n == 3) cout << "169\n196\n961\n";
        else {
            string ans;
            int gap = 0;
            string seed1 = "169";
            string seed2 = "961";
            string ad = "196";
            for(int i = 3;i < n;i ++) ad.pb('0');
            ans += ad +"\n";
            for(int i = 0;i <= (n-3)/2;gap++,i++)
            {
                ad.clear();
                for(int j = 0;j < seed1.size()-1;j ++)
                {
                    ad.pb(seed1[j]);
                    for(int k = 0;k < gap;k ++)
                        ad.pb('0');
                }
                ad.pb(seed1[2]);
                for(int j = ad.size();j < n;j ++)
                    ad.pb('0');
                ans += ad + "\n";
                ad.clear();
                for(int j = 0;j < seed2.size()-1;j ++)
                {
                    ad.pb(seed2[j]);
                    for(int k = 0;k < gap;k ++)
                        ad.pb('0');
                }
                ad.pb(seed2[2]);
                for(int j = ad.size();j < n;j ++)
                    ad.pb('0');
                ans += ad + "\n";
            }
            cout << ans << "\n";
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