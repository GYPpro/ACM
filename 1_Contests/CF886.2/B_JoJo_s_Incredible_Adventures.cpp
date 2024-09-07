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
        s = s+s;
        int maxcnj1 = 0;
        int presumcnj = 0;
        lop(i,0,s.size())
        {
            if(s[i] == '1'){
                presumcnj ++;
                maxcnj1 = max(maxcnj1,presumcnj);
            } else presumcnj = 0;
        }
        maxcnj1 = max(maxcnj1,presumcnj);
        // cout << maxcnj1 << "\n";
        if(maxcnj1 == s.size()) cout << (s.size()/2)*(s.size()/2)<< "\n";
        else cout << ((maxcnj1+1)/2)*((maxcnj1+2)/2) << "\n";
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