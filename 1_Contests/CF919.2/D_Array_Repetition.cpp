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
#include <set>

#define int long long
#define mod1 998244353

using namespace std;

// void solve()
// {
//     int n,q;
//     cin >> n >> q;
//     vector<vector<ll int>> tilLis;
//     vector<ll int> maxdf;
//     tilLis.push_back(vector<ll int>());
//     maxdf.push_back(0);
//     for(int i = 0;i < n;i ++)
//     {
//         ll int t,x;
//         cin >> t >> x;
//         if((maxdf[maxdf.size()-1] >= (ll)1e18) || (maxdf[maxdf.size()-1] < 0)) continue;
//         if(t == 1)
//         {
//             tilLis[tilLis.size()-1].push_back(x);
//             maxdf[maxdf.size()-1] += 1;
//         } else {    
//             tilLis.push_back(vector<ll int>());
//             maxdf.push_back(maxdf[maxdf.size()-1] * x);
//         }
//     }
//     for(int i = 0;i < q;i ++)
//     {
//         ll int qust;
//         cin >> qust;
//         // ll int pvmx = maxdf[maxdf.size()-1];
//         // for(int i = tilLis.size()-1;i >= 0;)
//         // {
//         //     if(abs(pvmx-qust) <= tilLis[i].size())
//         //     {
//         //         cout << tilLis[i][tilLis[i].size() -1 - abs(pvmx-qust)] <<" ";
//         //         break;
//         //     } else {
//         //         i --;
//         //         qust %= pvmx;
//         //         pvmx = maxdf[i];
//         //     }
//         // }
//     }
//     cout << "\n";
// }

class pt{
    int ptMx;
    vector<int> dt;
    pt(){;}
    pt(int _ptMx,vector<int> _dt){
        ptMx = _ptMx;
        dt = _dt;
    }
};

void solve()
{
    
}

#define _WITH_T_

signed main()
{
    #ifndef _PRIV_TEST_
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
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