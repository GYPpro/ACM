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
#include <set>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

bool stBie(string s)
{
    for(int i = 0;i + 2 < s.size();i ++)
    {
        if(s[i] == 'b' && s[i+1] == 'i' && s[i+2] == 'e') return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    set<string> st;
    string s;
    for(int i = 0;i < n;i ++)
    {
        int t;
        cin >> t;
        bool pbed = 0;
        for(int j = 0;j < t;j ++)
        {

            cin >> s;
            if(!stBie(s)) continue;
            if(st.find(s) == st.end())
            {
                st.insert(s);
                pbed = 1;
                cout << s << endl;
            }
            s.clear();
        }
        if(!pbed) cout << "Time to play Genshin Impact, Teacher Rice!\n";
    }
}

// #define _WITH_T_

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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}