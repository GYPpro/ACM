#include<iostream>
#include<cmath>
#include<math.h>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>

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
    cin>>n;
    vector<ll> du(n+1,0);
    ll num=0;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        du[u]++;
        du[v]++;
        if(du[u]==2) num++;
        if(du[v]==2) num++;
    }
    if(n == 2){cout << "Bob\n";return;}
    if(num%2==0) cout<<"Alice\n";
    else cout<<"Bob\n";
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
    // system("pause");
}