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
    string s;
    cin >> s;
    switch(s[0])
    {
        case '1':
        {
            cout << "13" << endl;
            break;
        }
        case '2':
        {
            cout << "23" << endl;
            break;
        }
        case '3':
        {
            cout << "31" << endl;
            break;
        }
        case '4':
        {
            cout << "41" << endl;
            break;
        }
        case '5':
        {
            cout << "53" << endl;
            break;
        }
        case '6':
        {
            cout << "61" << endl;
            break;
        }
        case '7':
        {
            cout << "73" << endl;
            break;
        }
        case '8':
        {
            cout << "83" << endl;
            break;
        }
        case '9':
        {
            cout << "97" << endl;
            break;
        }
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