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

        int n,k;
        string s;
        bool check(int l) {
            if (l == 0) return 1;
            int t = 0;
            for(int i = 0;i < n;) {
                if(s[i] == '1') {t ++;i += l;}
                else i += 1;
            }
            // cout << "check " << l << " :" << t << "\n";
            return t <= k;
        }
public:
    void solve()
    {
        cin >> n >> k;
        cin >> s;
        int l = 0, r = 1e9 + 1;   // 因为是左闭右开的，所以 10^9 要加 1
        while (l + 1 < r) {       // 如果两点不相邻
            int mid = (l + r) / 2;  // 取中间值
            if (check(mid))         // 如果可行
            r = mid;              // 升高锯片高度
            else
            l = mid;  // 否则降低锯片高度
        }
        cout << r << "\n";
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