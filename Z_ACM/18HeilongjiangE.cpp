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

int ttt(int n)
{
    ull ANS = 1;
    for(int i = 1;i <= n;i ++)
    {
        ANS *= i;
    }
    return ANS;
}

void slove()
{
    double n,m;
    cin >> n >> m;

    double ANS = 0;
    ANS += m/n;
    double tmpA1;
    tmpA1 = (double)ttt(m)/((double)ttt(n-1)/(double)ttt(m));
    ANS += (n-m)/n*(1-tmpA1)*( ((n-1)-m)/(n-m));
    cout << ANS << endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    for(;;)slove();
    return 0;
}