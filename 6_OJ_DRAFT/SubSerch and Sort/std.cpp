#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int main()
{
	void solve();
	solve();
	return 0;
}

struct point //结构体存点
{
	ll x,y;  //坐标
	ll v;  //价值
}a[N],b[N];
void merge(int l,int r) //归并排序
{
	int mid=(l+r)/2;
	if(l==r)return;
	if(l+1==r)
	{
		if(a[l].v>a[r].v)swap(a[l],a[r]); 
		else if(a[l].v==a[r].v)
		{
			if(a[l].x>a[r].x)swap(a[l],a[r]);
			else if(a[l].x==a[r].x)
			{
				if(a[l].y>a[r].y)swap(a[l],a[r]);
			}
		}
		return ;
	}
	merge(l,mid);merge(mid+1,r);  //先将左右半边排好序

	int i=l,j=mid+1,t=l;//分别从左右两半边选点

	while(i<=mid&&j<=r)
	{
		if(a[i].v<a[j].v) //先比较价值
		{
			b[t++]=a[i++];
		}
		else if(a[i].v==a[j].v)  //价值相等比较坐标
		{
			if(a[i].x<a[j].x) //先比较x坐标
			{
				b[t++]=a[i++];
			}
			else if(a[i].x==a[j].x) //x坐标比较y坐标
			{
				if(a[i].y<a[j].y)
				{
					b[t++]=a[i++];
				}
				else 
				{
					b[t++]=a[j++];
				}
			}
			else if(a[i].x>a[j].x)
			{
				b[t++]=a[j++];
			}
		}
		else if(a[i].v>a[j].v)
		{
			b[t++]=a[j++];
		}
	}
	while(i<=mid)b[t++]=a[i++];
	while(j<=r)b[t++]=a[j++];
	for(i=l;i<=r;i++)a[i]=b[i];
	return ;
}

void solve()
{
    freopen("temp.in","r",stdin);
    freopen("temp.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].v=a[i].x*a[i].x+a[i].y*a[i].y;
	}
	merge(1,n);
	while(q--)
	{
		ll x,y,v;
		scanf("%lld%lld",&x,&y);
		v=x*x+y*y;

		int l=1,r=n,mid=(l+r)/2;  //对于每次询问使用二分查找找到对应的点
		while(l<r)
		{
			mid=(l+r)/2;
			
			if(v<=a[mid].v)
			{
				r=mid;
			}
			else l=mid+1;
		}
		
		if(v!=a[l].v)printf("Not Found\n");  //价值不等说明不存在这种点
		else 
		{
			printf("%lld %lld\n",a[l].x,a[l].y);  //输出点
		}
	}
}/*
3 8
315946560 1500408 //99824480000000064
266898943 169084104 //99824480000000065
140754862 282864895 //99824480000000069

1500408 315946560
295406649 112068692
266898943 169084104
282864895 140754862
312515395 46460821
229453279 217199615
217199615 229453279
46460821 312515395

315946560 1500408
266898943 169084104
266898943 169084104
140754862 282864895
Not Found
Not Found
Not Found
Not Found
*/