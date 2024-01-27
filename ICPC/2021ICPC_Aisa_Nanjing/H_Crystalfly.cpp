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

class Tree{
public:
    vector<vector<int>> son;
    vector<vector<int>> nxt;
    vector<int> w;
    vector<int> t;
    vector<int> dep;
    vector<int> par;
    vector<int> dp;
    Tree(int n)
    {
        son.resize(n+1);
        w.resize(n+1);
        t.resize(n+1);
        dep.resize(n+1);
        par.resize(n+1);
        nxt.resize(n+1);
        dp.resize(n+1);
    }
    void ins(int u,int v)
    {
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }

    void dfs(int p)
    {
        if(son[p].size()) return;
        for(int i = 0;i < nxt[p].size();i ++)
        {
            int x = nxt[p][i];
            if(x == par[p]) continue;
            son[p].push_back(x);
            par[x] = p;
            dep[x] = dep[p]+1;
            dfs(x);
        } 
    }

    int f(int x)
    {
        if(dp[x]) return dp[x];
        if(!son[x].size()) return dp[x] = 0;
        int sumua = 0;
        int va = 0;
        for(int i = 0;i < son[x].size();i ++)
        {
            int p = son[x][i];
            va = max(va,w[p]);
            sumua += f(p);
        }
        int mwb = 0;
        int mib = 0;
        for(int i = 0;i < son[x].size();i ++)
        {
            int p = son[x][i];
            if(t[p] < 3) continue;
            if(w[p]>mwb){
                mwb = w[p];
                mib = i;
            }
        }
        int maxtb = 0;
        for(int i = 0;i < son[x].size();i ++)
        {
            if(i == mib) continue;
            int p = son[x][i];
            int sumub = 0;
            for(int j = 0;j < son[p].size();j ++)
            {
                sumub += f(son[p][j]);
            }
            maxtb = max(sumub-f(p)+w[p],maxtb);
        }
        return dp[x] = max(maxtb,sumua+va);
    }

    void init()
    {
        dfs(1);
    }
};

void solve()
{
    int n;
    cin >> n;
    Tree tr(n);
    for(int &x:tr.w) cin >> x;
    for(int &x:tr.t) cin >> x;
    for(int i = 0;i < n-1;i ++)
    {
        int u,v;
        cin >> u >> v;
        tr.ins(u,v);
    }
    tr.init();
    cout << tr.f(1)+tr.w[1] << "\n";
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