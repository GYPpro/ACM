#define _USE_IOSTREAM_
// #define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

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

using namespace std;

class people{
    public:
    string n;
    int a,b,c;
    people()
    { }
    people(int _a,int _b,int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    int sum()
    {
        return a+b+c;
    }
};

bool cmp1(people a,people b)
{
    return a.a > b.a;
}
bool cmp2(people a,people b)
{
    return a.c > b.c;
}

void solve()
{
    int n;
    cin >> n;
    vector<people> arr(n);
    int sum = 0;
    for(int i = 0;i < n;i ++)
    {
        cin >> arr[i].n >> arr[i].a >> arr[i].b >> arr[i].c;
        sum += arr[i].sum();
    }
    sort(arr.begin(),arr.end(),cmp1);
    people a1 = arr[0];
    people a2 = arr[1];
    sort(arr.begin(),arr.end(),cmp2);
    people c1 = arr[0];
    people c2 = arr[1];
    if(a1.n == c1.n)
    {
        int ans1 = sum-a1.a-c2.c;
        int ans2 = sum-a2.a-c1.c;
        if(ans1 > ans2) cout << a2.n << " " << c1.n << "\n" << ans2 << "\n";
        else cout << a1.n << " " << c2.n << "\n" << ans1 << "\n";
    } else cout << a1.n << " " << c1.n << "\n" << sum-a1.a-c1.c << "\n";
}

// #define _WITH_T_

signed main()
{
    #ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #endif
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}