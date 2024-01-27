//拓扑排序
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

vector<vector<ll>> graph(50);


void bfs(queue<ll> &S,queue<ll> L,vector<ll> din,vector<ll> dout)
{
    ll q;
    q=S.front();
    S.pop();
    L.push(q);
    for(ll i=0;i<graph[q].size();i++)
    {
        din[graph[q][i]]--;
        if(din[graph[q][i]]==0) S.push(graph[q][i]);
    }
    return;
}

ll toposort(vector<ll> din,vector<ll> dout)
{
    queue<ll> S,L;
    for(ll i=1;i<=26;i++)
    {
        if(din[i]==-1&&dout[i]>0) S.push(i);//找到入度?0的点
    }
    while(S.size()>0)
    {
        bfs(S,L,din,dout);
    }
    ll ans=L.size();
    cout<<"拓扑排序\n";
    while(!L.empty())
    {
        cout<<L.front()<<" ";
        L.pop();
    }
    cout<<"\n";
    return ans;
}



void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> din(27,-1);
    vector<ll> dout(27,-1);
    // memset(din,-1,27*8);
    // memset(dout,-1,27*8);
    ll flag=0;

    for(ll i=0;i<m;i++)
    {
        string s;
        cin>>s;
        ll u,v;
        u=(ll)(s[0]-'A'+1);
        v=(ll)(s[2]-'A'+1);
        graph[u].push_back(v);
        if(din[v]==-1) din[v]++;
        din[v]++;//入度+1
        if(dout[u]==-1) dout[u]++;
        dout[u]++;//出度+1
            cout<<"邻接表\n";
            for(ll l=1;l<=n;l++)
            {
                for(ll j=0;j<graph[l].size();j++)
                cout<<graph[l][j]<<" ";
            }
            cout<<"\n";
        ll ans=toposort(din,dout);
        if(ans==n) flag=1;
            cout<<"序列长度\n";
        cout<<ans<<"\n";
    }
    
    // for(ll i=1;i<=n;i++)
    // {
    //     cout<<i<<" : ";
    //     for(ll j=0;j<graph[i].size();j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    // std::cout.tie(0);
    // std::cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // solution sl;
        solve();
    }

    system("pause");

    return 0;
}