#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 1100

#define ull unsigned long long
using namespace std;


void solve()
{
    ll int n,k;
    cin >> n >> k;
    ll int A[maxn] = {0};
    for(int i = 0;i < n;i ++)
        cin >> a[i];
    vector<int> downpoint;
    vector<int> maxnum;
    for(int i = 0;i < n;i ++)
    {
        if(A[i] > A[i + 1])
            downpoint.push_back(i);
    }
    downpoint.push_back(n);
    for(int i = 0;i < downpoint.size();i ++)
    {
        int maxtmp = 0;
        for(int j = i;j >= 0;j --)
        {
            
        }
        
        maxnum.push_back(max);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 0;
    cin >> T;
    for(int i = 0;i < T;i ++)
        solve();
   // system("pause");
    return 0;
}