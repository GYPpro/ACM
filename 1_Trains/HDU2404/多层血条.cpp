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
        int n,m,hp,dmg;
        cin >> n >> m >> hp >> dmg;
        cout << "+";
        lop(i,0,m) cout << "-";
        cout << "+\n";
        int basic = (hp)/m;
        // if(basic == 0) basic = 1;
        string s = "ABCDE";
        char biscc = s[(basic-1)%5];
        while(n--)
        {
            cout << "|";
            lop(i,0,m)
            {
                if(basic * m + (i+1) <= hp)
                    if(basic * m + (i+1) >= hp-dmg+1) cout << ".";
                    else cout << s[(basic)%5];
                else if(basic == 0) cout << " "; 
                else if((basic-1) * + (i+1) <= hp) 
                    if((basic-1) * m + (i+1) >= hp-dmg+1) cout << ".";
                    else cout << s[(basic-1)%5];
                else cout << " ";
            }
            cout << "|\n";
        }
        cout << "+";
        lop(i,0,m) cout << "-";
        cout << "+\n";
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