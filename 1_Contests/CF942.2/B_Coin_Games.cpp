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

    void YN(bool y)
    {
        if (y) cout << "YES\n";
        else cout << "NO\n";
    }

    int cel(string &c)
    {
        if(c.size() < 3) 
        {
            for(int i = 0;i < c.size();i ++) if(c[i] == 'U') return i;
            return -1;
        }
        for(int i = 0;i < c.size();i ++)
        {
            if(c[(i+2)%c.size()] == 'U' && c[(i+1)%c.size()] == 'U' && c[i] == 'U') return (i+1)%c.size();
        }
        for(int i = 2;i < c.size()+2;i ++)
        {
            if(c[i%2] == 'U' && c[(i+2)%c.size()] != 'U' && c[(i-2)%c.size()] != 'U') return i;
        }
        for(int i = 0;i < c.size();i ++) if(c[i] == 'U') return i;
        return -1;
    }

public:
    void solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // if(s.size() < 3){ YN(!s.size()%2);return;}
        // bool t = 0;
        // while(n--)
        // {
        //     cout << cel(s);
        //     s = s.erase(cel(s));
        //     t = !t;
        // }
        // YN(t);
        map<char,int> cnt;
        for(auto x:s) cnt[x] ++;
        YN(cnt['U']%2);
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