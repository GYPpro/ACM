#define _USE_IOSTREAM_
// #define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define nullmst 1145141919810

using namespace std;

class Mst{
public:
    int l,r;
    int df,atk;
};

void solve()
{
    int n;
    cin >> n;
    vector<Mst> mst(n);
    for(int i = 0;i < n;i ++) cin >> mst[i].atk;  
    for(int i = 0;i < n;i ++) cin >> mst[i].df;  
    mst[0].r = 1;
    mst[n-1].l = n-2;
    mst[0].l = nullmst;
    mst[n-1].r = nullmst;
    for(int i = 1;i < n-1;i ++)
    {
        mst[i].l = i-1;
        mst[i].r = i+1;
    }
    set<int> effLis;
    for(int i = 0;i < n;i ++) effLis.insert(i);
    for(int t = 0;t < n;t ++)
    {
        set<int> deadLis;
        for(auto x:effLis)
        {
            if(x == nullmst) continue;
            int dmg = 0;
            if(mst[x].l != nullmst) dmg += mst[mst[x].l].atk;
            if(mst[x].r != nullmst) dmg += mst[mst[x].r].atk;
            if(dmg > mst[x].df) {
                deadLis.insert(x);
                // if(mst[x].l != nullmst) mst[mst[x].l].r = mst[x].r;
                // if(mst[x].r != nullmst) mst[mst[x].r].l = mst[x].l;
            }
        }
        cout << deadLis.size() << " ";
        vector<int> deadArr;
        for(auto x:deadLis) deadArr.push_back(x);
        sort(deadArr.begin(),deadArr.end());
        for(auto x:deadArr)
        {
            if(mst[x].r != nullmst) mst[mst[x].r].l = mst[x].l;
            if(mst[x].l != nullmst) mst[mst[x].l].r = mst[x].r;
        }
        effLis.clear();
        for(auto x:deadLis){
            effLis.insert(mst[x].r);
            effLis.insert(mst[x].l);
        }
        for(auto x:deadLis) effLis.erase(x);
    }
    cout << "\n";
}

#define _WITH_T_

signed main()
{
    #ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #endif
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// void solve()
// {
// 	int n;
// 	cin>>n;
// 	vector<int>a(n+5,0),b(n+5,2e9+10);
// 	for(int i=1;i<=n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		cin>>b[i];
// 	}
// 	vector<int>pre(n+5,0),nxt(n+5,n+1);
// 	for(int i=1;i<=n;i++)
// 	{
// 		pre[i]=i-1;
// 		nxt[i]=i+1;
// 	}
// 	vector<int>vis(n+5,0);
// 	queue<pair<int,int>>q;
// 	vector<int>ans(n+5,0);
// 	vector<int>hurt(n+5,0);
// 	for(int i=1;i<=n;i++)
// 	{
// 		hurt[pre[i]]+=a[i];
// 		hurt[nxt[i]]+=a[i];
// 	}
// 	vis[0]=1;
// 	vis[n+1]=1;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(hurt[i]>b[i])
// 		{
// 			ans[1]++,q.push({i,1});
// 			nxt[pre[i]]=nxt[i];
// 			pre[nxt[i]]=pre[i];
// 			vis[i]=1;
// 		}
// 	}
// 	while(!q.empty())
// 	{
// 		pair<int,int>p=q.front();
// 		q.pop();
		
// 		if(!vis[pre[p.first]])
// 		{
// 			int x=pre[p.first],y=nxt[x];
// 			int hurtx=a[pre[x]]+a[y];
// 			if(hurtx>b[x])
// 			{
// 				q.push({x,p.second+1});
// 				vis[x]=1;
// 				ans[p.second+1]++;
// 				nxt[pre[x]]=nxt[x];
// 		        pre[nxt[x]]=pre[x];

// 			}
// 			if(y>n)continue;
// 			int hurty=a[pre[y]]+a[nxt[y]];
// 			if(hurty>b[y])
// 			{
// 				q.push({y,p.second+1});
// 				vis[y]=1;
// 				ans[p.second+1]++;
// 				nxt[pre[y]]=nxt[y];
// 		        pre[nxt[y]]=pre[y];

// 			}

// 		}
// 		else if(!vis[nxt[p.first]])
// 		{
// 			int x=nxt[p.first],y=pre[x];
// 			int hurtx=a[nxt[x]]+a[y];
// 			if(hurtx>b[x])
// 			{
// 				vis[x]=1;
// 				q.push({x,p.second+1});
// 				ans[p.second+1]++;
// 				nxt[pre[x]]=nxt[x];
// 		        pre[nxt[x]]=pre[x];

// 			}
// 			if(y<1)continue;
// 			int hurty=a[x]+a[nxt[y]];
// 			if(hurty>b[y])
// 			{
// 				vis[y]=1;
// 				q.push({y,p.second+1});
// 				ans[p.second+1]++;
// 				nxt[pre[y]]=nxt[y];
// 		        pre[nxt[y]]=pre[y];
// 			}

// 		}
// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		cout<<ans[i]<<" \n"[i==n];
// 	}
// }
// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while(t--)
// 		solve();
// 	return 0;
// }