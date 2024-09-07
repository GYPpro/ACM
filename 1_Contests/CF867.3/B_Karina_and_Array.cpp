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
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> pr(2),cr(2);
        FI {
            int t;
            cin >> t;
            if(t < 0) cr.pb(t);
            else pr.pb(t);
        }
        sort(pr);
        sort(cr);
        if(pr.size() >= 4 || cr.size() >= 4) cout << max(pr[pr.size()-1] * pr[pr.size()-2],cr[0] * cr[1]) << "\n";
        else cout << pr[pr.size()-1] * cr[0] << "\n";
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