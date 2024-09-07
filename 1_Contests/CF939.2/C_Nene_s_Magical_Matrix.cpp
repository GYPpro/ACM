#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution{
    private:

    public:
    void solve()
    {
        int n;
        cin >> n;
        int sum = 0;
        int cnt = 0;
        vector<int> pri;
        vector<vector<int>> mtx(n,vector<int> (n));
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++)
                mtx[i][j] = max(i,j) +1;
        // for(int i = 0;i < n;i ++){ pri.pb(i+1);sum += i+1;}
        // int ans = (n/2) * sum;
        // for(int i =(n/2) +1;i <= n;i ++) ans += i * n;
        // cout << ans << " " << n + n/2 <<"\n";
        // int m  = 0;
        // for(int rn = n;rn;rn = rn/2){
        //     for(int i = 0;i < rn;i ++)
        //     {
        //         // cout << m+1 << " " << i + 1 << " ";
        //         // for(int i = 0;i < n;i ++) cout << i+1 << " ";
        //         // cout << "\n";
        //         cnt ++;
        //         if(m)
        //             for(int j = 0;j < n;j ++)mtx[i][j] = j+1;
        //         else 
        //             for(int j = 0;j < n;j ++)mtx[j][i] = j+1;
        //     }m = !m;
        // for(auto x:mtx){
        //     for(auto y:x) cout << y << " ";cout << "\n";}}
        for(auto x:mtx)
            for(auto y:x) sum += y;
        cout << sum << " " << 2*n << "\n";
        for(int i = n;i > 0;i --)
        {
            cout << 1 << " " << i << " ";
            for(int ii = 0;ii < n;ii ++) cout << ii+1 << " ";
            cout << "\n";
            cout << 2 << " "  << i << " ";
            for(int ii = 0;ii < n;ii ++) cout << ii+1 << " ";
            cout << "\n";
        }
        // for(auto x:mtx){
        //     for(auto y:x) cout << y << " ";cout << "\n";}
        // cout << sum << " " << cnt <<"\n";
        // m = 0;
        // for(int rn = n;rn;rn = rn/2){
        //     for(int i = 0;i < rn;i ++)
        //     {
        //         cout << m+1 << " " << i + 1 << " ";
        //         for(int i = 0;i < n;i ++) cout << i+1 << " ";
        //         cout << "\n";
        //         // if(m)
        //         //     for(int j = 0;j < n;j ++)mtx[i][j] = j+1;
        //         // else 
        //         //     for(int j = 0;j < n;j ++)mtx[j][i] = j+1;
        //     }m = !m;}
        // // for(int i = 0;i < n/2;i ++)
        // // {
        // //     cout << 2 << " " << i + 1 << " ";
        // //     for(int i = 0;i < n;i ++) cout << i+1 << " ";
        // //     cout << "\n";
        // // }
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