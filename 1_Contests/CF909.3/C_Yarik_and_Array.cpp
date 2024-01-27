
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    vector<int> dp(n);
    dp[0]=a[0];
    int m = a[0];
    for(int i = 1;i < n;i ++)
    {
        if((a[i] + a[i-1])%2){ dp[i] = max(dp[i-1]+a[i],a[i]);}
        else{ dp[i] = a[i];}
        m = max(m,dp[i]);
    }
    cout << m << "\n";
}


int main()
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