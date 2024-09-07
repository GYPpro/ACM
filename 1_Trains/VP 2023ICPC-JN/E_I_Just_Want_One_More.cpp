// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
// #define ll long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1e6;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

// #ifndef _IN_TEMPLATE_
// #include <template_overAll.h>
// #endif

class maxFlow//AC
{
public:
    class edge
    {
    public:
        int nxt,                   // 出度
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
    int maxFlowAns;

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
        // cout << "ADDED" << _u << "->" << _v << "\n";
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
            int at = que.front();
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

    int dfs(int at, int flow)
    {
        if ((at == T) || (!flow))
            return flow; // 到了或者没了
        int ret = 0;  // 本节点最大流
        for (int &i = fir[at]; i < edgeList[at].size(); i++)
        {
            auto tar = edgeList[at][i];      // 目前遍历的边
            int tlFlow = 0;                  // 目前边的最大流
            if (dep[at] == dep[tar.nxt] - 1) // 遍历到的边为合法边
            {
                tlFlow = dfs(tar.nxt, min(tar.cap - tar.flow, flow - ret));
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

    int dinic()
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

    int find_range(int st,int tar)
    {
        cout << "[";
        vector<int> vst(edgeList.size());
        queue<int> q;
        
        // q.push(st);
        for(auto x:edgeList[st])
        {
            if(x.flow == tar) q.push(x.nxt);
        }
        int ret = 0;
        vst[st] = 1;
        while(q.size())
        {
            int now = q.front();
            cout << now << "\n";
            q.pop();
            for(auto x:edgeList[now])
                if(! vst[x.nxt]) cout << x.nxt << " ",ret ++,vst[x.nxt] = 1;
            
        }
        cout << "]\n";
        // while(q.size())
        // {
        //     int now = q.front();
        //     q.pop();
        //     // ret += (l <= now && now <= r);
        //     if (l <= now && now <= r) {
        //         // cout << "finded:" << now;
        //         ret ++;
        //     }
        //     for(auto x:edgeList[now])
        //     {
        //         if(x.flow == tar || x.flow == tar2) if(!vst[x.nxt]) vst[x.nxt]=1,q.push(x.nxt); 
        //     }
        // }
        return ret;
    }

};


void solve()
{
    int n,m;
    cin >> n >> m;
    int F = 0,E = n*2+1;
    maxFlow mf(n*2+4);
    // vector<int> 
    set<pii> edges,redges;
    
    lop(i,0,m)
    {
        int u,v;
        cin >> u >> v;
        // if(redges.find(ord(u,v+n+1)) != redges.end()) continue;
        // redges.insert(ord(u,v+n+1));
        mf.addedge(u,v+n,1);

        // mf.addedge(v+n+1,u,1);
        // mf.addedge(F,u,1),mf.addedge(E,v+n+1,1);

        // if(edges.find(ord(F,u+1)) == edges.end())
        //     mf.addedge(F,u+1,1),edges.insert(ord(F,u+1));

        // if(edges.find(ord(E,v+n+2)) == edges.end())
        //     mf.addedge(v+n+2,E,1),edges.insert(ord(v+n+2,E));
    }

    // lop(i,1,n+1) if(edges.find(ord(F,i+1)) == edges.end()) mf.addedge(F,i+1,1),edges.insert(ord(F,i+1));
    // lop(i,1,n+1) if(edges.find(ord(E,i+n+2)) == edges.end()) mf.addedge(i+n+2,E,1),edges.insert(ord(E,i+n+2));
    // lop(i,1,n+1) mf.addedge(E,i+n+2,1);

    lop(i,1,n+1) mf.addedge(F,i,1);
    lop(i,n+1,n*2+1) mf.addedge(i,E,1);
 
    mf.resetTS(E,F);
    // int cntl = 0,cntr = 0;
    vector<int> cntl,cntr;

    int a = mf.dinic();
    
    // vector<int> vis(n+1);
    // queue<int> q;
    
    // for(auto x:mf.edgeList[F]){
    //     q.push(x.nxt);
    // }
    // while(q.size())
    // {

    // }

    lop(i,0,n*2+3)
    {
        cout << i << " ---\t-> -----------\n";
        for(auto x:mf.edgeList[i]) cout << "cap:" << x.cap << " flow:" << x.flow << " nxt:" <<  x.nxt << "\n";
    }

    // for(auto x:mf.edgeList[E]) if(x.cap == 0) cntl.pb(x.nxt);
    // for(auto x:mf.edgeList[F]) if(x.cap == 1) cntr.pb(x.nxt);
    // for(auto x:cntl) cout << x - n - 2 << " ";cout << "\n";
    // for(auto x:cntr) cout << x - 1<< " ";cout << "\n";
    // cout << a << " " << cntl << " " << cntr << "\n";
    // cout << (n-a) * (n-a+redges.size()-a) << "\n";
    // cout << a << "\n";
    cout << mf.find_range(F,1) << " " << mf.find_range(E,0) << "\n";
    cout << mf.find_range(F,0) << " " << mf.find_range(E,-1) << "\n";
    // cout << mf.find_range(F,1,n,1,1) << " " << mf.find_range(E,n+1,2*n,0,-1) << "\n";
    // cout << mf.find_range(E,1,n,0,-1) * mf.find_range(F,n+1,2*n,1,1) << "\n";
    // lop(i,0,)
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
