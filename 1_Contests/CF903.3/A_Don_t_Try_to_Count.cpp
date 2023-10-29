#define _USE_IOSTREAM_
#define _PRIV_TEST_

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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;


void solve()
{
    int m, n;
    cin >> m >> n;
    string s1, s2;
    cin >> s1 >> s2;
    do
    {
        s1 = s1 + s1;
    } while (s1.size() <= s2.size() * 2);
    bool cp = 0;
    int tw = 0;
    
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[0])
        {
            tw = 0;
            for (int j = 0; j < s2.size(); j++)
            {
                cp = 1;
                tw = j;
                if ((i+j >= s1.size()) || (s1[i + j] != s2[j]))
                {
                    cp = 0;
                    break;
                }
            }
            tw += i;
            if (cp)
                break;
        }
        cp = 0;
    }
    if (!cp)
    {
        cout << -1 << endl;
        return;
    }
    int rp = 0;
    // do{
    //     rp ++;
    //     tw /= 2;
    // }while(tw > m);
    while (tw >= m)
    {
        rp++;
        tw /= 2;
    }
    cout << rp << endl;
}

#define _WITH_T_

int main()
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}