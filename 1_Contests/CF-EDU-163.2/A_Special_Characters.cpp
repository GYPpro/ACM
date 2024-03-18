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
        if(n % 2){ cout << "NO\n";return;}
        string s;
        int f = 0;
        for(int i = 0;i < n/2;i ++)
        {
            s.push_back('A'+f);
            s.push_back('A'+f);
            f = !f;
        }
        if(n%2) 
            s.push_back('A'+f);
        cout << "YES\n";
        cout << s << "\n";
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