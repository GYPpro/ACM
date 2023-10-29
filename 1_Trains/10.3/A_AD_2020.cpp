#define _USE_IOSTREAM_
#define _PRIV_TEST_

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

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

vector<int> mo;

bool ifComDay(int yy,int mm,int dd)
{
    if(mm == 2) return dd <= 28+(yy%4 == 0);
    return dd<=mo[mm];
}

class prt{
public:
    vector<int> arr;
    // int pri;

public:
    prt()
    {
        arr.resize((int)(3*1e6+8*1e5+1000));
        // pri = 0;
    }
    int getPri(int yy,int mm,int dd){return (yy-2000)*365+mm*31+dd;}

    void init(int yy,int mm,int dd)
    {
        // yy -= 2000;
        int i = yy*372+mm*31+dd;
        // cout << yy << mm << dd  << i << " :";
        if(!ifComDay(yy,mm,dd)) 
            arr[i] = arr[i-1];
        else {
            // cout << arr[i-1] << endl;
            if((yy/10 == 202) || (yy % 1000 == 202)) 
                arr[i] = arr[i-1]+1;
            else if((yy %10 == 2) && (mm == 2)) 
                arr[i] = arr[i-1] +1;
            else if((mm == 12 && dd == 2) || (mm == 2 && dd == 2)) 
                arr[i] = arr[i-1] +1;
            else 
                arr[i] = arr[i-1];
        }
    }
    void setPrAdd(int yy,int mm,int dd,int n)
    {
        // yy -= 2000;
        arr[yy*372+mm*31+dd] = n;
    }
    int getPrAdd(int yy,int mm,int dd)
    {
        // yy -= 2000;
        return arr[yy*372+mm*31+dd];
    }
};

prt Year;

void list()
{
    mo.push_back(0);
    mo.push_back(31);
    mo.push_back(28);
    mo.push_back(31);
    mo.push_back(30);
    mo.push_back(31);
    mo.push_back(30);
    mo.push_back(31);
    mo.push_back(31);
    mo.push_back(30);
    mo.push_back(31);
    mo.push_back(30);
    mo.push_back(31);
    int yy = 2000;
    int mm = 1;
    int dd = 1;
    for(;yy <= 10000;yy ++)
    {
        for(;mm <= 12;mm ++)
        {
            for(;dd <= 31;dd ++)
            {
                Year.init(yy,mm,dd);
            }
            dd = 1;
        }
        mm = 1;
    }
}

void solve()
{
    int y1,m1,d1;
    cin >> y1 >> m1 >> d1;   
    int y2,m2,d2;
    cin >> y2 >> m2 >> d2;
    cout << Year.getPrAdd(y2,m2,d2)-Year.getPrAdd(y1,m1,d1-1) << endl;   
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

    list();

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