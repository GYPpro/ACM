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
#include <set>
#include <unordered_map>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

bool comp(string s1,string s2){
    return s1.length() < s2.length();
}

void solve()
{
    int n;
    cin >> n;
    int t = /* sqrt(2*n) + 1 */n;
    set<string> smap;
    vector<string> slist;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.size() > t)
            continue;
        else
        {
            smap.insert(s);
            slist.push_back(s);
        }
    }
    sort(slist.begin(),slist.end(),comp);
    for(int i = slist.size()-1;i >= 0;i --)
    {
        bool ifAC = 1;
        for(int l = 0;l < slist[i].size();l ++)
        {
            string tmp;
            for(int r = l;r < slist[i].size();r ++)
            {
                tmp.push_back(slist[i][r]);
                if(smap.find(tmp) == smap.end()){
                    ifAC = 0;
                    break;
                }
            }
        }
        if(ifAC){
            cout << slist[i].size() << endl;
            return;
        }
    }
    cout << 0 << endl;
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}