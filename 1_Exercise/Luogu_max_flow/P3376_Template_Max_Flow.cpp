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
#include <queue>

#define ll long long
#define mod1 998244353
#define N 205
#define ull unsigned long long
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

using namespace std;

struct MF
{
    struct edge
    {
        int v, nxt = 0, cap, flow;
    } e[N];

    int fir[N], cnt = 0;

    int n, S, T;
    ll maxflow = 0;
    int dep[N], cur[N];

    void init()
    {
        memset(fir, -1, sizeof fir);
        memset(dep, 0, sizeof fir);
        memset(cur, 0, sizeof fir);
        cnt = 0;
    }

    void addedge(int u, int v, int w)
    {
        e[cnt] = {v, fir[u], w, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
    }

    bool bfs()
    {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));

        dep[S] = 1;
        q.push(S);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; i != 0; i = e[i].nxt)
            {
                int v = e[i].v;
                if ((!dep[v]) && (e[i].cap > e[i].flow))
                {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[T];
    }

    int dfs(int u, int flow)
    {
        if ((u == T) || (!flow))
            return flow;

        int ret = 0;
        for (int &i = cur[u];  i != 0; i = e[i].nxt)
        {
            int v = e[i].v, d;
            if ((dep[v] == dep[u] + 1) &&
                (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow))))
            {
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == flow)
                    return ret;
            }
        }
        return ret;
    }

    void dinic()
    {
        while (bfs())
        {
            memcpy(cur, fir, sizeof(int) * (n + 1));
            maxflow += dfs(S, INT_MAX);
        }
    }
};

class maxFlow
{
private:
    class edge
    {
    public:
        ll int nxt,                   // 出度
              cap,                   // 容量
              flow;                  // 流量
        pair<int, int> revNodeIdx; // 反向边
    public:
        edge(int _nxt, int _cap)
        {
            nxt = _nxt;
            cap = _cap;
            flow = 0;
        }
        void setRevIdx(int _i, int _j)
        {
            revNodeIdx.first = _i;
            revNodeIdx.second = _j;
        }
    };
    vector<vector<edge>> edgeList; // 节点列表
    vector<int> dep;               // 深度
    vector<int> fir;               // 节点最近合法边
    ll int maxFlowAns;

    int T, S;

public:
    maxFlow(int _n)
    {
        maxFlowAns = 0;
        S = 1;
        T = _n;
        edgeList.resize(_n + 1);
        dep.resize(_n + 1);
        fir.resize(_n+1);
    }

    void resetTS(int _T, int _S)
    {
        T = _T;
        S = _S;
    }

    void addedge(int _u, int _v, int _w)
    {
        edgeList[_u].push_back(edge(_v, _w));
        edgeList[_v].push_back(edge(_u, 0)); // 反向建边
        edgeList[_u][edgeList[_u].size() - 1].setRevIdx(_v, edgeList[_v].size() - 1);
        edgeList[_v][edgeList[_v].size() - 1].setRevIdx(_u, edgeList[_u].size() - 1);
    }

    bool bfs() // 统计深度
    {
        queue<int> que;
        for (auto x = dep.begin(); x != dep.end(); x++)
            (*x) = 0;

        dep[S] = 1;
        que.push(S);
        while (que.size())
        {
            ll int at = que.front();
            que.pop();
            for (int i = 0; i < edgeList[at].size(); i++)
            {
                auto tar = edgeList[at][i];
                if ((!dep[tar.nxt]) && (tar.flow < tar.cap))
                {
                    dep[tar.nxt] = dep[at] + 1;
                    que.push(tar.nxt);
                }
            }
        }
        return dep[T];
    }

    ll int dfs(int at, ll int flow)
    {
        if ((at == T) || (!flow))
            return flow; // 到了或者没了
        ll int ret = 0;  // 本节点最大流
        for (int &i = fir[at]; i < edgeList[at].size(); i++)
        {
            auto tar = edgeList[at][i];      // 目前遍历的边
            int tlFlow = 0;                  // 目前边的最大流
            if (dep[at] == dep[tar.nxt] - 1) // 遍历到的边为合法边
            {
                tlFlow = dfs(tar.nxt, min((ll)tar.cap - tar.flow, flow - ret));
                if (!tlFlow)
                    continue;                                                         // 若最大流为0，什么都不做
                ret += tlFlow;                                                        // 本节点最大流累加
                edgeList[at][i].flow += tlFlow;                                       // 本节点实时流量
                edgeList[tar.revNodeIdx.first][tar.revNodeIdx.second].flow -= tlFlow; // 反向边流量
                if (ret == flow)
                    return ret; // 充满了就不继续扫了
            }
        }
        return ret;
    }

    ll int dinic()
    {
        if (maxFlowAns)
            return maxFlowAns;
        while (bfs())
        {
            for(auto x = fir.begin();x != fir.end();x ++) (*x) = 0;
            maxFlowAns += dfs(S, INT_MAX);
        }
        return maxFlowAns;
    }
};

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    maxFlow mf(n);
    // MF mf;
    // mf.n = n;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mf.addedge(u, v, w);
    }
    mf.resetTS(t, s);
    // mf.S = s;
    // mf.T = t;
    // mf.dinic();
    // cout << mf.maxflow << endl;
    cout << mf.dinic() << endl;
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