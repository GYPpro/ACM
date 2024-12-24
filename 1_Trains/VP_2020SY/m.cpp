#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll qsm(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int num=0;
    vector<string>s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }
    for(int j=1;j<=m;j++)
    {
        ll A=0,B=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i][j]=='A')A++;
            else B++;
        }
        num+=A*B>=k;
    }
    cout<<qsm(2,m)-qsm(2,m-num);
    

    return 0;
}