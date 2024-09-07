#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

#define map unordered_map
// #define set unordered_se

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int n,m;
        cin >> n >> m;
        vector<set<int>> cnj(n+1);

        for(int i = 0;i < n;i ++)
        {
            int u,v;
            cin >> u >> v;
            cnj[u].insert(v);
            cnj[v].insert(u);
        }
        vector<int> vst(n+1,0);
        // stack<set<int>> gt;
        int rtV = INT_MAX;
        int T = 1;
        int adj = 0;
        // int ans = 0;
        auto link = [&](int u,int v) -> void {
            cnj[u].insert(v);
            cnj[v].insert(u);
            adj ++;
        };

        auto dfs = [&](auto self,int p,int f) -> void {
            vst[p] = 1;
            cout << p << " ";
            if(p == n) return;
            if(cnj[p].find(p+1) == cnj[p].end()) {
                if(cnj[p].size() <= 1) {
                    if(rtV == p+1) return;
                    else link(p,p+1);
                } else link(p,p+1);
            }
            vector<int> tcnj;
            for(auto x:cnj[p]) tcnj.pb(x);
            for(int i = 0;i < tcnj.size();i ++) 
            {
                rtV = (i < cnj.size() -1) ? tcnj[i+1] : rtV;
                if(tcnj[i] == p || vst[tcnj[i]] == 1) continue;
                self(self,tcnj[i],p);
            }
            // cout << p << " ";
            // vst[p] = 1;
            // if(cnj[p].find(p+1) == cnj[p].end()) {
            //     if(cnj[p].size() <= 1) {
            //         if(gt.top().find(p+1) != gt.top().end()) {
            //             gt.pop();
            //             return;    
            //         } else {
            //             link(p,p+1);  
            //             adj ++;
            //         }
            //     }
            // }
            // auto gtt = cnj[p];
            // gt.push(gtt);
            // for(auto x:cnj[p]) {
            //     gt.top().erase(x);
            //     if(x == p || vst[x] == 1) continue;
            //     // cout << "?";
            //     self(self,x,p);
            //     gt.top().insert(x);
            // }
        };
        dfs(dfs,1,0);
        cout << adj << "\n";

        // vector<vector<int>> lnc;
        // set<int> lnct;
        // auto dfs = [&](auto self,int p,int t) -> void {
        //     if(lnct.find(p) != lnct.end()) return;
        //     lnct.insert(p);
        //     for(auto x:cnj[p]) if(x != p) self(self,x,p);
        // };
        // set<int> uvst;
        // for(int i = 0;i < n;i ++) uvst.insert(i+1);
        // for(int i = 1;i <= n;i ++){
        //     lnct.clear();
        //     if(uvst.find(i) == uvst.end())continue;
        //     vector<int> lncl;
        //     dfs(dfs,i,0);
        //     for(auto x:lnct) lncl.pb(x);
        //     lnc.pb(lncl);
        //     for(auto x:lncl) uvst.erase(x);
        // }

        // for(int i = 0;i < lnc.size()-1;i ++){
        //     // cnj[lnc[i][0]].insert(lnc[i+1][0]);
        //     // cnj[lnc[i][1]].insert(lnc[i+1][0]);
        //     link(lnc[i][0],lnc[i+1][0]);
        // }



        // auto addedge = [&](auto self,int p,int t) -> int {

        // };

    }
};  

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}