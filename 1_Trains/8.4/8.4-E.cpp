#include <iostream>
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 100

#define ull unsigned long long
using namespace std;


void solve()
{
    bool A[maxn] = {0};
    bool flagAr1[maxn] = {0};
    bool flagAr2[maxn] = {0};
    int pairSum1[maxn] = {0};
    int pairSum2[maxn] = {0};
    int zeroSum1[maxn] = {0};
    int zeroSum2[maxn] = {0};
    int n;
    cin >> n;
    
    int q;
    cin >> q;

    bool flagp1 = 0;
    bool flagp2 = 1;
    flagAr2[0] = 1;

    for (int i = 1;i <= n;i ++)
    {
        pairSum1[i] = pairSum1[i - 1];
        pairSum2[i] = pairSum2[i - 1];
        zeroSum1[i] = zeroSum1[i - 1];
        zeroSum2[i] = zeroSum2[i - 1];
        ull tmp;
        cin >> tmp;
        tmp %= 2;
        A[i] = tmp;
        if(tmp)
        {
            if(flagp1)
            {
                pairSum1[i] = pairSum1[i - 1] + 1;
                flagp1 = 0;
            } else flagp1 = 1;
            if(flagp2)
            {
                pairSum2[i] = pairSum2[i - 1] + 1;
                flagp2 = 0;
            } else flagp2 = 1;
        } else {
            if(!flagp1) zeroSum1[i] = zeroSum1[i - 1] + 1;
            if(!flagp2) zeroSum2[i] = zeroSum2[i - 1] + 1;
        }
        flagAr1[i] = flagp1;
        flagAr2[i] = flagp2;
    }
    for (int i = 0;i < q;i ++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        //区间长度l-r+1
        //K为区间数量，分隔数量为k-1
        if(k > r-l+1)
        {
            cout << "NO" << endl;
            continue;
        } else {
            if(!flagAr1[l-1])
            {
                if(flagAr1[r]) cout << "NO" << endl;
                else {
                    if(k <= zeroSum1[r] - zeroSum1[l - 1] + pairSum1[r] - pairSum1[l - 1]) {
                        cout << "YES" << endl;
                    } else cout << "NO" << endl;
                }
            } else {
                if(flagAr2[r]) cout << "NO" << endl;
                else {
                    if(k <= zeroSum2[r] - zeroSum2[l - 1] + pairSum2[r] - pairSum2[l - 1]) {
                        cout << "YES" << endl;
                    } else cout << "NO" << endl;
                }
            }
        }
    }
        
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // test();
    int T;

    // scanf("%d",&T);
    cin >> T;
    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");
    return 0;
}