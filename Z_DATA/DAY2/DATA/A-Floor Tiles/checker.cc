#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int MAXN = 3000005;
int get_max_cnt(int n, int m, int type)
{
    int temp = n + m;
    n--;
    m--;
    if ((n & 1) && (m & 1) && type == 0)
    {
        return (n * m + 1) / 2 + temp;
    }
    else
    {
        return n * m / 2 + temp;
    }
}
int get_min_cnt(int n, int m)
{
    return n + m;
}
int fa[MAXN];
int _f(int x)
{
    return fa[x] == x ? x : fa[x] = _f(fa[x]);
}
void _merge(int x, int y)
{
    if (_f(x) != _f(y))
    {
        fa[_f(x)] = _f(y);
    }
}
int U(int m, int x, int y)
{
    return x * (2 * m + 1) + y;
}
int D(int m, int x, int y)
{
    return (x + 1) * (2 * m + 1) + y;
}
int L(int m, int x, int y)
{
    return x * (2 * m + 1) + m + y;
}
int R(int m, int x, int y)
{
    return x * (2 * m + 1) + m + y + 1;
}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    for (int cas = 1; cas <= T; ++cas)
    {
        //setTestCase(cas);
        int n = inf.readInt();
        int m = inf.readInt();
        int k = inf.readInt();
        int x = inf.readInt();
        int y = inf.readInt();
        string ts = inf.readToken();
        int t = ts[0] == 'B';
        if ((x + y) & 1)
            t ^= 1;
        bool flag = get_min_cnt(n, m) <= k && k <= get_max_cnt(n, m, t);
        string yn = ouf.readToken("[YyEeSsNnOo]{2,3}", "yn");
        for (auto& i : yn)
        {
            i |= ' ';
        }
        quitif(yn != "yes" && yn != "no", _wa, "token must give yes or no");
        quitif(yn == "yes" && !flag, _wa,
               "expected: no, found yes, %d %d %d k must in [%d,%d], but %d", n,
               m, t, get_min_cnt(n, m), get_max_cnt(n, m, t), k);
        quitif(yn == "no" && flag, _wa,
               "expected: yes, found no, %d %d %d k must in [%d,%d], k:%d", n,
               m, t, get_min_cnt(n, m), get_max_cnt(n, m, t), k);
        if (flag)
        {
            char buffer[233];
            vector<string> a;
            a.resize(n);
            sprintf(buffer, "[AB]{%d}", m);
            for (int i = 0; i < n; ++i)
            {
                a[i] = ouf.readToken(buffer, "ai");
            }
            quitif(a[x-1][y-1]!=ts[0], _wa, "need %c at (%d,%d) found: %c", ts[0],x,y, a[x-1][y-1]);
            for (int i = 0; i < n + m + 2 * n * m; ++i)
            {
                fa[i] = i;
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (a[i][j] == 'A')
                    {
                        _merge(U(m, i, j), L(m, i, j));
                        _merge(D(m, i, j), R(m, i, j));
                    }
                    else
                    {
                        _merge(U(m, i, j), R(m, i, j));
                        _merge(D(m, i, j), L(m, i, j));
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n + m + 2 * n * m; ++i)
            {
                if (_f(i) == i)
                {
                    ++cnt;
                }
            }
            quitif(cnt != k, _wa, "need %d blocks found: %d", k, cnt);
        }
    }
    quitf(_ok, "all ok!");
    return 0;
}