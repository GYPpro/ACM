#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>

#define ll long long
#define N 100005

using namespace std;

ll a[5]={0,0,1,1,2};

ll recu(ll x,ll d)
{
    if(d >= 100) return 1000000000000000000;
    if(x<=4) return a[x];
    else
    {
        if(x%3==0) return recu(x/3,d+1)+1;
        else
        {
            if(x%2==0)
            {
                if(x%3==1)
                {
                    ll ans1 = recu((x-1)/3,d+2)+2;
                    ll ans2 = recu(x/2,d+1)+1;
                    if(ans1<ans2) return ans1;
                    else return ans2;
                }
                if(x%3==2)
                {
                    ll ans1 = recu((x-2)/3,d+3)+3;
                    ll ans2 = recu(x/2,d+1)+1;
                    if(ans1<ans2) return ans1;
                    else return ans2;
                }
            }
            else return recu(x-1,d+1)+1;
        }
    }
}



void solve()
{
    for(int i = 0;i < 1000;i ++)
    {
        cout << i << " " << recu(i,0) << "\n";
    }
    cout << recu(1000,0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    system("pause");
}