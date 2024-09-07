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
        int n;
        cin >> n;
        string s;
        cin >> s;
        n = s.size();
        int cntf = 0;
        lop(i,0,n){
            if(s[i] != '_') {
                cntf += s[i] == '(' ? 1:-1;
                continue;
            }
            if(cntf == 0) s[i] = '(';
            else s[i] = ')';
            cntf += s[i] == '(' ? 1:-1;
        }
        // cout << s << '\n';
        int costs = 0;
        cntf = 0;
        lop(i,0,n)
        {
            cntf += s[i] == '(' ? 1:-1;
            costs += cntf;
        }
        cout << costs << "\n";
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

//_(_)_(_)
/*
_(_)_(_)
(())(())
_)_)_)_)
()()()()
*/