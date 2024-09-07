// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

class get_occr
{
private:
    string s;
public:
    get_occr(string _s) { s = _s; }
    vector<int> locate(vector<string> _s,bool dira)
    {
        int n = _s.size();
        vector<int> occr(n);
        map<char,vector<pair<int,int>>> gncing;
        if(dira == 1)
        {
            for(int i = 0;i < n;i++)
                gncing[_s[i][0]].push_back({i,0});
            for(int i = 0;i < s.size();i ++)
            {
                vector<pair<int,int>> gnctmp = gncing[s[i]];
                gncing[s[i]].clear();
                for(int j = 0;j < gnctmp.size();j ++)
                {
                    if(s[i] == _s[gnctmp[j].fi][gnctmp[j].se])
                    {
                        if(gnctmp[j].se+1 < _s[gnctmp[j].fi].size())
                            gncing[_s[gnctmp[j].fi][gnctmp[j].se+1]].push_back({gnctmp[j].fi,gnctmp[j].se+1});
                        else occr[gnctmp[j].fi] = i;
                    } else gncing[_s[gnctmp[j].fi][gnctmp[j].se]].push_back(gnctmp[j]);
                }
            }
        } else {
            for(int i = 0;i < n;i++) gncing[_s[i][_s[i].size()-1]].push_back({i,_s[i].size()-1});
            for(int i = 0;i < s.size();i ++)
            {
                vector<pair<int,int>> gnctmp = gncing[s[i]];
                gncing[s[i]].clear();
                for(int j = 0;j < gnctmp.size();j ++)
                {
                    if(s[i] == _s[gnctmp[j].fi][gnctmp[j].se])
                    {
                        if(gnctmp[j].se -1 >= 0)
                            gncing[_s[gnctmp[j].fi][gnctmp[j].se-1]].push_back({gnctmp[j].fi,gnctmp[j].se-1});
                        else occr[gnctmp[j].fi] = i;
                    } else gncing[_s[gnctmp[j].fi][gnctmp[j].se]].push_back(gnctmp[j]);
                }
            }
        }
        return occr;
    }
};

class solution
{
private:
public:
    void solve()
    {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<string> names(n);
        for(auto &x:names) cin >> x;
        get_occr oc(s);
        vector<int> occr = oc.locate(names,1);
        // vector<pii> gncing(n);
        // map<char,vector<pii>> gncing;
        // lop(i,0,n) gncing[names[i][0]].pb({i,0});
        // lop(i,0,s.size())
        // {
        //     vector<pii> gnctmp = gncing[s[i]];
        //     gncing[s[i]].clear();
        //     lop(j,0,gnctmp.size())
        //     {
        //         if(s[i] == names[gnctmp[j].fi][gnctmp[j].se])
        //         {
        //             if(gnctmp[j].se+1 < names[gnctmp[j].fi].size())
        //                 gncing[names[gnctmp[j].fi][gnctmp[j].se+1]].pb({gnctmp[j].fi,gnctmp[j].se+1});
        //             else occr[gnctmp[j].fi] = i+1;
        //         } else gncing[names[gnctmp[j].fi][gnctmp[j].se]].pb(gnctmp[j]);
        //     }
        //     // gncing[s[i]] = tmp;
        // }
        vector<string> DATES;
        vector<int> maxdate = {0,31,29,31,30,31,30,31,31,30,31,30,31};
        lop(i,1,13)
        {
            string s;
            s.push_back('0'+i/10);
            s.push_back('0'+i%10);
            lop(j,1,maxdate[i]+1)
            {
                string t = s;
                t.push_back('0'+j/10);
                t.push_back('0'+j%10);
                DATES.pb(t);
            }
        }
        vector<int> occrDT = oc.locate(DATES,0);
        for(auto &x:occr) x ++;

        // map<char,vector<pii>> gncingDT;
        // lop(i,0,366) gncingDT[DATES[i][DATES[i].size()-1]].pb({i,DATES[i].size()-1});
        // vector<int> occrDT(366);
        // for(int i = s.size()-1;i >= 0;i --)
        // {
        //     vector<pii> gnctmp = gncingDT[s[i]];
        //     gncingDT[s[i]].clear();
        //     vector<pii> tmp;
        //     lop(j,0,gnctmp.size())
        //     {
        //         if(s[i] == DATES[gnctmp[j].fi][gnctmp[j].se])
        //         {
        //             if(gnctmp[j].se-1 >= 0) 
        //                 gncingDT[DATES[gnctmp[j].fi][gnctmp[j].se-1]].pb({gnctmp[j].fi,gnctmp[j].se-1});
        //             else occrDT[gnctmp[j].fi] = i;
        //         } else gncingDT[DATES[gnctmp[j].fi][gnctmp[j].se]].pb(gnctmp[j]);
        //     }
        //     // gnctmp = tmp;
        // }
        vector<int> datepre(s.size()+1,0);
        for(auto x:occrDT) datepre[x] ++;
        vector<int> sufix(s.size()+1,0);
        for(int i = s.size()-1;i >= 0;i --) sufix[i] = sufix[i+1] + datepre[i];
        int ans = 0;
        // for(auto x:occr) cout << x <<" ";cout << "\n";
        for(auto x:occr) ans += (x == 0 ? x:sufix[x]);
        cout << ans << "\n";
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
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