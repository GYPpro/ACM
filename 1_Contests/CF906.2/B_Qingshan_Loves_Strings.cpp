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
#include <map>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

pair<bool,bool> ifcmp(string &s)
{
    char ch = s[0];
    for(int i = 1;i < s.size();i ++)
    {
        if(s[i] == ch) return pair<bool,bool>(0,s[i]-'0');
        ch = s[i];
    }
    return pair<bool,bool>(1,0);
}

void solve()
{
    int m,n;
    cin >> m >> n;
    string s,t;
    cin >> s >> t;
    char ch = s[0];
    bool cp = 1;
    for(int i = 1;i < s.size();i ++)
    {
        if(s[i] == ch){
            cp = 0;
            break;
        }
        ch = s[i];
    }
    if(cp){
        cout << "Yes\n";
        return;
    }

    pair<bool,bool> cpt = ifcmp(t);
    if(!cpt.first) {
        cout << "No\n";
        return;
    }

    map<int,int> cnt;
    ch = s[0];
    for(int i = 1;i < s.size();i ++)
    { 
        if(s[i] == ch){
            cnt[s[i]] ++;
        }
        ch = s[i];
    }
    if(cnt.size() >= 2) {
        cout << "No\n";
        return;
    }
    if(t[0] != t[n-1] || t[0] == (*cnt.begin()).first) cout << "No\n";
    else cout << "Yes\n";
    return;

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
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}