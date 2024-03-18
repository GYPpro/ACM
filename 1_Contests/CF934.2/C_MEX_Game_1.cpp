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
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        map<int,int> cnt;
        for(auto x:arr) cnt[x] ++;
        int MEXc = 0;
        bool f = 1;
        for(auto x:cnt)
        {
            if(x.first != MEXc) break;
            else {
                if(x.second == 1) if(f) f = 0;
                    else break;
            }
            MEXc ++;
        }
        cout << MEXc << "\n";
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