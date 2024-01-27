#define _USE_IOSTREAM_
// #define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

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
#include <map>
#include <set>

#define pb push_back
#define ll long long
#define mod1 998244353

using namespace std;

//V2可以考虑类封装差分查询

int solMtx(const vector<vector<int>> &mtx,int k) //V1
{    
    int n = mtx[0].size();
    int m = mtx.size();
    // vector<vector<int>> mtx(m,vector<int>(n));//mtx2'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx[j][i] = _mtx[i][j];
    // swap(n,m);
    //[n][m]
    k ++;
    vector<vector<int>> sumX(n);
    vector<vector<int>> sumD(m+n);

    for(int i = 0;i < n;i ++)
    {
        sumX[i].pb(0);
        for(int j = 0;j < m;j ++)
            sumX[i].pb(sumX[i][j] + mtx[j][i]);
    }

    for(int i = 0;i < m;i ++)
    {
        sumD[i].pb(0);
        for(int j = 0;j < min(i,n);j ++)
            sumD[i].pb(sumD[i][j] + mtx[i-j-1][j]);
    }
    for(int i = 0;i < n;i ++)
    {
        sumD[i+m].pb(0);
        for(int j = 0;j < min(n-i,m);j ++)
            sumD[i+m].pb(sumD[i+m][j] + mtx[m-1-j][i+j]);
    }

    int maxAns = 0;
    int tsSum = 0;
    for(int i = 0;i < m;i ++)
    {
        tsSum = 0;
        for(int j = 0;j < n;j ++)
        {
            tsSum += sumX[j][i+1] - sumX[j][max(0,i-k+1)];
            if(i+j-k+1 >= 0)
                if(i+j-k+1 < m) 
                    tsSum -= sumD[i+j-k+1][min(j,(int)sumD[i+j-k+1].size()-1)]
                     - sumD[i+j-k+1][max(0,j-k)];
                    // else tsSum -= sumD[max(0,m+(j-k-1))][min(m-i-1+k,(int)sumD[max(0,m+(j-k-1))].size()-1)] - sumD[max(0,m+(j-k-1))][max(0,m-i-1)];
                    else tsSum -= sumD [i+j-k+1] [min(m-i+k-1,(int)sumD[i+j-k+1].size()-1)]
                     - sumD[i+j-k+1][max(0,m-i-1)];
            maxAns = max(tsSum,maxAns); 
        }
    }
    return maxAns;
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> mtx1(n,vector<int>(m));//[n][m]

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
        {
            char c;
            cin >> c;
            if(c == '.') mtx1[i][j] = 0;
            else mtx1[i][j] = 1;
        }

    vector<vector<int>> mtx2(m,vector<int>(n));// 90
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            mtx2[j][n-1-i] = mtx1[i][j];

    vector<vector<int>> mtx3(n,vector<int>(m));// +90
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < n;j ++)
            mtx3[j][m-1-i] = mtx2[i][j];

    vector<vector<int>> mtx4(m,vector<int>(n));// +90
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            mtx4[j][n-1-i] = mtx3[i][j];

    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx2[n-i-1][m-j-1] = mtx1[i][j];

    // vector<vector<int>> mtx1p(m,vector<int>(n));//mtx1'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx1p[j][i] = mtx1[i][j];

    // vector<vector<int>> mtx2p(m,vector<int>(n));//mtx2'
    // for(int i = 0;i < n;i ++)
    //     for(int j = 0;j < m;j ++)
    //         mtx2p[j][i] = mtx2[i][j];

    cout << max(max(solMtx(mtx1,k),solMtx(mtx2,k)),max(solMtx(mtx3,k),solMtx(mtx4,k))) << "\n";

}

#define _WITH_T_    

int main()
{
    #ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #endif
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}