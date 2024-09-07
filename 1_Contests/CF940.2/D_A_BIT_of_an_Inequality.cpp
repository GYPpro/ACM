#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI0 for (int i = 0; i < n; i++)
#define FI1 for (int i = 1; i <= n; i++)
#define pb push_back
#define fr first
#define se second

void sort(auto &x)
{
    sort(x.begin(), x.end());
};

using namespace std;

class solution
{
private:
public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n +1);
        FI1 cin >> arr[i];
        vector<vector<int>> bits(n +1);
        vector<vector<int>> XORbits(n +1, vector<int>(32));
        FI1
        {
            int MEX = 32;
            int t = arr[i];
            vector<int> tmp;
            while (t)
            {
                tmp.pb(t % 2);
                t >>= 1;
            }
            while (tmp.size() < MEX)
                tmp.pb(0);
            bits[i] = tmp;
        }

        // for (int i = 0; i < 32; i++)
        //     XORbits[0][i] = bits[0][i];
        // for (int i = 1; i < n; i++)
        FI1
            for (int j = 0; j < bits[i].size(); j++)
                XORbits[i][j] = XORbits[i - 1][j] ^ bits[i][j];
        
        vector<vector<int>> fcnt(n + 1, vector<int>(32));
        // vector<vector<int>> fcnt1(n,vector<int>(32));
        // vector<vector<int>> ecnt0(n,vector<int>(32));
        // vector<vector<int>> ecnt1(n,vector<int>(32));

        // int MEX = 32;
        // for (int i = 0; i < 32; i++)
        //     fcnt[0][i] = 1;

        // for (int i = 1; i < n; i++)
        FI1
            for (int j = 0; j < bits[i].size(); j++)
                fcnt[i][j] = fcnt[i - 1][j] + XORbits[i][j];

        int ans = 0;
        FI1
        {
            int t = 31;
            while (t >= 0)
            {
                if (bits[i][t] == 1)
                    break;
                t--;
            }
            if (t < 0)
                continue;

            // if(i > 0)
                // ans += fcnt[i][t] * (n - i - (fcnt[n - 1][t] - fcnt[i-1][t])); //left 1 right 0
                // ans += fcnt[i][t] * (fcnt[n][t] - fcnt[i][t]); //left 1 right 1
                ans += fcnt[i - 1][t] * (fcnt[n][t] - fcnt[i - 1][t]); //left 1 right 1
            // else 
            //     ans += fcnt[i][t] * (n - i - (fcnt[n - 1][t]));
            // if (i > 0)
                // ans += (n - i - (fcnt[n][t] - fcnt[i][t])) * (i - fcnt[i][t] + 1);//left 0 right 0
                ans += (n - i + 1 - (fcnt[n][t] - fcnt[i - 1][t])) * (i - fcnt[i - 1][t]);//left 0 right 0
            // else 
            //     ans += (fcnt[n - 1][t] - fcnt[i][t]) * (i - fcnt[i][t]);//left 0 right 1
        }
        cout << ans << "\n";
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