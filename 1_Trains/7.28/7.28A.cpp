#include <iostream>
//#include <stdio.h>
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

struct person{
    ll int idx;
    ll int val;
};

bool comp(person a,person b)
{
    return a.val < b.val;
};

person A[maxn] = {0};

void test()
{
    int n = rand()%20;
    int BIN[20] = {0};
    //将n转为二进制
    int i = 0;
    while(n != 0)
    {
        BIN[i] = n%2;
        n /= 2;
        i ++;
    }
    for(int j = 0;j < i;j ++)
    {
        cout << BIN[j];
    }
    cout << endl;
    system("pause");
}

void slove()
{
    string ARR;
    int t; 
    cin >> t;
    cin >> ARR;
    if((ARR[0]-'0')^(ARR[ARR.length()-1]-'0'))
    {
        for(int i = 0;i < t;i ++) cout << 1;
    } else if(ARR[0] == '0')//0
    {
        int maxar0 = 0;
        int rr0 = 0;
        int lr0 = 0;
        int ifar1 = 0;
        int ar0tmp;
        for(int i = 0;i < ARR.length();i ++)
        {
            if(ARR[i] == '1')//=0
            {
                if(ifar1 == 0)
                {
                    ifar1 = 1;
                    ar0tmp = 0;
                } else {
                    if(ar0tmp > maxar0) maxar0 = ar0tmp;
                    ar0tmp = 0;
                }
            } else {
                if (ifar1 == 1) ar0tmp ++;
                else lr0 ++;
            }
        }
        lr0 = ar0tmp;
        if(!ifar1) for(int i = 0;i < t;i ++) cout << 1;
        else if(lr0+rr0+t == maxar0) for(int i = 0;i < t;i ++) cout << "0";
        else for (int i = 0;i < t;i ++) cout << 1;
    } else {
        int maxar1 = 0;
        int rr1 = 0;
        int lr1 = 0;
        int ifar0 = 0;
        int ar1tmp;
        for(int i = 0;i < ARR.length();i ++)
        {
            if(ARR[i] == '0')//=1
            {
                if(ifar0 == 0)
                {
                    ifar0 = 1;
                    ar1tmp = 0;
                } else {
                    if(ar1tmp > maxar1) maxar1 = ar1tmp;
                    ar1tmp = 0;
                }
            } else {
                if (ifar0 == 1) ar1tmp ++;
                else lr1 ++;
            }
        }
        lr1 = ar1tmp;
        if(!ifar0) for(int i = 0;i < t;i ++) cout << "0";
        else if(lr1+rr1+t == maxar1) for(int i = 0;i < t;i ++) cout << 1;
        else for (int i = 0;i < t;i ++) cout << "0";
    }
    cout << endl;
}

int main()
{
    
    std::ios::sync_with_stdio(false);
   // test();
    int T;
    // scanf("%d",&T);
    cin >> T;
    //for(;;) test();
    for(int i = 0;i < T;i ++) slove();

   // system("pause");
    return 0;
}