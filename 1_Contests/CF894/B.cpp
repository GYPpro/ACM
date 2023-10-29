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

char getnext(char a)
{
    switch(a){
        case 'v':return 'i';
        case 'i':return 'k';
        case 'k':return 'a';
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll int> cnt(n+10);
    vector<ll int> arr(n);
    bool flag = 0;
    for(int i = 0;i < n;i ++)
    {
        ll int tmp;
        cin >> tmp;
        if(tmp > n) flag = 1;
        if(!flag){
            arr[i] = tmp;
            cnt[tmp] ++;
        }
    }
    if(flag) {
        cout << "No\n";
        return;
    }

    for(int i = n+1;i >= 1;i --) cnt[i] += cnt[i+1];

    flag = 1;
    for(int i = 0;i < n;i ++)
    {
        if(arr[i] != cnt[i+1]) flag = 0;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
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