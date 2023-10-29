#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>

#define ll long long
#define ld long double
const ll int maxn = (ll)(1e5 + 10);
const ll int mod1 = 998244353;
#define INT_MAX 2147483647

using namespace std;

int n, m;

void list()
{
}

void getpubpar(int u, int v, int deepth, vector<int> &par, vector<int> &deep, vector<int> &ans)
{
    // cout << u << " " << v << endl;
    if (ans[u] == -1 || ans[u] > deepth)
        ans[u] = deepth;
    if (ans[v] == -1 || ans[v] > deepth)
        ans[v] = deepth;
    for (; u != v;)
    {
        // if(ans[u] != -1)
        // {
        //     if(ans[v] != -1) return;
        //     else {
        //         ans[v] = deepth;
        //         v = par[v];
        //         continue;
        //     }
        // } else {
        //     ans[u] = deepth;
        //     u = par[u];
        //     if(ans[v] == -1){
        //         ans[v] = deepth;
        //         v = par[v];
        //     }
        // }

        if (deep[u] == deep[v])
        {
            u = par[u];
            v = par[v];
            if (ans[u] == -1 || ans[u] > deepth)
                ans[u] = deepth;
            if (ans[v] == -1 || ans[v] > deepth)
                ans[v] = deepth;
        }
        else if (deep[u] > deep[v])
        {
            u = par[u];
            if (ans[u] == -1 || ans[u] > deepth)
                ans[u] = deepth;
        }
        else
        {
            v = par[v];
            if (ans[v] == -1 || ans[v] > deepth)
                ans[v] = deepth;
        }
    }
    // if(u == v) return;
    // if(ans[u] != -1)
    // {
    //     if(ans[v] != -1) return;
    //     else ans[v] = deepth;
    //     getpubpar(u,par[v],deepth,par,deep,ans);
    // } else {
    //     if(ans[v] != -1)
    //     {
    //         ans[u] = deepth;
    //         getpubpar(par[u],v,deepth,par,deep,ans);
    //     }
    //     else {
    //         ans[v] = deepth;
    //         ans[u] = deepth;
    //         getpubpar(par[u],par[v],deepth,par,deep,ans);
    //     }
    // }
    // return;
}

int getpar(int p, int ivpar, int deepth, vector<vector<int>> &nex, vector<int> &par, vector<int> &deep)
{
    par[p] = ivpar;
    deep[p] = deepth;
    for (int i = 0; i < nex[p].size(); i++)
    {
        getpar(nex[p][i], p, deepth + 1, nex, par, deep);
    }
    return 0;
} // 父节点

int dfs(int deepth, int p, vector<vector<int>> &bustar, vector<int> &par, vector<int> &ans, vector<int> &deep, vector<int> &havept)
{
    cout << "et " << p << endl;

    if (havept[p] <= bustar[p].size() * 3)
        havept[p]++;
    else
        return 0;
    // if(ans[p] != -1) return 0;
    // if(deepth==n+1) return 0;
    for (int i = 0; i < bustar[p].size(); i++)
    {
        // if(havept[bustar[p][i]]) continue;
        // if(bustar[p][i]==1)
        // {
        //     getpubpar(1,p,deepth,par,deep,ans);
        // }
        // if(bustar[bustar[p][i]].size()==0&&(ans[bustar[p][i]]==-1||ans[bustar[p][i]]>deepth)) ans[bustar[p][i]]=deepth;
        // if(bustar[bustar[p][i]].size()>0)
        // {
        // getpubpar(p,bustar[p][i],deepth,par,deep,ans);
        // dfs(deepth+1,bustar[p][i],bustar,par,ans,deep,havept);
        // }
        int u = p;
        int v = bustar[p][i];    
        if (ans[u] == -1 || ans[u] > deepth)
        ans[u] = deepth;
        if (ans[v] == -1 || ans[v] > deepth)
        ans[v] = deepth;
        cout << u << " " << v << endl;
        for (; u != v;)
        {
            if(u != p)dfs(deepth + 1, u, bustar, par, ans, deep, havept);
            if(v != p)dfs(deepth + 1, v, bustar, par, ans, deep, havept);
            if (deep[u] == deep[v])
            {
                u = par[u];
                v = par[v];
                if (ans[u] == -1 || ans[u] > deepth)
                    ans[u] = deepth;
                if (ans[v] == -1 || ans[v] > deepth)
                    ans[v] = deepth;
            }
            else if (deep[u] > deep[v])
            {
                u = par[u];
                if (ans[u] == -1 || ans[u] > deepth)
                    ans[u] = deepth;
            }
            else
            {
                v = par[v];
                if (ans[v] == -1 || ans[v] > deepth)
                    ans[v] = deepth;
            }
        }
    }
    return 0;
} // 对公交车端点dfs

void slove()
{

    cin >> n >> m;
    vector<vector<int>> nex(n + 1);
    vector<int> par(n + 1);
    for (int i = 1; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nex[tmp].push_back(i + 1);
    }                        // 存储树的邻接表
    vector<int> deep(n + 1); // 存储深度
    getpar(1, 1, 0, nex, par, deep);
    vector<int> ans(n + 1, -1);
    vector<vector<int>> bustar(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int tma, tmb;
        cin >> tma >> tmb;
        bustar[tma].push_back(tmb);
        bustar[tmb].push_back(tma);
    } // 公交线路的端点
    vector<int> havept(n + 1, 0);
    dfs(1, 1, bustar, par, ans, deep, havept);
    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio("false");
    std::cin.tie(0);
    std::cout.tie(0);

    // list();
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++)
        slove();
    // system("pause");
    return 0;
}