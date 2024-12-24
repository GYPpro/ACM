#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int a[1'000'003];
signed main(int argc,char *argv[])
{
	registerTestlibCmd(argc,argv);
	int T=inf.readInt();
	for(int tc=1; tc<=T; ++tc)
	{
	    // setTestCase(tc);
		int n=inf.readInt(1,1'000'000,"n"),m=inf.readInt(0,n,"m");
		if(m==n-2)
		{
			int x=ouf.readInt(-1,n,"a[i]");
			int y=ans.readInt(-1,n,"a[i]");
			if(x!=-1) quitf(_wa,"Wrong answer on (%d,%d): cnt!=m",n,m);
			if(y!=-1) quitf(_fail,"std failed on (%d,%d): cnt!=m",n,m);
			continue;
		}
		int c=0;
		for(int i=1; i<=n; ++i)
			a[i]=ouf.readInt(-1,n,"a[i]");
		for(int i=2; i<n; ++i)
		{
			int x=a[i-1],y=a[i],z=a[i+1];
			if(x+y>z&&x+z>y&&y+z>x) ++c;
		}
		if(c!=m) quitf(_wa,"Wrong answer on (%d,%d): cnt!=m",n,m);
		sort(a+1,a+n+1),c=0;
		for(int i=1; i<=n; ++i) c|=(a[i]!=i);
		if(c) quitf(_wa,"Wrong answer on (%d,%d): not a perm",n,m);
		for(int i=1; i<=n; ++i)
			a[i]=ans.readInt(-1,n,"a[i]");
		for(int i=2; i<n; ++i)
		{
			int x=a[i-1],y=a[i],z=a[i+1];
			if(x+y>z&&x+z>y&&y+z>x) ++c;
		}
		if(c!=m) quitf(_fail,"std failed on (%d,%d): cnt!=m",n,m);
		sort(a+1,a+n+1),c=0;
		for(int i=1; i<=n; ++i) c|=(a[i]!=i);
		if(c) quitf(_wa,"std failed on (%d,%d): not a perm",n,m);
	}
	quitf(_ok,"Haitang suki");
	return 0;
}