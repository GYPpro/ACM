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
        int n,a,b;
        cin >> n >> a >> b;
        a --,b --;
        vector<int> ans (n,1);
        for(int i = a;i <= b;i ++) ans[i] = 1;
        for(int k = a,i = 0;k + i < n;i ++) ans[i+k] = i%2?-1:1;
        for(int k = b,i = 0;k - i >= 0;i ++) ans[k-i] = i%2?-1:1;
        // int f;
        // b --;
        // if(a < b) f = 1; //先取极大值
        // else f = 0; //先取极小值
        // for(int i = 0;i < n;i ++)
        // {
        //     if(i == a || i == b) f = !f;
        //     ans[i] = f?1:-1;
        // }
        // vector<int> prf(1,ans[0]);
        // for(int i = 1;i < n;i ++) prf.pb(prf[i-1]+ans[i]);
        // // for(auto x:prf) cout << x << " ";cout << "\n";
        // vector<int> sef(n,ans[n-1]);
        // for(int i = n-2;i >= 0;i --) sef[i] = sef[i+1]+ans[i];
        // // for(auto x:sef) cout << x << " ";cout << "\n";
        // int maxprf = -1145141919810LL;
        // for(auto x:prf) maxprf = max(maxprf,x);
        // int maxsef =-1145141919810LL;
        // for(auto x:sef) maxsef = max(maxsef,x);
        // int xa = 0;
        // for(;xa < n;xa ++) if(prf[xa] == maxprf) break;
        // int xb = n-1;
        // for(;xb >= 0;xb --) if(sef[xb] == maxsef) break;
        // cout << xa << " " << xb << "\n";
        // if(xa+1 == a && xb == b)
          
          for(auto x:ans) cout << x << " ";cout << "\n";
        // else cout << -1 << "\n";
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