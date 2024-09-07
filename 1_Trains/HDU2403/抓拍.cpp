// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n;
        cin >> n;
        map<char,vector<pii>> mp;
        string tars = "NSWE";
        //  N {   }
        //
        //  
        //
        lop(i,1,n)
        {
            int x,y;
            char c;
            cin >> x >> y >> c;
            mp[c].pb({x,y});
        }

        map<char,pii> MVrange;
        {
            for(auto x:tars)
            {

            }
        }
        
        map<char,pii> STrange;
        
        auto check = [&](int _t) -> int {
            int res = 0;
            // N E W S
            
            // for(auto &x:range)
            // {
            //     int l = x.se.fi,r = x.se.se;
            //     if(_t < l) res += l - _t;
            //     if(_t > r) res += _t - r;
            // }
            return res*2;
        };
        int l = 0,r = INF;
        while(l < r)
        {
            int mid1 = l + (r-l)/3;
            int mid2 = r - (r-l)/3;
            if(check(mid1) < check(mid2)) r = mid2;
            else l = mid1;
            if(check(mid1) == check(mid2)) break;
        }
        cout << check(l) << endl;
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
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