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
#define maxn 1001000

#define ull unsigned long long
using namespace std;

long double A[3][3] = {0};
long double A_[3][4] = {0};

int getRank_A()//获取矩阵A的秩
{
    int rank = 0;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        if (A[i][i] == 0)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (A[j][i] != 0)
                {
                    for (k = 0; k < 3; k++)
                    {
                        swap(A[i][k], A[j][k]);
                    }
                    break;
                }
            }
        }
        if (A[i][i] != 0)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (A[j][i] != 0)
                {
                    long double temp = A[j][i];
                    for (k = i; k < 3; k++)
                    {
                        A[j][k] = (A[j][k] * A[i][i] - A[i][k] * temp);
                    }
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (A[i][i] != 0)
            rank++;
    }
    return rank;
}

int getRank_A_()
{
    int rank = 0;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        if (A_[i][i] == 0)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (A_[j][i] != 0)
                {
                    for (k = 0; k < 4; k++)
                    {
                        swap(A_[i][k], A_[j][k]);
                    }
                    break;
                }
            }
        }
        if (A_[i][i] != 0)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (A_[j][i] != 0)
                {
                    long double temp = A_[j][i];
                    for (k = i; k < 4; k++)
                    {
                        A_[j][k] = (A_[j][k] * A_[i][i] - A_[i][k] * temp);
                    }
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (A_[i][i] != 0)
            rank++;
    }
    return rank;
}



void solve()
{
    long double x1 = 0,x2 = 0,x3 = 0;
    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 3;j ++)
            cin >> A_[j][i];
    for(int i = 0;i < 3;i ++)
        for(int j = 0;j < 3;j ++)
            A[i][j] = A_[i][j];
    int rank_A = getRank_A();
    int rank_A_ = getRank_A_();
    //求解并判断是否有正数解
    if(rank_A == rank_A_)
    {
        if(rank_A == 3)
        {
            x3 = (long double)A_[2][3] / A_[2][2];
            x2 = (long double)(A_[1][3] - A_[1][2] * x3) / A_[1][1];
            x1 = (long double)(A_[0][3] - A_[0][2] * x3 - A_[0][1] * x2) / A_[0][0];
            if(x1 >= 0 && x2 >= 0 && x3 >= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if(rank_A == 2)
        {
            long double tx1,tx2,tx3;//系数矩阵基础解系
            tx3 = 1;
            tx2 = -(long double)A_[1][2] / A_[1][1];
            tx1 = (long double)(-A_[0][2] - A_[0][1] * tx2) / A_[0][0];
            long double fx1,fx2,fx3;//原方程特解
            fx3 = 0;
            fx2 = A_[1][3] / A_[1][1];
            fx1 = (A_[0][3] - A_[0][1] * fx2) / A_[0][0];
            //判断解系tx+k*fx中是否存在正数解
            if(tx1 >= 0 && tx2 >= 0 && tx3 >= 0)
                cout << "YES" << endl;
            else
            {
                long double k = 0;
                if(tx1 < 0)
                    k = max(k,(-tx1) / fx1);
                if(tx2 < 0)
                    k = max(k,(-tx2) / fx2);
                if(tx3 < 0)
                    k = max(k,(-tx3) / fx3);
                if(fx1 * k + tx1 >= 0 && fx2 * k + tx2 >= 0 && fx3 * k + tx3 >= 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }

        } 
        else if(rank_A == 1) 
        {
            long double tx1,tx2,tx3;//系数矩阵基础解系
            tx3 = 1;
            tx2 = 0;
            tx1 = 0;
            long double fx1,fx2,fx3;//原方程特解
            fx3 = 0;
            fx2 = 0;
            fx1 = (long double) A[0][3] / A[0][0];
            //判断解系tx+k*fx中是否存在正数解
            if(tx1 >= 0 && tx2 >= 0 && tx3 >= 0)
                cout << "YES" << endl;
            else
            {
                long double k = 0;
                if(tx1 < 0)
                    k = max(k,(-tx1) / fx1);
                if(tx2 < 0)
                    k = max(k,(-tx2) / fx2);
                if(tx3 < 0)
                    k = max(k,(-tx3) / fx3);
                if(fx1 * k + tx1 >= 0 && fx2 * k + tx2 >= 0 && fx3 * k + tx3 >= 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    else
        cout << "NO" << endl;
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