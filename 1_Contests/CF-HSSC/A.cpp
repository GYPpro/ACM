#define _USE_IOSTREAM_
// #define _USE_STDIO_

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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    int x,y,n;
    cin >> x >> y >> n;
    vector<int> ans;
    for(int div = 1;div <= n;div ++)
    {
        ans.push_back(y);
        y -= div;
    }
    if(ans[ans.size()-1] < x) cout << "-1\n";
    else {
        ans[ans.size()-1] = x;
        for(int i = ans.size()-1;i >= 0;i --) cout << ans[i] << " ";
        cout << endl;
    }
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
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