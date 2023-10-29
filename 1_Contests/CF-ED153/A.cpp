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

bool equal(string a,string b)
{
    if(a.size() != b.size()) return false;
    for(int i = 0;i < a.size();i ++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    if(s.length() == 2)
    {
        if(equal(s,"((")) cout << "YES\n()()\n";
        if(equal(s,"))")) cout << "YES\n()()\n";
        if(equal(s,"()")) cout << "NO\n";
        if(equal(s,")(")) cout << "YES\n(())\n";
        return;
    }
    cout << "YES\n";
    int maxslen = 0;
    int tmp = 1;
    for(int i = 0;i < s.length()-1;i ++)
    {
        if(s[i+1] == s[i]) tmp ++;
        else {
            if(tmp > maxslen) maxslen = tmp;
            tmp = 1;
        }
    }
    if(tmp > maxslen) maxslen = tmp;

    if(maxslen == 1){
        for(int i = 0;i < s.size();i ++)
        {
            cout << "(";
        }
        for(int i = 0;i < s.size();i ++)
            cout << ")";
    } else {
        for(int i = 0;i < s.size();i ++)
            cout << "()";
    }
    cout << endl;
    return ;
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
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