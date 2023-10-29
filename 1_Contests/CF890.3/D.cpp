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
#define maxn 200100
#define ull unsigned long long

using namespace std;


    ll int A[maxn] = {0};
    ll int B[maxn] = {0};
    ll int HSL[maxn] = {0};
void solve()
{
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(HSL, 0, sizeof(HSL));
    ll int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
    {
        HSL[i] = A[i] - B[i];
    }

    int maxvalue = -100000000;
    for (int i = 0; i < n; i++)
        if (HSL[i] >= maxvalue)
            maxvalue = HSL[i];

    vector<int> ans;

    for(int i = 0;i < n;i ++)
    {
        if(HSL[i] == maxvalue)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}