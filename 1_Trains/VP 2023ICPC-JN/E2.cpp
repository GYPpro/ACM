#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <cctype>
#define RI register int
#define CI const int &
using namespace std;
const int N = 200005, INF = 1e9;
int T, n, m, x, y;
class FileInputOutput
{
private:
    static const int S = 1 << 21;
#define tc() (A == B && (B = (A = Fin) + fread(Fin, 1, S, stdin), A == B) ? EOF : *A++)
    char Fin[S], *A, *B;

public:
    inline void read(int &x)
    {
        x = 0;
        char ch;
        while (!isdigit(ch = tc()))
            ;
        while (x = (x << 3) + (x << 1) + (ch & 15), isdigit(ch = tc()))
            ;
    }
} F;
namespace Network_Flow
{
    const int NN = 200005, MM = 1e7 + 5;
    struct edge
    {
        int to, nxt, v;
    } e[MM << 1];
    int cnt = 1, head[NN], cur[NN], dep[NN], s, t;
    inline void addedge(CI x, CI y, CI z)
    {
        e[++cnt] = (edge){y, head[x], z};
        head[x] = cnt;
        e[++cnt] = (edge){x, head[y], 0};
        head[y] = cnt;
    }
    inline void clear(void)
    {
        memset(head, 0, (t + 1) * sizeof(int));
        cnt = 1;
    }
#define to e[i].to
    inline bool BFS(void)
    {
        memset(dep, 0, (t + 1) * sizeof(int));
        dep[s] = 1;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (RI i = head[now]; i; i = e[i].nxt)
                if (e[i].v && !dep[to])
                    dep[to] = dep[now] + 1, q.push(to);
        }
        return dep[t];
    }
    inline int DFS(CI now, CI tar, int dis)
    {
        if (now == tar)
            return dis;
        int ret = 0;
        for (RI &i = cur[now]; i && dis; i = e[i].nxt)
            if (e[i].v && dep[to] == dep[now] + 1)
            {
                int dist = DFS(to, tar, min(dis, e[i].v));
                if (!dist)
                    dep[to] = INF;
                dis -= dist;
                ret += dist;
                e[i].v -= dist;
                e[i ^ 1].v += dist;
                if (!dis)
                    return ret;
            }
        if (!ret)
            dep[now] = 0;
        return ret;
    }
    inline int Dinic(int ret = 0)
    {
        while (BFS())
            memcpy(cur, head, (t + 1) * sizeof(int)), ret += DFS(s, t, INF);
        return ret;
    }
};
using namespace Network_Flow;
inline int travel(CI st, CI L, CI R, CI tp)
{
    static int vis[N];
    memset(vis, 0, (t + 1) * sizeof(int));
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    int ret = 0;
    cout << "-------\n";
    while (!q.empty())
    {
        int now = q.front();
        cout << now << " ";
        #undef to
        cout << "e.v " << e[now].v << " e.nxt" << e[now].nxt << " to:" << e[now].to << " head:" << head[now] << " cur" << cur[now] << " dep" << dep[now] << "\n";
        #define to e[i].to
        q.pop();
        ret += (L <= now && now <= R);
        for (RI i = head[now]; i; i = e[i].nxt)
            if (e[i].v == tp)
                if (!vis[to])
                    vis[to] = 1, q.push(to);
    }
    return ret;
}
#undef to
int main()
{
    // freopen("E.in","r",stdin);
    for (cin >> T; T; --T)
    {
        RI i, j;
        for (cin >> n >> m, i = 1; i <= m; ++i)
            cin >> x >> y, addedge(x, y + n, 1);
        for (s = 2 * n + 1, t = 2 * n + 2, i = 1; i <= n; ++i)
            addedge(s, i, 1), addedge(i + n, t, 1);
        


        Dinic();
        // cout << travel(s, 1, n, 1)  << " " << travel(t, n + 1, 2 * n, 0) << "\n";
        int sss = travel(s, 1, n, 1),rtt = travel(t, n + 1, 2 * n, 0) ;
        cout << sss << " " << rtt << " " << sss*rtt << ":\n";
        // printf("%lld\n", 1LL * travel(s, 1, n, 1) * travel(t, n + 1, 2 * n, 0));
        clear();
    }
    return 0;
}
