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

int dfs(int n,int mx, vector<vector<int>> &Gra, vector<int> &mxTar)
{
    if (mxTar[n] != -1)
        return mxTar[n];
    mxTar[n] = mx;
    for (int i = 0; i < Gra[n].size(); i++)
        dfs(Gra[n][i],mx, Gra, mxTar);
    return mxTar[n] = mx;
}

void solve()
{ 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Gra(n + 1);
    for (int i = 0; i < m; i++)
    {
        int tf, tt;
        cin >> tt >> tf;
        Gra[tf].push_back(tt);
    }
    vector<int> mxTar(n+1,-1);
    dfs(n,n,Gra,mxTar);
    for (int i = n; i >= 1; i--)
        dfs(i,i,Gra,mxTar);
    for(int i = 1;i <= n;i ++)
        cout << mxTar[i] << " ";
    cout << endl;
}

// #define _WITH_T_

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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}