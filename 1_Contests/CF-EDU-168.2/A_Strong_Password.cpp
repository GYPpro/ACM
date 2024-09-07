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
        string s;
        cin >> s;
        int n = s.size();
        lop(i,0,n-1) if(s[i] == s[i+1])
        {
            string ans;
            lop(j,0,i+1) ans.pb(s[j]);
            ans.pb('a'+((s[i]+1)%26));
            lop(j,i+1,n) ans.pb(s[j]);
            cout << ans << "\n";
            return;
        }
        cout << s << (char)('a'+(s[s.size()-1]+1) % ('z'-'a')) << "\n";
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