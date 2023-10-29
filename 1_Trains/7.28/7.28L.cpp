#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 1000010

#define ull unsigned long long
using namespace std;

struct oper{
    bool if_r;//if_r = 1: r; if_r = 0: c
    int oprIdx;
    bool if_on;//if_on = 1: on; if_on = 0: off
};

void slove()
{
    int m,n;
    cin >> n >> m ;
    int opered[maxn][2] = {0};

    //r:n m:c
    int q;
    cin >> q;
    oper op[maxn];
    for(int i = 0;i < q;i++)
    {
        string c;
        cin >> c;
        if(c == "row")
        {
            op[i].if_r = 1;
        } else {
            op[i].if_r = 0;
        }
        cin >> op[i].oprIdx;
        cin >> c;
        if(c == "on")
        {
            op[i].if_on = 1;
        } else {
            op[i].if_on = 0;
        }
    }
    ll int ans = 0;
    for(int i = q-1;i >= 0;i --)
    {
        if(opered[op[i].oprIdx][op[i].if_r] == 1) continue;
        else opered[op[i].oprIdx][op[i].if_r] = 1;
        if(op[i].if_r == 1) //r
        {
            if(op[i].if_on == 1)
            {
                ans += m;
                n --;
            } else {
                n --;
            }
        } else {
            if(op[i].if_on == 1)
            {
                ans += n;
                m --;
            } else {
                m --;
            }
        }
        if(!(m||n)) break;
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    slove();
   // system("pause");
    return 0;
}