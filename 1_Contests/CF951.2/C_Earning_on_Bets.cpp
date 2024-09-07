#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

// #define map unordered_map
// #define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lca(int a,int b) {
    return a * b / gcd(a,b);
}
using namespace std;

class solution
{
private:
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> k(n);
        FI cin >> k[i];
        // auto factor = [&](int N) -> vector<int>  {
        //     vector<int> result;
        //     for (int i = 2; i * i <= N; i++) {
        //         if (N % i == 0) {  // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
        //         while (N % i == 0) {N /= i;result.push_back(i);}
        //         result.push_back(i);
        //         }
        //     }
        //     if (N != 1) {  // 说明再经过操作之后 N 留下了一个素数
        //         result.push_back(N);
        //     }
        //     return result;
        // };
        // map<int,int> factcnt;
        // for(auto x:k)
        // {
        //     auto rt = factor(x);
        //     map<int,int>tmpcnt;
        //     for(auto y:rt) tmpcnt[y] ++;
        //     for(auto y:tmpcnt) factcnt[y.first] = max(factcnt[y.first],y.second);
        // }
        // int MEX = 1;
        // for(auto x:factcnt){
        //     MEX *= binpow(x.first,x.second);
        // }
        // // cout << MEX << "\n";
        // vector<int> ans;
        // for(auto x:k) ans.pb(MEX/x);
        // int sum = 0;
        // for(auto x:ans) sum += x;
        int MEX = 1;
        for(auto x:k) MEX = lca(MEX,x);
        vector<int> ans;
        for(auto x:k) ans.pb(MEX/x);
        int sum = 0;
        for(auto x:ans) sum += x;
        if(sum >= MEX) cout << "-1\n";
        else {
            for(auto x:ans ) cout << x << "  ";
            cout << "\n"; 
        } 
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