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

class mcolor{
public:
    int r;
    int g;
    int b;

public:
    mcolor()
    {
        r = 0;
        g = 0;
        b = 0;
    }
    mcolor(int _r,int _g,int _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
    void setcolor(int _r,int _g,int _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
    bool operator==(mcolor B)
    {
        bool ifcomp = 1;
        if((r < B.r) && (g < B.g) && (b < B.b)) return 0;
        else  if((r > B.r) && (g > B.g) && (b > B.b)) return 0;
        return 1;
    }
    bool operator!=(mcolor B)
    {
        bool ifcomp = 1;
        if((r < B.r) && (g < B.g) && (b < B.b)) return 1;
        else  if((r > B.r) && (g > B.g) && (b > B.b)) return 1;
        return 0;
    }
    bool operator>(mcolor B)
    {
        if((r > B.r) && (g > B.g) && (b > B.b)) return 1;
        return 0;
    }
    bool operator<(mcolor B)
    {
        if((r < B.r) && (g < B.g) && (b < B.b)) return 1;
        return 0;
    }
};

struct tcolor{
    mcolor color;
    int grayini;
    int idx;
};

bool comp(tcolor a,tcolor b)
{
    return a.color < b.color;
}

bool recomp(tcolor a,tcolor b)
{
    return a.idx < b.idx;
}

void solve()
{
    int n;
    cin >> n;
    vector<tcolor> arr(n);
    
    for(int i = 0;i < n;i ++)
    {
        int tr,tg,tb;
        cin >> tr >> tg >> tb;
        arr[i].color.setcolor(tr,tg,tb);
        arr[i].idx = i;
    }
    sort(arr.begin(),arr.end(),comp);
    int tmpgry = 0;
    int tar0,tar1;
    for(int i = 0;i < n;i ++)
    {
        if(arr[i].idx == 0) tar0 = i;
        if(arr[i].idx == 1) tar1 = i;
    }
    if(tar0 > tar1) swap(tar0,tar1);
    for(;;)
    {
        bool done = 0;
        if((tar0 == n-1) || (tar1 == 0)) break;
        if(arr[tar0].color == arr[tar0+1].color){
            swap(arr[tar0],arr[tar0+1]);
            tar0 ++;
            done = 1;
        }
        if(tar0 == tar1-1) break;
        if(arr[tar1].color == arr[tar1-1].color){
            swap(arr[tar1],arr[tar1-1]);
            tar1 --;
            done = 1;
        }
        if(!done) break;
    }
    for(int i = 0;i < n-1;i ++)
    {
        arr[i].grayini = tmpgry;
        if(arr[i].color != arr[i+1].color) tmpgry ++;
    }
    arr[n-1].grayini = tmpgry;
    if(tmpgry > 255) {
        cout << -1 << endl;
        return ;
    }
    if(arr[tar0].grayini != arr[tar1].grayini) {
        cout << -1 << endl;
        return;
    }
    sort(arr.begin(),arr.end(),recomp);
    for(int i = 0;i < n;i ++)
    {
        cout << arr[i].grayini << endl;
    }
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

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
} 