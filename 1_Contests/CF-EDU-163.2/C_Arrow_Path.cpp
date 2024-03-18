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

class solution
{
private:
    vector<vector<int>> arr;
    vector<vector<int>> ptd;
    int n;
    bool t = false;
    void ddfs(int i, int x)
    {
        if (ptd[i][x])
            return;
        ptd[i][x] = 1;
        if (i == n && x == 1LL)
        {
            t = 1LL;
            return;
        }
        if (i < n - 1)
            if (arr[i + 1][x])
                ddfs(i + 2, x);
        if (arr[i][!x])
            ddfs(i + 1, !x);
        return;
    };

public:
    void solve()
    {
        // int n;
        cin >> n;
        arr = vector<vector<int>>(n, vector<int>(2));
        ptd = vector<vector<int>>(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            char t;
            cin >> t;
            if (t == '>')
                arr[i][0] = 1;
            else
                arr[i][0] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            char t;
            cin >> t;
            if (t == '>')
                arr[i][1] = 1;
            else
                arr[i][1] = 0;
        }
        n--;

        auto dfs = [&](auto self,int i,int x) -> void{
            if(ptd[i][x]) return;
            ptd[i][x] = 1;
            if(i == n && x == 1LL) {t = 1LL;return;}
            if(i < n-1) if(arr[i+1][x]) self(self,i+2,x);
            if(arr[i][!x]) self(self,i+1,!x);
            return;
        };

        dfs(dfs,0,0);


        ddfs(0, 0);

        if (t)
            cout << "YES\n";
        else
            cout << "NO\n";
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