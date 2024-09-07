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
#define fi first
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
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> arr(n);
        FI {
            cin >> arr[i].fi;
            arr[i].se = i;
        }
        sort(arr);
        int curl = arr[0].fi;
        int ans = 1;
        if(n == 1){ arr[0].fi += k;k = 0;curl = arr[0].fi;}
        for(int i = 1;i < n;i ++)
        {
            if(k < (arr[i].fi - curl) * i ){
                int tmpt = k/i;
                curl += tmpt;
                k -= i*tmpt;
                break;
            }
            k -= (arr[i].fi - curl) * i;
            curl = arr[i].fi;
        }
        // if(k == n-1) ans += n-1;
        // for(auto &x:arr)
        // {
        //     if(x.fi > curl) break;
        //     else x.fi = curl;
        // }
        // vector<int> fst(n);
        // for(auto x:arr) fst[x.se] = x.fi;
        // int minn = fst[0];
        // FI{
        //     minn = min(fst[i],minn);
        //     ans += minn;
        // }
        // ans -= n;
        ans += (curl-1LL )* n;
        int tmpad = 0;
        for(auto x:arr) if(x.fi > curl) tmpad ++;
        tmpad += k;
        tmpad = min(tmpad,n);
        cout << ans + tmpad << "\n";
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