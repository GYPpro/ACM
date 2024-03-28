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

    string rev(string &s)
    {
        string as;
        for(int i = s.size()-1;i >= 0;i --)
            as.pb(s[i]);
        return as;
    }

    public:
    void solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool revn = false;
        for(int i = 0;i < s.size()/2;i ++)
        {
            if(s[i] > s[s.size()-1-i]){ revn = 1;break;}
            else if(s[i] < s[s.size()-1-i]) break;
        }
        if (revn)
        {
            if(!(n%2)) cout << rev(s) << s  << "\n";
            else cout << rev(s) << "\n";
        } else if(!(n%2)) cout << s << "\n";
        else cout << s << rev(s) << "\n";
        
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