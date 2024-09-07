#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

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

using namespace std;


int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd (a, b) * b;
}

void sort(auto &x)
{
    sort(x.begin(),x.end());
};

    int T = 1;

vector<int> init( int n)
{
    vector<int> pri;
    vector<bool> vis(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    return pri;
}
vector<int> pri;
class solution
{
private:

public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        FI cin >> arr[i];
        sort(arr);

        // if(T == 318-64){ cout << n;for(auto x:arr) cout << x << "-";cout << "\n";return;}

        if(n == 1) {cout << 0 << "\n";return;}
        int t = arr[0];
        for(int i = 1;i < n;i ++)
        {
            t = lcm(t,arr[i]);
            if(t > 1e9) break;
        }
        int MEX = -1;
        for(int i = 0;i < n;i ++)
        {
            if(arr[i] == t) {MEX = i;break;}
        }
        if(MEX == -1){cout << n << "\n";return;}

        vector<vector<int>> factor;
        auto fac = [&](int N) -> vector<int> {
            vector<int> result;
            for (int i = 2; i * i <= N; i++) {
                if (N % i == 0) {  // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
                while (N % i == 0){ N /= i;
                result.push_back(i);}
                }
            }
            if (N != 1) {  // 说明再经过操作之后 N 留下了一个素数
                result.push_back(N);
            }
            return result;
        };
        // for (auto x : arr)
        //     cout << x << " ";
        // cout << "\n";

        for(int i = 0;i < n;i ++)
        {
            factor.pb(fac(arr[i]));
        }

        // cout <<t << " " << MEX <<  "---\n";
        // for(auto x:factor){
        //     for(auto y:x)
        //         cout << y << " ";cout << "\n";}
        // cout << "-\n";

        int top = 0;
        for(int i = 0;i < n;i ++)
        {
            top = max(top,(int)factor[i].size());
        }

        for(int i = 0;i < n;i ++)
        {
            vector<int> pushf(factor[MEX].size());
            int p1 = 0,p2 = 0;
            while(p2 < factor[MEX].size() && p1 < factor[i].size())
            {
                if(factor[MEX][p2] == factor[i][p1])
                {
                    // pushf.pb(factor[i][p1]);
                    pushf[p2] = factor[i][p1];
                    p1 ++;
                    p2 ++;
                } else {
                    p2 ++;
                }
            }
            // if(p1 < factor[i].size()) cout << "error\n";
            // if(factor[i].size() > factor[MEX].size()) cout << "error\n";
            // if(p2 < factor[MEX].size()) cout << "error\n";
            factor[i] = pushf;
        }

        vector<int> cnt(top,0);
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < factor[i].size();j ++)
            {
                if(factor[i][j] == 0) continue;
                cnt[j] ++;
            }
        }
        // for(auto x:factor){
        //     for(auto y:x)
        //         cout << y << "\t";cout << "\n";}
        // cout << "\n";
        // for(auto x:cnt) cout << x << " ";cout << "\n";
        
        vector<pair<int,int>> pq;
        for(int i = 0;i < top;i ++)
        {
            pq.pb({n-cnt[i],i});
        }
        sort(pq);
        int atc = 0;
        auto check = [&](vector<int> ttf) -> bool{
            int t = 1;
            // cout << "begin check:\n";
            // for(auto x:ttf) cout << x << " ";cout << "\n";
            bool forcecmp = 0;
            FI
            {
                // if (factor[i][ttf] == 0) t = lcm(t,arr[i]);
                int act = 1;
                for(int j = 0;j < ttf.size();j ++)
                {
                    if(factor[i][ttf[j]] == 0) continue;
                    else {act = 0;break;}
                }
                if(act) {atc ++;t = lcm(t,arr[i]);}
                if(t > 1e9) forcecmp = 1;
                // cout << "checking:" << "at:" << i << " " << t << "\n";
            }
            if(forcecmp) return 1;
            FI if(arr[i] == t) return 0;
            return 1;
        };
        int ans = 0;
        int rp = 1<<(top);
        for(int i = 0;i < rp;i ++)
        {
            vector<int> ttf(top,0);
            for(int j = 0;j < top;j ++)
            {
                if(i & (1<<j)) ttf[j] = 1;
            }
            // cout << "check:" << ttf << "\n";
            vector<int> tocheck;
            for(int i = 0;i < top;i ++)
            {
                if(ttf[i]) tocheck.pb(i);
            }
            atc =0;
            // cout << "check:" << i << "\n";
            // for(auto x:tocheck) cout << x << " ";cout << "\n";
            if(check(tocheck)) ans = max(ans,atc);
            // cout << "resault:" << check(tocheck) << "and atc:" << atc << "\n";
        }
        // for(int i = pq.size()-1;i >= 0;i --)
        // {
        //     auto x = pq[i];
        //     // cout << "check " << x.se << ":" << check(x.se) << "\n";
        //     if(check(x.se)) {cout << x.fi << "\n";return;}
        //     // pq.pop();
        // }
        cout << ans << "\n";
        // cout  << 0 << "\n";
    }
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    cin >> T;
    pri = init(100030);

    while(T--)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}