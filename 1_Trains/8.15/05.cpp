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
    getchar();
    for(;;)
    {
        char c = getchar();
        if(c != '\n')
            s += c;
        else
            break;
    }
    int x,y;
    cin >> x >> y;
    string ans = "[";
    int commacnt = 0;
    bool flag = false;
    for(int i = 0;i < s.length();i ++)
    {
        if(commacnt == y)
        {
            ans.pop_back();
            ans += "], [";
            commacnt = 0;
        } else {
            if(s[i] == ',')
            {
                commacnt ++;
                if(!flag) ans += "0";
                flag = false;
                ans += s[i];
            } else if(s[i] == '0')
            {
                if(flag) ans += "0";
            } else 
            {
                ans += s[i];
                if(s[i] != ' ') flag = true;
            }
        }
    }
    ans += "]";
    cout << ans << endl;
}

#define _WITH_T_

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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