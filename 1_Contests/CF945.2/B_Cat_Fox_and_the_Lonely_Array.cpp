#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;


        auto check = [&](int k) -> bool
        {
            vector<int> orsum(22);
            if(k == 9)
                orsum[0] = 0;
            for(int i = 0;i < k;i ++)
            {
                // orsum |= arr[i];
                int tmp = arr[i];
                while(tmp)
                {
                    orsum[__builtin_ctz(tmp)] ++;
                    tmp -= tmp & -tmp;
                }
            }
            // cout << "k:" << k << " orsum:";
            // for(auto x:orsum) cout << x << " ";
            // cout << "\n";
            map<int,int> cnt;
            int rks = 0;
            for(int j = 1;j <= n-k;j ++)
            {
                // cout << "k:" << k << " j:" << j << " orsum:" << orsum << "\n";
                // cnt[orsum] ++;
                // orsum ^= arr[j-1];
                // orsum |= arr[j+k-1];
                
                rks = 0;
                for(int i = 0;i < 21;i ++)
                {
                    if(orsum[i] >= 1) rks += (1 << i);
                }
                cnt[rks] ++;
                // cout << " --";
                // for(auto x:orsum) cout << x << " ";
                // cout << "\n-" << rks << " \n";
                // cout << arr[j-1] << " " << arr[j+k-1] << "\n";
                int tmp = arr[j-1];
                while(tmp)
                {
                    orsum[__builtin_ctz(tmp)] --;
                    tmp -= tmp & -tmp;
                }
                tmp = arr[j+k-1];
                while(tmp)
                {
                    orsum[__builtin_ctz(tmp)] ++;
                    tmp -= tmp & -tmp;
                }
            }
            // cout << "\n";
            // cnt[orsum] ++;
            rks = 0;
            for(int i = 0;i < 21;i ++)
            {
                if(orsum[i] >= 1) rks += (1 << i);
            }
            cnt[rks] ++;
            if(cnt.size() > 1) return false;
            return true;
        };

        int l = 1,r = n;

        while(l < r)
        {
            int mid = (l+r)/2;
            // cout << "mid:" << mid << "check" << check(mid) << "\n";
            if(check(mid)) r = mid;
            else l = mid+1;
        }

        cout << l << "\n";
    }
};

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

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