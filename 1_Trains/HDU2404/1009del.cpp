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

bool comp(int a,int b) {return a < b;}
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
        vector<string> names;
        int sumL = 0;
        lop(i,0,n)
        {
            string tmp;
            cin >> tmp;
            sumL += tmp.size();
            names.pb(tmp);
        }
        vector<int> maxdate = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<map<char,vector<int>>> cnj(sumL);
        vector<int> exist(sumL,0);
        int cnt = 0;
        //trie
        for(auto x:names)
        {
            int pos = 0;
            for(auto y:x)
            {
                if(cnj[pos].find(y) == cnj[pos].end())
                {
                    cnj[pos][y] = vector<int>(2,-1);
                    cnj[pos][y][0] = cnt;
                    cnt++;
                }
                pos = cnj[pos][y][1];
            }
            exist[pos] = 1;
        }
        //dp
        vector<int> rDATE(s.size()+1,0);
        vector<vector<bool>> rDAY(33,vector<bool>(s.size()+1));
        vector<vector<bool>> rMON(13,vector<bool>(s.size()+1));
        vector<vector<int>> rcnt(10,vector<int>(s.size()+1));
        // lop(i,1,32) rDAY[i] = vector<int>(s.size()+1,0);
        // lop(i,1,12) rMON[i] = vector<int>(s.size()+1,0);
        // lop(i,0,10) rcnt[i] = vector<int>(s.size()+1,0);
        for(int i = s.size()-1;i >= 0;i --)
            if(s[i] > '9') continue;
            else rcnt[s[i]-'0'][i] = rcnt[s[i]-'0'][i+1]+1;

        auto countDigit = [&](int _i) -> int {
            int cnt = 0;
            for(auto x:rcnt[_i]) if(x) cnt++;
            return cnt;
        };

        auto countDate = [&](int _i,int _maxdate) -> int {
            int cnt = 0;
            for(int i = 1;i <= _maxdate;i ++) if(rDAY[i][_i]) cnt++;
            return cnt;
        };

        auto countMon = [&](int _i) -> int {
            int cnt = 0;
            for(int i = 1;i <= 12;i ++) if(rMON[i][_i]) cnt++;
            return cnt;
        };

        for(int i = s.size()-1;i >= 0;i --)
        {
            if(s[i] > '9') continue;
            int dg = s[i]-'0';
            if(dg <= 3)
            {
                lop(j,0,10)
                {
                    if(rcnt[i][j+1] == 0) continue;
                    if(dg*10+j <= 31) rDAY[dg*10+j][i] = 1;
                    if(dg*10+j <= 12) rMON[dg*10+j][i] = 1;
                }
            }
        }
        for(int i = s.size()-1;i >= 0;i --)
        {
            lop(j,1,13)
            {
                if(rMON[j][i] == 0) continue;
                int mex = maxdate[j];
                rDATE[i] += countDate(i+2,mex);
            }
        }
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
    // cout << 'a'-'1' << "--\n";

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}