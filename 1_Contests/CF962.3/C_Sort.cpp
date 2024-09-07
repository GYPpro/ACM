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
        int n,q;
        cin >> n >> q;
        string a,b;
        cin >> a >> b;
        map<char,vector<int>> cnta;
        map<char,vector<int>> cntb;
        // int c[3.3];
        for(int i = 'a';i <= 'z';i ++)
        {
            cnta[i] = vector<int>(n+1);
            cntb[i] = vector<int>(n+1);
        }
        lop(i,0,n)
        {
            cnta[a[i]][i+1] = cnta[a[i]][i]+1;
            cntb[b[i]][i+1] = cntb[b[i]][i]+1;
            for(int j = 'a';j <= 'z';j ++)
            {
                if(j != a[i])
                    cnta[j][i+1] = cnta[j][i];
                if(j != b[i])
                    cntb[j][i+1] = cntb[j][i];
            }
        }
        //for x in xxx:
        // for(auto x:cnta)
        
        auto xx = cnta.begin();
        // {
        //     cout << (char)x.fi << " ";
        //     for(auto y:x.se)
        //         cout << y << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
        // for(auto x:cntb)
        // {
        //     cout << (char)x.fi << " ";
        //     for(auto y:x.se)
        //         cout << y << " ";
        //     cout << "\n";
        // }
        // cout << "\n";

        while(q--)
        {
            int l,r;
            cin >> l >> r;
            int sum = 0;
            for(int i = 'a';i <= 'z';i ++)
            {
                sum += abs(cnta[i][r]-cnta[i][l-1]-(cntb[i][r]-cntb[i][l-1]));
            }
            cout << sum/2 << "\n";
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

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}