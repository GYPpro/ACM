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

class solution{
    private:

    public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n,0);
        int gt = 0;
        int ht = 0;
        for(int i = 1;i <= (n+1)/2;i ++)
        {
            arr[gt] = i;
            gt += k;
            if(gt >= n) gt =( ht += 2);
        }
        gt = 1;
        ht = 1;
        for(int i = 0;i < n/2;i ++)
        {
            arr[gt] = n-i;
            gt += k;
            if(gt >= n) gt =( ht += 2);
        }
        for(auto x:arr) cout << x << " ";
        cout << "\n";
    }
};
//1 8 4 10 2 7 5 9 3 6
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