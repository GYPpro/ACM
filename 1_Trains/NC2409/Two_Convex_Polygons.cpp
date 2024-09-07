#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =1e6+100;
#define double long double

#define pi acos(-1)

struct node
{
    double x,y;
}p[N],sta[N];

int i,j,k,m,n,o,top;
double ans,jl,js;

double multi(node p1,node p2, node p0)
{
    double x1=p1.x-p0.x;
    double y1=p1.y-p0.y; 

    double x2=p2.x-p0.x;
    double y2=p2.y-p0.y;

    return(x1*y2-x2*y1); 
}//计算叉积 

double dis(node p1,node p2)
{
    return (double)((p1.x-p2.x)*(p1.x-p2.x))+(double)((p1.y-p2.y)*(p1.y-p2.y));
}//计算任意两点间距离 

bool cmp(node p1,node p2)
{
    double tt=multi(p1,p2,p[1]);
    if(tt<0)return(0);
    if(tt==0 && dis(p1,p[1])>dis(p2,p[1]))return(0);
    return(1);
}

void graham()
{
    sort(p+2,p+n+1,cmp);
    for(int i=1;i<=2;i++)sta[i]=p[i];
    top=2;
    n++;p[n]=p[1];

    for(int i=3;i<=n;i++)
    {
        while(top>1 && multi(sta[top],p[i],sta[top-1])<=0)top--;
        top++;
        sta[top]=p[i];

    }
}

double dis(int x,int y,int a,int b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
struct Point
{
    int x, y;
    bool operator < (const Point& _P) const
    {
        return y<_P.y||(y==_P.y&&x<_P.x);
    };
}pset[N],ch[N];
int cross(Point a,Point b,Point o)      
{
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
int dist2(Point a,Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void convex_hull(Point *p,Point *ch,int n,int &len)
{
    sort(p, p+n);
    ch[0]=p[0];
    ch[1]=p[1];
    int top=1;
    for(int i=2;i<n;i++)
    {
        while(top>0&&cross(ch[top],p[i],ch[top-1])<=0)
            top--;
        ch[++top]=p[i];
    }
    int tmp=top;
    for(int i=n-2;i>=0;i--)
    {
        while(top>tmp&&cross(ch[top],p[i],ch[top-1])<=0)
            top--;
        ch[++top]=p[i];
    }
    len=top;    
}

int rotating_calipers(Point *ch,int n)
{
    int q=1,ans=0;
    ch[n]=ch[0];
    for(int p=0;p<n;p++)
    {
        while(cross(ch[p+1],ch[q+1],ch[p])>cross(ch[p+1],ch[q],ch[p]))
            q=(q+1)%n;
        ans=max(ans,max(dist2(ch[p],ch[q]),dist2(ch[p+1],ch[q+1])));            
    }
    return ans; 
}

void solve(){
    cin>>n;
    double c=0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    for(int i=0;i<n;i++){
        int j=(i-1+n)%n;
        c+=dis(a[i],b[i],a[j],b[j]);
    }
    cin>>n;

    int len;
    for(int i = 0;i < n;i ++)
    {
        cin >> pset[i].x >> pset[i].y;
    }

        convex_hull(pset,ch,n,len);

    // for(int i=1;i<=n;i++){
    //     cin>>p[i].x>>p[i].y;
    //     if(p[i].y<p[1].y ||(p[i].y==p[1].y && p[i].x<p[1].x))
    //     {
    //         node t=p[1];p[1]=p[i];p[i]=t;
    //     }
    // }
    // top=0;//记录凸包上点的个数 
    // graham();
    // top--;//sta中存储了top+1个点，第top+1个和第一个相同 

    // j=2;ans=0;
    // for(int i=1;i<top;i++)
    // {
    //     while(fabs(multi(sta[i],sta[i+1],sta[j]))<fabs(multi(sta[i],sta[i+1],sta[j+1])))
    //     {
    //         j++;
    //         if(j>top)j=1;
    //     }
    //     js=max(dis(sta[i],sta[j]), dis(sta[i+1],sta[j]));
    //     if(js>ans)ans=js;
    // }//旋转卡壳
//     cout<<sqrt(ans)<<"\n";
    cout<<setprecision(21)<<sqrt(rotating_calipers(ch,len))*2.0*pi+c<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}