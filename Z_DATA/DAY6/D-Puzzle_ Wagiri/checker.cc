#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int n,m;
map<pair<int,int>,int> edges,rec;
const string YES = "YES";
const string NO = "NO";
const int lim=1e9;
int readAndCheckAnswer(InStream& in)
{
	string tans = upperCase(in.readToken("[A-Za-z]*","yesno"));

	if (tans != YES && tans != NO)
		in.quitf(_wa, "%s or %s expected in answer, but %s found.",YES.c_str(), NO.c_str(), compress(tans).c_str());
	if(tans==NO)return -1;
	edges=rec;
	vector<vector<int>> G(n+5);
	vector<pair<int,int>> lun,qie;
	int rm=in.readInt(0,m,"m'");
	in.seekEoln();
	for(int i=1;i<=rm;i++)
	{
		int u=in.readInt(1,n,"u_i");in.readSpace();
		int v=in.readInt(1,n,"v_i");
		in.seekEoln();
		if(edges.find({u,v})==edges.end())in.quitf(_wa,"Edge %d-%d does not appear in the original graph.",u,v);
		int w=edges[{u,v}];
		edges.erase({u,v});edges.erase({v,u});
		if(w)
		{
			lun.emplace_back(u,v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		else qie.emplace_back(u,v);
	}
	in.seekEof();
	in.readEof();
	
	
	vector<int> dfn(n+5),low(n+5),ins(n+5),bel(n+5);
	int bccnt=0,ind=0;
	stack<int> s;
	function<void(int,int)> dfs=[&](int u,int pa)
	{
		dfn[u]=low[u]=++ind;
		s.push(u);
		ins[u]=1;
		for(auto v:G[u])
		{
			if(v==pa)continue;
			if(not ins[v])
			{
				dfs(v,u);
				low[u]=min(low[u],low[v]);
			}
			else if(ins[v]==1)
			{
				low[u]=min(low[u],dfn[v]);
			}
		}
		if(dfn[u]==low[u])
		{
			int vv;
			++bccnt;
			do
			{
				vv=s.top();s.pop();
				ins[vv]=2;
				bel[vv]=bccnt;
			}
			while(vv!=u);
		}
	};
	for(int i=1;i<=n;i++)
	{
		if(not ins[i])
		{
			dfs(i,0);
		}
	}
	for(auto [u,v]:lun)
	{
		if(bel[u]!=bel[v]) in.quitf(_wa,"Lun edge not on any cycle.");
	}
	vector<int> pa(bccnt+5);
	function<int(int)> find=[&](int x){return pa[x]?pa[x]=find(pa[x]):x;};
	int tot=bccnt;
	for(auto [u,v]:qie)
	{
		int pu=find(bel[u]),pv=find(bel[v]);
		if(pu!=pv)
		{
			pa[pv]=pu;
			tot--;
		}
		else in.quitf(_wa,"Qie edge on a cycle.");
	}
	if(tot>1)in.quitf(_wa,"Not connected.");
	return 1;
}
int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);

	n = inf.readInt();
	m = inf.readInt();
	for(int i=1;i<=m;i++)
	{
		int u=inf.readInt();
		int v=inf.readInt();
		int ty=(inf.readToken()=="Lun");
		edges[{u,v}]=ty;
		edges[{v,u}]=ty;
	}
	rec=edges;
	int anso=readAndCheckAnswer(ouf);
	int ansa=readAndCheckAnswer(ans);
	if(anso>ansa)quitf(_fail,"Participant has answer but jury has not.");
	else if(anso<ansa)quitf(_wa,"Jury has answer but participant has not.");
	quitf(_ok, "Correct.");
}
