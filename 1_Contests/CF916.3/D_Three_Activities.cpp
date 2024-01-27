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

#define ll long long
#define mod1 998244353

using namespace std;

class md{
    public:
    int data,idx;
    md(int _a,int _b)
    {
        data = _a;
        idx = _b;
    }
    md(){};
};

bool comp(md a,md b)
{
    return a.data > b.data;
}

void solve()
{
    int n;
    cin >> n;
    vector<md> a(n);
    vector<md> b(n);
    vector<md> c(n);
    for(int i = 0;i < n;i ++) cin >> a[i].data;
    for(int i = 0;i < n;i ++) cin >> b[i].data;
    for(int i = 0;i < n;i ++) cin >> c[i].data;
    for(int i = 0;i < n;i ++){
        a[i].idx = i;
        b[i].idx = i;
        c[i].idx = i;
    }
    sort(a.begin(),a.end(),comp);
    sort(b.begin(),b.end(),comp);
    sort(c.begin(),c.end(),comp);
    int pvmx = 0;
    for(int ix = 0;ix < 3;ix ++)
    {
        set<int> used;
        int tpmx = a[ix].data;
        used.insert(a[ix].idx);
        for(int iy = 0;iy < 3;iy ++)
        {
            if(used.find(b[iy].idx) != used.end()) continue;
            tpmx += b[iy].data;
            used.insert(b[iy].idx);
            for(int iz = 0;iz < 3;iz ++)
            {
                if(used.find(c[iz].idx) != used.end()) continue;
                tpmx += c[iz].data;
                pvmx = max(pvmx,tpmx);
                tpmx -= c[iz].data;
            }
            used.erase(b[iy].idx);
            tpmx -= b[iy].data;
        }
    }
    cout << pvmx << "\n";
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