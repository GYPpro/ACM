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
        string arr;
        cin >> arr;
        // FI cin >> arr[i];
        vector<int> divs(1);
        FI if(n%(i+1) == 0) divs.pb(i+1);
        auto check = [&](int idx) -> bool{
            if( idx == 0) return 0;
            int len = idx;
            string s;
            for(int id = 0;id < len;id ++)
            {
                s.pb(arr[id]);
            }
            int neq = 0;
            FI{
                // if(neq > 1) return false;
                if(arr[i] != s[i%len]) neq ++;
            }
            if(neq > 1) 
            {
                s.clear();
                for(int id = n-len;id <=n-1;id ++)
                {
                    s.pb(arr[id]);
                }
                // cout << divs[idx] << " " << s << "\n";
                neq = 0;
                FI{
                // if(neq > 1) return false;
                if(arr[i] != s[i%len]) neq ++;
                }
                // cout << neq << "\n";
                if(neq > 1) return false;
                else return true;
            }
            else return true;
        } ;
        // int l = 0;
        // int r = divs.size();
        // while(l+1<r)
        // {
        //     int mid = (l + r) / 2; // 取中间值
        //     if (check(mid))        // 如果可行
        //         r = mid;           // 升高锯片高度
        //     else
        //         l = mid; // 否则降低锯片高度
        // }
        // cout << divs[r] << "\n"
        ;
        for(auto x:divs)
            if(check(x)){cout << x << "\n";break;}
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