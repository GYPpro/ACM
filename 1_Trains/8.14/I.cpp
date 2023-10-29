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
#define mod1 (ll)(1e9 + 7)
#define maxn 500
#define ull unsigned long long

using namespace std;

struct mpair{
    int a,b;
};

bool comp(mpair a,mpair b)
{
    return a.a < b.a;
}

ll int binpow(int m,int n)
{
    ll int ans = 1;
    ll int tmp = m;
    while(n)
    {
        if(n & 1)
            ans = (ans * tmp) % mod1;
        tmp = (tmp * tmp) % mod1;
        n >>= 1;
    }
    return ans % mod1;
}

int sumi[maxn];
int divi[maxn] = {0};

void solve()
{
    vector<mpair> ar1;
    vector<mpair> ar2;
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int tmpa1,tmpb1,tmpa2,tmpb2;
        cin >> tmpa1 >> tmpb1 >> tmpa2 >> tmpb2;
        divi[tmpa1] ++;
        divi[tmpb1] --;
        divi[tmpa2] ++;
        divi[tmpb2] --;
        mpair tmp1,tmp2;
        if(tmpa1 >= tmpa2){
            swap(tmpa1,tmpa2);
            swap(tmpb1,tmpb2);
        }
        if(tmpa2 < tmpb1)
        {
            tmp1.a = tmpa1;
            tmp1.b = tmpb2;
            ar1.push_back(tmp1);
            ar2.push_back(tmp1);
        } else {
            tmp1.a = tmpa1;
            tmp1.b = tmpb1;
            tmp2.a = tmpa2;
            tmp2.b = tmpb2;
            ar1.push_back(tmp1);
            ar2.push_back(tmp2);
        }
    }
    sort(ar1.begin(),ar1.end(),comp);
    sort(ar2.begin(),ar2.end(),comp);
    mpair ansarr1,ansarr2;
    ansarr1.a = 0;
    ansarr1.b = maxn;
    for(int i = 0;i < ar1.size();i ++)
    {
        if((ar1[i].b < ansarr1.a) || (ar1[i].a > ansarr1.b )){
            ansarr1.a = -1;
            ansarr1.b = -1;
            break;
        }
        if(ar1[i].a > ansarr1.a)
            ansarr1.a = ar1[i].a;
        if(ar1[i].b < ansarr1.b)
            ansarr1.b = ar1[i].b;
    }
    ansarr2.a = 0;
    ansarr2.b = maxn;
    for(int i = 0;i < ar2.size();i ++)
    {
        if((ar2[i].b < ansarr2.a) || (ar2[i].a > ansarr2.b )){
            ansarr2.a = -1;
            ansarr2.b = -1;
            break;
        }
        if(ar2[i].a > ansarr2.a)
            ansarr2.a = ar2[i].a;
        if(ar2[i].b < ansarr2.b)
            ansarr2.b = ar2[i].b;
    }

    if(ansarr1.a > ansarr2.a)
        swap(ansarr1,ansarr2);
    
    if(ansarr1.b >= ansarr2.a)
    {
        ansarr1.b = ansarr2.b;
        ansarr2.a = -1;
        ansarr2.b = -1;
    }

    for(int i = 0;i < maxn;i ++)
    {
        if(i != 0)
            sumi[i] = sumi[i - 1] + divi[i];
        else
            sumi[i] = divi[i];
    }
    ll int ans = 0;
    ll int tmpans1 = 0;
    if(ansarr1.a != -1)
    {
        for(int i = ansarr1.a;i <= ansarr1.b;i ++)
        {
            ll int tmpsum2 = sumi[i];
            ll int tmpans = binpow(2,tmpsum2-n+1);
            if(tmpans > tmpans1)
                tmpans1 = tmpans;
        }
    }
    ll int tmpans2 = 0;
    if(ansarr2.a != -1)
    {
        for(int i = ansarr2.a;i <= ansarr2.b;i ++)
        {
            ll int tmpsum2 = sumi[i];
            ll int tmpans = binpow(2,tmpsum2-n+1);
            if(tmpans > tmpans2)
                tmpans2 = tmpans;
        }
    }
    cout << tmpans1+tmpans2 << endl;
}

// #define _WITH_T_

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