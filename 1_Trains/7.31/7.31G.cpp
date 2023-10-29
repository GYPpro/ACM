#include <iostream>
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 3010

#define ull unsigned long long
using namespace std;

int g[maxn][maxn] = {0};
int vis[maxn] = {0};
int match[maxn] = {0};
int n, m;
//求二分图最大匹配
int dfn;
int res;
void init()
{
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    memset(match, 0, sizeof(match));
    dfn = 0;
    res = 0;
}

void dfs(int v)
{
    vis[v] = dfn;
    for (int u = 1; u <= m; u++)
    {
        if (g[v][u] == 1 && match[u] == 0)
        {
            match[u] = v;
            return;
        }
    }
    for (int u = 1; u <= m; u++)
    {
        if (g[v][u] == 1 && vis[match[u]] != dfn)
        {
            dfs(match[u]);
            if (match[u] != 0)
            {
                match[u] = v;
                return;
            }
        }
    }
}

int solve()
{
    while (true)
    {
        dfn++;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (match[i] == 0)
            {
                dfs(i);
                if (match[i] != 0)
                {
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            break;
        }
        res += cnt;
    }
    return res;
}

void add(int from, int to)
{
    g[from][to] = 1;
}

void slove()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
        {
            int tmp;
            cin >> tmp;
            if(tmp) add(i+1,j+1);
        }
    int ans;
    ans = solve();
    cout << ans << endl;
}

int main()
{

    std::ios::sync_with_stdio(false);
    // test();
    int T;
    // scanf("%d",&T);
    // cin >> T;
    T = 1;
    // for(;;) test();
    for (int i = 0; i < T; i++)
        slove();

    // system("pause");
    return 0;
}