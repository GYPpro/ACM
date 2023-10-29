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
#define maxn 110
#define ull unsigned long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int A[maxn];
    vector<int> ans;
    for(int i = 0;i < n;i ++)
        cin >> A[i];
    
    sort(A,A+n);
    int minia = A[0];
    int miniidx = 0;
    for(;miniidx < n;miniidx ++)
    {
        if(A[miniidx] != minia)
            break;
        ans.push_back(A[miniidx]);
    }
    if(ans.size() == n) cout << -1 << endl;
    else {
        cout << ans.size() << " " << n-miniidx << endl;
        for(int i = 0;i < ans.size();i ++)
            cout << ans[i] << " ";
        cout << endl;
        for(int i = miniidx;i < n;i ++)
            cout << A[i] << " ";
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