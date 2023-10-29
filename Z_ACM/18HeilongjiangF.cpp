#include <iostream>
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
    int T;
    cin >> T;
    int ANS = 0;
    bool N[maxn] = {false};
    for(int i = 0;i < T-1;i ++)
    {
        int tmp;
        cin >> tmp;
        if(N[tmp]) ANS ++;
        else N[tmp] = true;
    }
    cout << ANS << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    for(;;)slove();
    return 0;
}