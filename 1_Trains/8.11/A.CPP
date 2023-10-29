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

void solve()
{
    int n;
    cin >> n;
    vector<string> s;
    for(int ii = 0;ii < n;ii ++)
    {
        int c;
        cin >> c;
        for(int i = 0;i < c;i ++)
        {
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
    }
    sort(s.begin(), s.end());
    vector<string> ans;
    int flag = 1;
    string strtmp = s[0];
    if(flag == n){
        ans.push_back(strtmp);
    }
    for(int i = 1;i < s.size();i ++)
    {
        if(s[i] == strtmp)
        {
            flag ++;
            if(flag == n) ans.push_back(strtmp);
        } else {
            strtmp = s[i];
            flag = 1;
            if(flag == n) ans.push_back(strtmp);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i ++)
    {
        cout << ans[i] << endl;
    }
    return;
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

//    system("pause");

    return 0;
}