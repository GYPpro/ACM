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
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

using namespace std;

int getIdx(int i, int j, int c)
{
    return i * c + j;
}

bool avI(int rt,int r,int c)
{
    int i = rt/c;
    int j = rt%c;
    return i > 0 && i < r-1 && j > 0 && j < c-1;
}

int dfs(int n, vector<vector<int>> &Gra, vector<int> &mxTar)
{
    if (mxTar[n] != -1)
        return mxTar[n];
    int mx = 0;
    for (int i = 0; i < Gra[n].size(); i++)
        mx = max(dfs(Gra[n][i], Gra, mxTar), mx);
    return mxTar[n] = mx + 1;
}

void solve()
{
    int r, c;
    cin >> r >> c;
    r += 2;
    c += 2;
    vector<vector<int>> Gra(r * c, vector<int>());
    vector<vector<int>> Hei(r , vector<int>(c, INT_MAX));

    for (int i = 1; i < r-1; i++)
        for (int j = 1; j < c-1; j++)
            cin >> Hei[i][j];

    for (int i = 1; i < r-1; i++)
        for (int j = 1; j < c-1; j++)
        {
            if (Hei[i][j] > Hei[i - 1][j])
                Gra[getIdx(i, j, c)].push_back(getIdx(i - 1, j, c));
            if (Hei[i][j] > Hei[i + 1][j])
                Gra[getIdx(i, j, c)].push_back(getIdx(i + 1, j, c));
            if (Hei[i][j] > Hei[i][j - 1])
                Gra[getIdx(i, j, c)].push_back(getIdx(i, j - 1, c));
            if (Hei[i][j] > Hei[i][j + 1])
                Gra[getIdx(i, j, c)].push_back(getIdx(i, j + 1, c));
        }

    vector<int> mxTar(r * c, -1);
    int ans = 0;
    for (int i = 0; i < r * c; i++)
        if(avI(i,r,c)) ans = max(ans, dfs(i, Gra, mxTar));
    cout << ans << endl;
}

// #define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
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