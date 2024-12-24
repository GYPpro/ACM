#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int>stk;
    stk.push_back(n+1);
    vector<pair<int,int>>ans;
    vector<int>mn=a;
    for(int i=n-1;i>=1;i--)
    {
        mn[i]=min(mn[i+1],mn[i]);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<mn[i]<<" \n"[i==n];
    // }
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(mn.begin()+i+1,mn.end(),a[i])-mn.begin()-1;
        ans.push_back({i,id});
    }
    // for(auto [l,r]:ans)
    // {
    //     cout<<l<<' '<<r<<'\n';
    // }
    //reverse(ans.begin(),ans.end());
    int cnt=0;
    int r=ans[0].second;
    for(int i=1;i<n;i++)
    {
        if(r>=ans[i].first)
        {
            r=max(r,ans[i].second);
        }
        else 
        {
            cnt++;
            r=ans[i].second;
        }
    }
    cnt++;
    cout<<cnt<<'\n';
    return 0;
}