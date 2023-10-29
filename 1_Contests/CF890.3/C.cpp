#define _USE_IOSTREAM_
// #define _USE_STDIO_

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

struct numsum
{
    int num;
    int sum;
};

bool comp(numsum a, numsum b)
{
    return a.num < b.num;
}

vector<numsum> HSL;

void addtoHSL(int a)
{
    for (int i = 0; i < HSL.size(); i++)
    {
        if (HSL[i].num == a)
        {
            HSL[i].sum++;
            return;
        }
    }
    numsum tmp;
    tmp.num = a;
    tmp.sum = 1;
    HSL.push_back(tmp);
}

void solve()
{
    HSL.clear();
    int n;
    int tmp;
    cin >> n;
    tmp = (n * (n - 1)) / 2;
    int B[maxn] = {0};
    for (int i = 0; i < tmp; i++)
        cin >> B[i];
    for (int i = 0; i < tmp; i++)
        addtoHSL(B[i]);
    sort(HSL.begin(), HSL.end(), comp);
    int HSLidx = 0;
    int tmpsum = 0;
    int tmpadd = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        cout << HSL[HSLidx].num << " ";
        HSL[HSLidx].sum -= tmpadd;
        tmpadd--;
        if (HSL[HSLidx].sum == 0)
            HSLidx++;
    }
    cout << HSL[HSLidx - 1].num << endl;
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // scanf("%d",&T);
    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");
    return 0;
}