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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k %2 == 1)
    {
        string s0,s1;
        for(int i = 0;i < n;i ++) if(i%2 == 0) s0.push_back(s[i]); else s1.push_back(s[i]);
        sort(s1.begin(),s1.end());
        sort(s0.begin(),s0.end());
        int is = 0,ij = 0;
        for(int i = 0;i < n;i ++)
        {
            if(i%2 == 0)
            {
                cout << s0[is];
                is ++;
            } else {
                cout << s1[ij];
                ij ++;
            }
        }
    } else {
        sort(s.begin(),s.end());
        cout << s;
    }
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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}