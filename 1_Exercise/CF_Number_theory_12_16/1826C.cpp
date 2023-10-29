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

vector<int> pri;
vector<bool> vis(maxn+1,false);

void list()
{
    vis[1] = true;
    for(int i = 2;i < maxn;i ++)
    {
        if(!vis[i]) pri.push_back(i);
        for(int j = 0;j < pri.size();j ++)
        {
            if(1ll*i*pri[j] > maxn) break;
            vis[i*pri[j]] = true;
            if(i%pri[j] == 0) break;
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    if((n == 1) || (n == 1)) {
        cout << "Yes\n";
        return;
    }
    if(m >= n){
        cout << "No\n";
        return;
    }
    for(int i = 0;(pri[i] <= min(m,(int)sqrt(n)+1)) && (i < pri.size());i ++) if(n % pri[i] == 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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
    list();
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