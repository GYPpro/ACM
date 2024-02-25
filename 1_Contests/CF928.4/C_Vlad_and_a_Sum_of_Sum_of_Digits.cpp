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

vector<int> ans(200010,1);

int szn(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

void init()
{
    for(int i = 2;i < ans.size();i ++)
        ans[i] = ans[i-1] + szn(i);
}

class solution{
    private:

    public:
    void solve()
    {
        int i;
        cin >> i;
        cout << ans[i] << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    cin >> T;

    init();

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}