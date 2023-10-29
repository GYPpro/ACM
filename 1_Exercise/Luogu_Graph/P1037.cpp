#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

#define ll long long
#define N 100005

using namespace std;

inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

void dfs(ll n, ll m, vector<ll> &vis, vector<ll> &times, vector<vector<ll>> &arr)
{
    vis[n]=1;
    for (ll j = 0; j < arr[m].size(); j++)
    {
        if (!vis[arr[m][j]]&&arr[m][j]!=0)
        {
            vis[arr[m][j]] = 1;
            times[n]++;
            dfs(n, arr[m][j], vis, times, arr);
        }
        else
            continue;
    }
    return;
}

void solve()
{
    string n;
    ll k;
    cin >> n >> k;
    vector<vector<ll>> arr(15);
    vector<ll> times;
    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    for (ll i = 0; i < 10; i++)
    {
        times.push_back(1);
    }
    for (ll i = 0; i < 10; i++)
    {
        vector<ll> vis;
        for (ll i = 0; i < 10; i++)
        {
            vis.push_back(0);
        }
        dfs(i, i, vis, times, arr);
    }
    // ll ans=1;
    __int128 ans = 1;
    for (ll i = 0; i < n.size(); i++)
    {
        ans *= times[n[i] - '0'];
    }
    // for(ll i=0;i<10;i++)
    // {
    //     cout<<times[i]<<" ";
    // }
    // cout<<endl;
    print(ans);
    // cout<<ans<<endl;
    cout<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
        solve();
    system("pause");
}