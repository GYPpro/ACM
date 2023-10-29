//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 100010

#define ull unsigned long long
using namespace std;


void slove()
{
    ll int n;
    scanf("%lld",&n);
    double ans = 2.0-2.0/(double)n;
    double ans2 = 2.0;
    if(n == 2) ans2 = 1.0;
    printf("%.9lf %.9lf\n",ans,ans2);

}

int main()
{
 //   std::ios::sync_with_stdio(false);
 int T;
 scanf("%d",&T);
    for(int i = 0;i < T;i ++)slove();
   // system("pause");
    return 0;
}