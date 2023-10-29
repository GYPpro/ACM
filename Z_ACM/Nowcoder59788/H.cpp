#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <numeric>

#define ull unsigned long long
#define ld long double
#define maxn 100
#define modq 1000000007
#define ll long long

using namespace std;

void solve()
{
    long long m,a,b[maxn],c[maxn],ans=0,i,j,k,maxc=0;
    cin>>m>>a;
    for(i=0;i<m;i++) 
    {
        cin>>b[i]>>c[i];
        b[i]-=c[i];
        if(maxc<c[i]) maxc=c[i];
    }
    for(i=1;i<m;i++)
    {
        b[i]=gcd(b[i-1],b[i]);
    }
    //b[m-1]is gcd ans;
    
    cout<<ans;
    return;
}

int main()
{
    int T = 1;
    std::ios::sync_with_stdio(false);
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        solve();
    }
    system("pause");
    return 0;
}