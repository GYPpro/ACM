    #include <iostream>
    #include <stdlib.h>
    #include <math.h>
    #include <algorithm>
    #include <string>
    #include <string.h>
    #include <vector>

    #define map unordered_map
    #define set unordered_set

    #include <map>
    #include <set>
    #pragma GCC optimize(3)

    #define int long long
    #define FI for (int i = 0; i < n; i++)
    #define pb push_back
    #define fi first
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
            string s;
            cin >> s;
            map<char,vector<int>> rcnt;

            int n = s.size();
            rcnt['9'] = vector<int>(n+1);
            rcnt['6'] = vector<int>(n+1);
            rcnt['8'] = vector<int>(n+1);
            rcnt['0'] = vector<int>(n+1);
            map<char,char> gteq = {
                {'6','9'},
                {'9','6'},
                {'0','0'},
                {'8','8'}
            };
            for(int i = n-1;i >= 0;i --){
                for(auto x:rcnt) rcnt[x.first][i] = rcnt[x.first][i+1];
                rcnt[s[i]][i] = rcnt[s[i]][i+1]+1;
            }
            int dict = 0;
            for(int i = 0;i < n;i ++) {
                dict += rcnt[gteq[s[i]]][i];
            }
            cout << n *(n+1LL)/2LL-dict+1LL << "\n";
            return;
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
        return 0;
    }