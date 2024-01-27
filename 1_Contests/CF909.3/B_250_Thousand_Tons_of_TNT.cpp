#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>

#define int long long
#define mod1 998244353

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int pt = 0;
    int mmax = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(n%i) continue;
        else {
            vector<int> c;
            int t = a[0];
            for(int j = 1;j < n;j ++)
            {
                if((j % i) == 0){
                    c.push_back(t);
                    t = a[j];
                } else t += a[j];
            }
            c.push_back(t);
            sort(c.begin(),c.end());
            mmax = max(mmax,abs(c[0]-c[c.size()-1]));
        }
    }
    cout << mmax << "\n";
    // cout << arr[n-1] - arr[0] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    cin >> T;

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}