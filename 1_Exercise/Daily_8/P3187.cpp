#define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}

using namespace std;

bool comp(int a,int b) {return a < b;}


class convexHell{
private:
    int cross(pair<int,int> a,pair<int,int> b) {
        return a.fi * b.se - a.se * b.fi;
    }

    int pf(int x) {
        return x * x;
    }

    int dis(int p, int q) {
        return pf(a[p].x - a[q].x) + pf(a[p].y - a[q].y);
    }

    int sqr(int p, int q, int y) {
        return abs((a[q] - a[p]) * (a[y] - a[q]));
    }

public:
    int n;
    vector<int> stk;
    vector<pair<int,int>> p;
    vector<int> used;
    vector<pair<int,int>> h;

    convexHell(vector<pair<int,int>> _dots)
    {
        init(_dot.size()-1,_dots);
    }

    vector<pair<int,int>> init(int _n,vector<pair<int,int>> _dots)
    {
        int tp = 0;
        p = _dots;
        n = _n;
        sort(p.begin(),p.end());
        stk[0] = 1;
        stk.resize(n+1);
        used.resize(n+1);
        for(int i = 2;i <= n;i ++){
            while (tp >= 2 && cross((p[stk[tp]] - p[stk[tp - 1]]),(p[i] - p[stk[tp]])) <= 0)
                used[stk[tp--]] = 0;
            used[i] = 1;  // used 表示在凸壳上
            stk[++tp] = i;
        }
        int tmp = tp;  // tmp 表示下凸壳大小
        for (int i = n - 1; i > 0; --i)
        if (!used[i]) {
            // ↓求上凸壳时不影响下凸壳
            while (tp > tmp && (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
            used[i] = 1;
            stk[++tp] = i;
        }
        h.resize(tp+1);
        for (int i = 1; i <= tp; ++i)  // 复制到新数组中去
        h[i] = p[stk[i]];
        int ans = tp - 1;
        return h;
    }

    vector<pair<int,int>> getConvexHell()
    {
        return h;
    }

    int getMaxDis()
    {
        // vector<pair<int,int>> sta = h;
        int mx = 0;
        vector<bool> is(n+1);
        int top = 0;
        int j = 3;
        if(top < 4) {
            mx = dis(sta[1],sta[2]);
            return mx;
        }
        for(int i = 1;i < top;i ++) {
            while (sqr(sta[i], sta[i + 1], sta[j]) <= sqr(sta[i], sta[i + 1], sta[j % top + 1]))
            j = j % top + 1;
            mx = max(mx, max(dis(sta[i + 1], sta[j]), dis(sta[i], sta[j])));
        }
        return mx;
    }
}



void solve()
{
    
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}