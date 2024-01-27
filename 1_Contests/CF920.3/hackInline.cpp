#include <iostream>
using namespace std;
#gcc optimize(2)
// #include <
#define int long long

 int qpow(int a,int b,int p)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = ans*a%p;
        a = a*a %p;
        b >>= 1;
    }
    // cout << ans << "\n";
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t,p;
    t = 1;
    for(int i = 0;i < t;i ++)
    {
        int a,b;
        cin >> a >> b >> p;
        cout << qpow(a,b,p);
    }
}