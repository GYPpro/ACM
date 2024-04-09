#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define pb push_back


    bool comp(int a,int b)
    {
        return a > b;
    }
using namespace std;

class solution{
    public:

    public:
    void solve()
    {
        int n , k ;
        cin >> n >> k;
        vector<vector<int>> arr(n+1);
        for(int i = 0;i <= n;i ++)
        {
            arr[i].resize(n - i + 2);
        }

        for(int i = 1;i <= n;i ++)
            for(int j = 1;j < n - i + 2;j ++)
                cin >> arr[i][j];
        
        for(auto &x:arr) x.pb(0);
        arr.pb(vector<int>(1));
        
        vector<vector<int>> dp(n+1,vector<int>(1,0));
        // dp[0].pb(0);
        // dp[1].pb(0);
        dp[1].pb(arr[1][1]);
        sort(dp[1].begin(),dp[1].end(),comp);
        for(int i = 2;i <= n;i ++)
        {
            //{ 生成的答案值 , 对应的补区间左端点 ，对应的dp下标 }

            priority_queue<array<int,3>> prq;
            // prq.push({dp[i - 1][0],i-1,0});  
            // for(int j = 0;j < i -1;j ++) prq.push({dp[j][0] + arr[j + 1][i - j],j,0});
            // prq.push({arr[1][i],0,0});
            for(int j = 0;j < i;j ++)
                prq.push({ dp[j][0], j+1 , 0});//arr[j+2][i-j-1]
            // prq.push()
            // vector<int> tmpAns(1,0);
            vector<int> tmpAns;
            while(tmpAns.size() < min((int)pow(2LL,min(31LL,i)),k)  && prq.size())
            {
                auto x = prq.top();
                // if(x[1] < i - 1) tmpAns.pb(x[0]);  
                tmpAns.pb(x[0] + arr[x[1] + 1 ][i - x[1]]);   
                // tmpAns.push_back(x[0]);// + arr[x[1]][i - x[1]]
                prq.pop();
                if(x[1] >= 1) if( dp[x[1]-1].size() > x[2] + 1) prq.push({dp[x[1]-1][x[2]+1] + arr[x[1]][i-x[1]] , x[1],x[2]+1});
               
                // if(dp[x[1]].size() > x[2] + 1 ) prq.push({dp[x[1]][x[2]+1] + (x[1] < i-1 ? arr[x[1]][i - x[1]] : 0),x[1],x[2] +1});

            }
            tmpAns.pb(arr[1][i]);
            sort(tmpAns.begin(),tmpAns.end(),comp);
            dp[i] = tmpAns;
        }
        for(auto x:dp[n]) cout << x << " ";
        cout << "\n";
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