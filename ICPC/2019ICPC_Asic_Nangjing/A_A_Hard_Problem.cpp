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

vector<int> pri;

vector<int> init(int n)
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

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    // for(int i = 2;i * i <= n;i ++)
    // {
    //     if(n%i == 0)
    //     {
    //         sum ++;
    //         while(n%i == 0) n /= i;
    //     }
    // }
    // sum += (n != 1);
    // auto euler_phi = [&](int n)-> int{
    // int m = (int)(sqrt(n + 0.5));
    // int ans = n;
    // for (int i = 2; i <= m; i++)
    //     if (n % i == 0) {
    //     ans = ans / i * (i - 1);
    //     while (n % i == 0) n /= i;
    //     }
    // if (n > 1) ans = ans / n * (n - 1);
    // return ans;
    // };
    // cout << sum+1 << "\n";
    cout << n-(n/2) +1 << "\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    // pri = init(1e9+7);

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
