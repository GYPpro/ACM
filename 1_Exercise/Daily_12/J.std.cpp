#include <bits/stdc++.h>
using namespace std;
#define int long long
void write(__int128_t x)
{
    if(x<0)
        cout<<('-'),x=-x;
    if(x>9)
        write(x/10);
    cout<<char(x%10+'0');
    return;
}

void solve()
{
    int aa,bb;
    cin>>aa>>bb;
    __int128_t a = aa,b = bb;
    __int128_t x=10*a+b;
    if(x!=100) 
    {
        __int128_t fenzi = a-11;
        __int128_t fenmu = x-100;
        __int128_t gcd = __gcd(fenzi,fenmu);
        fenzi/=gcd;
        fenmu/=gcd;
        if(fenmu<0) fenzi*=-1,fenmu*=-1;
        write(fenzi);
        cout<<" ";
        write(fenmu);
        cout<<"\n";
    }
    else
    {
        if(a==11 && b==-10) cout<<1<<" "<<9<<"\n";
        else cout<<-1<<"\n";
    }
}
signed main()
{
#ifdef FC
    freopen("J.A.in","r",stdin);
    freopen("J.A.std","w",stdout);
#endif

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // if (argc > 1)
    // {
    //     string i;
    //     i = argv[1];
    //     freopen(("data/TeeDecimal" + i + ".in").c_str(), "r", stdin);
    //     freopen(("data/TeeDecimal" + i + ".out").c_str(), "w", stdout);
    // }
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
/*

12
11 -10
10 0
0 100
1000000000000000000 100
1 1000000000000000000
-1000000000000000000 1000000000000000000
-100000000000000000 1000000000000000100
1 2
10 10
0 0
1 1
1 100

*/