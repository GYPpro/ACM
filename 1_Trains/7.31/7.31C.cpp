/**************************
 * 二分图匹配(Hopcroft-Carp算法)
 * 复杂度 O (sqrt(n) * E)
 * 邻接表存图
 * Nx 为左端的端点数,使用前先赋值(点编号从 0 开始
 **************************/
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define ri int
using namespace std;
#define gc getchar
template <class T>
void read(T &x)
{
    ri f = 1, c;
    while (c = gc(), c < 48 || 57 < c)
        if (c == '-')
            f = -1;
    x = c ^ 48;
    while (c = gc(), 47 < c && c < 58)
        x = (x << 3) + (x << 1) + (c ^ 48);
    x *= f;
}
const int N = 3005, INF = 0x3f3f3f3f;
vector<int> G[N];
int Nx, Ny, k;

int Mx[N], My[N];
int dx[N], dy[N];
int dis, u, v;
bool used[N];
bool searchP()
{
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < Nx; ++i)
        if (Mx[i] == -1)
            Q.push(i), dx[i] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)
            break;
        int sz = G[u].size();
        for (int i = 0; i < sz; ++i)
        {
            int v = G[u][i];
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                    dx[My[v]] = dy[v] + 1, Q.push(My[v]);
            }
        }
    }
    return dis != INF;
}
bool DFS(int u)
{
    int sz = G[u].size();
    for (int i = 0; i < sz; ++i)
    {
        int v = G[u][i];
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis)
                continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (searchP())
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < Nx; ++i)
            if (Mx[i] == -1 && DFS(i))
                ++res;
    }
    return res;
}
int main()
{
    int n;
    read(n);
    Nx = Ny = n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp;
            read(tmp);
            if(tmp) G[i].push_back(j);
        }
    }
    printf("%d\n", MaxMatch());
}