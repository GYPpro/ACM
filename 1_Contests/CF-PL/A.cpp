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
    int n,a,p;
    cin >> n >> a >> p;
    string arr;
    cin >> arr;
    int indiv = 0,
        inadd = 0;
    int pre = a;
    int flag = 3;//0:NO 2:Maybe 1:Yes
    if(pre == n) flag = 1;
    for(int i = 0;i < p;i ++)
    {
        if(arr[i] == '+') 
        {
            inadd ++;
            pre ++;
        }
        else
        {
            indiv ++;
            pre --;
        }
        if(pre == n) flag = 1;
    }
    if(flag == 1) cout << "YES" << endl;
    else if((inadd + a) >= n) cout << "MAYBE" << endl;
    else cout << "NO" << endl;
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