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
        int n,k;
        cin >> n >> k;
        vector<int> a1(n);
        vector<int> a2(n);
        FI cin >> a1[i];
        FI cin >> a2[i];
        int maxn = 0,maxidx = -2;
        FI 
            if(a1[i] <= k - i) 
                if(a2[i] > maxn)
                    (maxn = a2[i],maxidx = i);
        cout << maxidx + 1 << "\n";
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