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

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int n,k,m;
        cin >> n >> k >> m;
        vector<int> a(n);
        for(auto &x:a) cin >> x;    
        map<int,vector<int>> gp;
        vector<int> ans(n);
        for(int i = 0;i < n;i ++) gp[a[i]].pb(i);
        for(auto x:gp) {
            auto tc = x.second;
            if(tc.size() %2 == 0) { //bin
                for(int i = 0;i < tc.size();i ++){
                    if(i %2 == 0) ans[tc[i]] = 0;
                    else ans[tc[i]] = m/n + ((m%n-1) >= tc[i]);
                }
            } else {
                for(int i = 0;i < tc.size();i ++){
                    if(i % 2 == 0) 
                        ans[tc[i]] = ((m/n)/2) + ((m%n-1) >= tc[i]&& ((m/n)%2 == 1)); // 
                    else
                        ans[tc[i]] = ((m/n +1)/2) + ((m%n-1) >= tc[i] && ((m/n)%2 != 1)); //
                }
            }
        }
        for(int i = 0;i < ans.size();i ++) cout << ans[i] << " \n"[i == ans.size()-1];
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