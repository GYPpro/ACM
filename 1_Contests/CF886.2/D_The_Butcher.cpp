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

bool compfi(pair<pii,int> a,pair<pii,int> b) {
    return a.fi.fi > b.fi.fi;
}
bool compse(pair<pii,int> a,pair<pii,int> b) {
    return a.fi.se > b.fi.se;
}
class solution
{
private:


public:
    void solve()
    {
        int n;
        cin >> n;
        vector<pair<pii,int>> arr(n);
        lop(i,0,n) cin >> arr[i].fi.fi >> arr[i].fi.se,arr[i].se = i;
        auto a1 = arr;
        auto a2 = arr;
        sort(all(a1),compfi);
        sort(all(a2),compse);
        // for(auto x:a1) cout << x.fi.fi << " " << x.fi.se << "\n";
        // for(auto x:a2) cout << x.fi.fi << " " << x.fi.se << "\n";
        vector<int> vst(n);
        vector<pii> ansls;
        //check se()
        int l,r;
        l = a2[0].fi.se;
        r = a1[a2[0].se].fi.fi;
        int f = 1;
        int p1 = 0,p2 = 1;
        bool acc = 1;
        while(p1 < n && p2 < n)
        {
            if(f)
            {
                r 
            } else {

            }
            f = !f;
        }
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