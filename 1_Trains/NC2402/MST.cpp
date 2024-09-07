#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

// #define map unordered_map
// #define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
const int INF = 9223372036854775807LL;

// void sort(auto &x)
// {
//     sort(x.begin(),x.end());
// };

using namespace std;

struct DSU {
    vector<int> f, sz;
    DSU(int n)
        : f(n), sz(n, 1) {
        //  构建函数
		for(int i = 0;i < n;i ++) f[i] = i;
    }
    int find(int x) {
        // 寻找父亲，路径压缩
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool merge(int a, int b) {
        // 合并两个节点
        int fa = find(a), fb = find(b);
        if (fa == fb)
            return false;
        if (sz[fb] > sz[fa])
            swap(fa, fb);
        f[fb] = fa;
        sz[fa] += sz[fb];
        return true;
    }
    bool same(int a, int b) {
        // 判断两个点是否是一个集合
        return find(a) == find(b);
    }
};
 

class solution
{
private:

public:
    void solve()
    {
        int ttn,ttm,qq;
        cin >> ttn >> ttm >> qq;
        map<pii,int> wei;
        set<pii> edgeList;
        vector<vector<int>> E;
        for(int i = 0;i < ttm;i ++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            wei[{min(u,v),max(u,v)}] = w;
            edgeList.insert({min(u,v),max(u,v)});
            E.pb({min(u,v),max(u,v),w});
        }    
        sort(E.begin(),E.end(),[](vector<int> a,vector<int> b) -> bool {return a[2] <b[2];});

        vector<int> SubN;
        vector<vector<int>> ET;
        DSU ds(ttn+1);
        vector<int> ifSUBN(ttn+1);
        while(qq--)
        {
            int sl;
            ET.clear();
            cin >> sl;
            SubN.clear();
            SubN.resize(sl);

            for(int i = 0;i < sl;i ++){
                int t;
                cin >> t;
                SubN[i] = t;
                ifSUBN[t] = 1;
            }
            if(sl == 1) {cout << 0 << "\n";continue;}
            if(sl < sqrt(ttn)){//对于每一对可用节点检查是否是边
                for(int i = 0;i < sl;i ++)
                    for(int j = i+1;j < sl;j ++)
                    {
                        if(edgeList.find({min(SubN[i],SubN[j]),max(SubN[i],SubN[j])}) != edgeList.end()) {
                                ET.push_back({min(SubN[i],SubN[j]),max(SubN[i],SubN[j]),wei[{min(SubN[i],SubN[j]),max(SubN[i],SubN[j])}]});
                        }
                    }
                
                sort(ET.begin(),ET.end(),[](vector<int> a,vector<int> b) -> bool {return a[2] <b[2];});
                int n = sl;
                int cnt = 1;
                int res = 0;
                // q.push({0,1});
                // for(auto x:ds.f) cout << x << " ";
                for(auto x:ET)
                {
                    // cout << x[0] << " " << x[1] << "\n";
                    if(ds.same(x[0],x[1])) continue;
                    // cout << "NC" ;
                    ds.merge(x[0],x[1]);
                    res += x[2];
                    cnt ++;
                }
                for(auto x:SubN) (ds.f[x] = x,ifSUBN[x] = 0);
                // cout << "--" << cnt << " " << res << "\n";
                if(cnt == n) cout << res << "\n";
                else cout << "-1\n";

            } else {//对于每个节点枚举可用边
                
                int n = sl;
                int cnt = 1;
                int res = 0;
                for(auto x:E)
                {
                    if(!(ifSUBN[x[0]] && ifSUBN[x[1]])) continue;
                    if(ds.same(x[0],x[1])) continue;
                    // cout << "NC" ;
                    ds.merge(x[0],x[1]);
                    res += x[2];
                    cnt ++;
                }
                
                for(auto x:SubN) (ds.f[x] = x,ifSUBN[x] = 0);

                // cout << "--" << cnt << " " << res << "\n";
                if(cnt == n) cout << res << "\n";
                else cout << "-1\n";
            }
            // for(auto x:ET) 
            // {
            //     cout << "[ ";
            //     for(auto y:x) cout << y << " ";
            //     cout << "]\n";
            // }

        }
        
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // cin >> T;
// ..,
    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}