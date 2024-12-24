#include <bits/stdc++.h>
#include "testlib.h"
#define MAXN 1005
#define INF 1000000000
 
using namespace std;
 
int n,m,k;
vector<int> rG[MAXN];
int ideg[MAXN],odeg[MAXN];
int ja[MAXN],pa[MAXN];
int dp[MAXN];
bool marked[MAXN];
vector<int> readAndCheckAnswer(InStream& in) {
    vector<int> ret; 
    int x=in.readInt(-1,n,"x");
    ret.push_back(x);
    // printf("x=%d\n",x);
	if (x==-1) {ret.push_back(x); return ret;}
    memset(marked,false,sizeof(marked));
    memset(dp,0,sizeof(dp));
    set<int> s;
    for(int i=0;i<x;i++){
        int v=in.readInt(1,n,"v");
        if(!odeg[v]) in.quitf(_wa,"cannot choose sink vertices");
        if(!ideg[v]) in.quitf(_wa,"cannot choose source vertices");
        if(s.count(v)) in.quitf(_wa, "repeated vertices");
        s.insert(v); ret.push_back(v);
        marked[v]=true;
    }
    int ans=INF;
    for(int i=1;i<=n;i++){
        dp[i]=INF;
        if(!ideg[i]) {dp[i]=0; continue;}
        for(auto to:rG[i]){
            dp[i]=min(dp[i],dp[to]);
        }
        if(marked[i]) dp[i]++;
        if(!odeg[i]) ans=min(ans,dp[i]);
    }
    if(ans<k) in.quitf(_wa,"there exists a path with less than k elites");
    // puts("done2");
	return ret;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	n = inf.readInt(); m = inf.readInt(); k = inf.readInt();
    inf.readEoln();
    for(int i=0;i<m;i++){
        int u,v;
        u=inf.readInt(); v=inf.readInt(); inf.readEoln();
        ideg[v]++; odeg[u]++;
        rG[v].push_back(u);
    }
    vector<int> ja = readAndCheckAnswer(ans);
    vector<int> pa = readAndCheckAnswer(ouf);
    assert(ja.size()>=1);
    assert(pa.size()>=1);
    if(ja[0] != -1 && pa[0] == -1)
        quitf(_wa, "Jury has the answer but participant has not");
    if(ja[0] == -1 && pa[0] != -1)
        quitf(_fail, "Participant has the answer but jury has not");
    if(ja[0]<pa[0]){
        quitf(_wa, "Jury has better assignment");
    }
    else if(ja[0]<pa[0]){
        quitf(_fail, "Participant has better assignment");
    }
    quitf(_ok, "n=%d", n);
}
