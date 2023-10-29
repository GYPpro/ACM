#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 55

#define ull unsigned long long
using namespace std;


void solve()
{
    ll int SUM = 0;
    ll int sum1 = 0;
    ll int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        ll int tmp;
        cin >> tmp;
        SUM += tmp;
        if(tmp == 1) sum1 ++; 
    }
    if(n == 1) cout << "NO" << endl;
    else if(SUM < (n/2)+(n-n/2)*2) cout << "NO" << endl;
    else if(SUM - ((n/2)+(n-n/2)*2) < (sum1-(n/2 + n%2))) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 0;
    cin >> T;
    for(int i = 0;i < T;i ++)
        solve();
   // system("pause");
    return 0;
}