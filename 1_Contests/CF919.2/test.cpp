#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define N 100005
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 2);
    bool vis[10050] = {0};
    ll d[10050] = {0}; // 将每个节点的入度初始化为零
    queue<ll> q;
    ll head, len, tail;
    for (ll i = 1; i <= n; i++)
    {
        cin >> head >> len;
        while (1)
        {
            cin >> tail;
            if (tail == 0)
                break;
            g[tail].push_back(head);
            d[head]++; // 点next的入度+1
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    ll t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
    // system("pause");
}