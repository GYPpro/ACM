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
        string s;
        cin >> s;
        int maxans = 0;
        for(int dim = 1;dim < s.size();dim ++)
        {
            int tmp = 0;
            int pvmx = 0;
            for(int i = dim;i < s.size();i ++)
            {
                if(s[i-dim]== s[i] || s[i] == '?' || s[i-dim] == '?') tmp ++;
                else {pvmx = max(tmp,pvmx);tmp = 0;}
            }
            pvmx = max(tmp,pvmx);
            if(pvmx < dim) pvmx = 0;
            else pvmx = dim;
            maxans = max(maxans,pvmx*2);
        }
        cout << maxans << "\n";
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