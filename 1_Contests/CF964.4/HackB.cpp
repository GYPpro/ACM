#include <stdio.h>
#include <bits/stdc++.h>
int main()
{
    long int t;
    long int a[10000][4];
    long int b[10000];
    int m, n, p;
    scanf("%ld", &t);
    for (long int i = 0; i < t; i++)
        for (long int j = 0; j < 4; j++)
            scanf("%ld", &a[i][j]);
    // 输入四个数
    for (int i = 0; i < t; i++) // 分别将两个人手中比较小的数排在第一个
    {
        p = 0;
        if (a[i][0] > a[i][1])
        {
            p = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = p;
            // swap(a[i][0],a[i][1]);
        }
        if (a[i][2] > a[i][3])
        {
            p = a[i][2];
            a[i][2] = a[i][3];
            a[i][3] = p;
        }
    }

    // 2 5     3 5

    for (long int i = 0; i < t; i++)
    {
        if (a[i][0] > a[i][3]) 
        {
            b[i] = 4;
        }
        else if (a[i][0] > a[i][2]) 
        {
            b[i] = 2;
        }
        else
        {
            b[i] = 0;
        }
    }
    for (long int i = 0; i < t; i++)
        printf("%d\n", b[i]);
    return 0;
}