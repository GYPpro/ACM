#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

#define int long long
using namespace std;

    int dif(int x)
    {
        if (x > 1)
            return x;
        else
            return 0;
    }

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    vector<int> vi;
    vector<int> vj, vo;
    for (int i = 0; i < x; i++)
    {
        int p;
        cin >> p;
        vi.push_back(p);
    }
    sort(vi.begin(), vi.end());

    for (int i = 1; i < vi.size(); i++)
    {
        int lgn = vi[i] - vi[i - 1] - 1;
        if(lgn % 2) vj.push_back(lgn);
        else vo.push_back(lgn);
    }
    int num = vi[0] + n  - vi[x - 1]- 1;
    if(num % 2) vj.push_back(num);
    else vo.push_back(num);
    for(auto xx:vj) ans += dif(xx);
    for(auto xx:vo) ans += dif(xx);

    sort(vj.begin(),vj.end());
    sort(vo.begin(),vo.end());

    for (int i = 0; i < vj.size(); i++)
    {
        if ((vj[i] -1) / 2 < y)
        {
            y -= (vj[i] -1) / 2;
            ans -= dif(vj[i]);
        }
        else
        {
            ans -= dif(vj[i]) - dif(vj[i] - 2 * y);
            y = 0;
            break;
        }
    }
    for (int i = 0; i < vo.size(); i++)
    {
        if (vo[i] / 2 <= y)
        {
            y -= vo[i] / 2;
            ans -= dif(vo[i]);
        }
        else
        {
            ans -= dif(vo[i]) - dif(vo[i] - 2 * y);
            y = 0;
            break;
        }
    }
    cout << n - 2 - ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
    // system("pause");
}