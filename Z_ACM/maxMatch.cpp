// HDU2389
#include <iostream>
#include <cstdliba
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int N = 3002;
const int M = N * N;

const int INF = 0x3f3f3f3f;

struct Edge
{
    int v;
    int next;
} edge[M];

// 两边顶点的个数
int nx, ny;
// 边数
int cnt;
// 当前最短增广路长度
int dis;

// 前向星头
int head[N];
// 两边的匹配点，-1表示未匹配
/*  xlink[i]表示左集合顶点所匹配的右集合顶点序号，
    ylink[i]表示右集合i顶点匹配到的左集合顶点序号 */
int xlink[N], ylink[N];
/* dx[i]表示左集合i顶点在bfs中到起始位置的路径长度（距离编号），dy[i]表示右集合i顶点的距离编号*/
int dx[N], dy[N];
// 寻找增广路的标记数组
int vis[N];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(xlink, -1, sizeof(xlink));
    memset(ylink, -1, sizeof(ylink));
}

void add_edge(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = head[u], head[u] = cnt++;
}

// 找到最多最短增广路。
int bfs()
{
    queue<int> q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < nx; ++i)
    {
        if (xlink[i] == -1)
        {
            q.push(i);
            dx[i] = 0;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dx[u] > dis)
            break;

        for (int e = head[u]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v;
            // 右边的v点还未遍历
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (ylink[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[ylink[v]] = dy[v] + 1;
                    q.push(ylink[v]);
                }
            }
        }
    }
    return dis != INF;
}
// 遍历每条增广路
int find_aug_path(int u)
{
    for (int e = head[u]; e != -1; e = edge[e].next)
    {
        int v = edge[e].v;
        // 沿着增广路的边走
        if (!vis[v] && dy[v] == dx[u] + 1)
        {
            vis[v] = 1;
            // dy[v] == dis，达到最长长度不能再增广了
            if (ylink[v] != -1 && dy[v] == dis)
                continue;
            if (ylink[v] == -1 || find_aug_path(ylink[v]))
            {
                xlink[u] = v, ylink[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int HK()
{
    int ans = 0;
    while (bfs())
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < nx; i++)
            if (xlink[i] == -1)
            {
                ans += find_aug_path(i);
            }
    }
    return ans;
}

double dist(const node a, const node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void read_case()
{
    init();
    int Time;
    scanf("%d", &Time);
    scanf("%d", &nx);
    for (int i = 0; i < nx; i++)
    {
        scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].v);
    }
    scanf("%d", &ny);
    for (int i = 0; i < ny; i++)
    {
        scanf("%lf%lf", &b[i].x, &b[i].y);
    }
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            double limit = a[i].v * Time;
            double s = dist(a[i], b[j]);
            if (s <= limit)
                add_edge(i, j);
        }
    }
}

void solve()
{
    // 读取数据 + 初始化 + 建图
    read_case();
    // 求最大匹配
    int ans = HK();
    printf("%d\n\n", ans);
}

int main()
{
    int y, times = 0;
    scanf("%d", &t);
    while (t--)
    {
        printf("Scenario #%d:\n", ++times);
        solve();
    }
    return 0;
}