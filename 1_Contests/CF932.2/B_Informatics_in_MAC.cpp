#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

#define ll long long
#define N 100005
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr, cmp(n + 1, 0), cmpl(n + 1, 0), cmpr(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
        cmp[tmp]++;
    } // input
    ll flag;
    ll fl=0,fr=0;
    for (ll i = 0; i < n; i++)
    {
        if (cmp[i] == 1)
        {
            cout << "-1\n";
            return;
        }
        else if (cmp[i] == 0)
        {
            flag = i;
            break;
        }
    }
    ll flag1;
    for(ll i=0;i<n&&fl<flag;i++)
    {
        if(arr[i]<flag&&cmpl[arr[i]]==0)
        {
            fl++;
            cmpl[arr[i]]=1;
        }
        flag1=i+1;
    }
    for(ll i=flag1;i<n;i++)
    {
        if(arr[i]<flag&&cmpr[arr[i]]==0)
        {
            fr++;
            cmpr[arr[i]]=1;
        }
    }
    if(fr<flag) cout<<"-1\n";
    else
    {
        cout<<"2\n1 "<<flag1<<"\n"<<flag1+1<<" "<<n<<"\n";
    }
}

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    ll t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
    // system("pause");
}