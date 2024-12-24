#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int n,k;
map<pair<int,int>,int> edges,rec;
const string YES = "YES";
const string NO = "NO";
const double lim=1e6,eps=1e-6;
typedef double db;
struct point
{
	db x,y;
	point operator+(const point &p)const{return {x+p.x,y+p.y};}
	point operator-(const point &p)const{return {x-p.x,y-p.y};}
	friend istream& operator>>(istream &is,point &p){is>>p.x>>p.y;return is;}
	friend ostream& operator<<(ostream &os,const point &p){os<<p.x<<' '<<p.y;return os;}
	point operator*(const db k1)const{return {x*k1,y*k1};}
	point operator/(const db k1)const{return {x/k1,y/k1};}
	db abs()const{return hypot(x,y);}
	db dis(const point &k1)const{return ((*this)-k1).abs();}
};
int readAndCheckAnswer(InStream& in)
{
	string tans = upperCase(in.readToken());

	if (tans != YES && tans != NO)
		in.quitf(_wa, "%s or %s expected in answer, but %s found.",YES.c_str(), NO.c_str(), compress(tans).c_str());
	if(tans==NO)return -1;
	
	vector<point> p(n+5);
	for(int i=1;i<=n;i++)
	{
		double x=in.readDouble(-lim,lim,"x_i");in.readSpace();
		double y=in.readDouble(-lim,lim,"y_i");
		in.seekEoln();
		p[i]={x,y};
	}
	in.seekEof();
	in.readEof();
	
	vector<double> mindis(n+5,lim*10);
	vector<int> cnt(n+5);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double dis=p[i].dis(p[j]);
			if(dis<=eps)in.quitf(_wa,"Points %d and %d collide.",i,j);
			mindis[i]=min(mindis[i],dis);
			mindis[j]=min(mindis[j],dis);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double dis=p[i].dis(p[j]);
			if(dis<=mindis[i]*(1+eps) and dis<=mindis[j]*(1+eps))
			{
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]!=k)
			in.quitf(_wa,"Point %d in %d good pairs.",i,cnt[i]);
	}
	
	return 1;
}
int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);

	n = inf.readInt();
	k = inf.readInt();
	int anso=readAndCheckAnswer(ouf);
	int ansa=readAndCheckAnswer(ans);
	if(anso>ansa)quitf(_fail,"Participant has answer but jury has not.");
	else if(anso<ansa)quitf(_wa,"Jury has answer but participant has not.");
	quitf(_ok, "Correct.");
}
