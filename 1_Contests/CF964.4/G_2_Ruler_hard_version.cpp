// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

// vector<int> init(int n)
// {
//     vector<int> pri;
//     vector<bool> vis(n, 0);
//     for (int i = 2; i <= n; i++)
//     {
//         if (!vis[i])
//             pri.push_back(i);
//         for (int j = 0; j < pri.size(); j++)
//         {
//             if (i * pri[j] > n)
//                 break;
//             vis[pri[j] * i] = 1;
//             if (i % pri[j] == 0)
//                 break;
//         }
//     }
//     return pri;
// } vector<int> pri;

void solve()
{
    // for(auto x:pri) cout << x << " ";
    int l = 0,r = 1e3;
    // cout << "? " << f1 << " " << f2 <<"\n";
    // int x = 3;
    // cin >> x;
    while(r > l+1)
    {
        int f1 = l + (r-l)/3;
        int f2 = l + 2 * (r-l)/3;
        cout << "? " << f1 << " " << f2 <<"\n";
        int res;
        cin >> res;
        // res = (f1+(f1>=x)) * (f2+(f2 >= x));
        if(res == f1 * f2) l = f2;
        else if(res == (f1+1) * (f2+1)) r = f1;  
        else if(res == f1 * (f2+1)) l = f1,r = f2;
        // cout << l << " " << r << "\n";
    }
    cout << "! " << r << "\n";
    return;
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    // pri = init(1e3);
    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
