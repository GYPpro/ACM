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
        vector<int> a(n);
        vector<int> b(n+1);
        FI cin >> a[i];
        for(auto &x:b) cin >> x;
        int tar = b[n];
        int cost = 0;
        int minc = INT_MAX;
        for(int i = 0;i < n;i ++)
        {
            // cost += abs(a[i] - b[i]);
            int l = a[i],r = b[i];
            if(l > r) swap(l,r);
            cost += r - l;
            if(tar > r) minc = min(minc, tar - r);
            else if(tar < l) minc = min(minc, l - tar);
            else minc = 0;
        }
        // cout << cost << "\n";.
        // cout << minc << "\n";
        cout << cost + minc + 1 << endl;
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