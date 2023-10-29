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
    string s = "0";
    string tmp;
    cin >> tmp;
    s += tmp;
    int k = 0;
    for(k = 0 ;k < s.length();k ++) if((s[k+1]-'0') >= 5) break;
    for(;(k >= 0) && (s[k] == '4');k --);
    if(s[0] != '0') cout << s[0];
    for(int i = 1;i < k;i ++) cout << s[i];
    if(k < s.length()) cout << s[k]-'0'+1;
    for(int i = k+1;i < s.length();i ++) cout << 0;
    cout << endl;
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;

    // scanf("%d",&T);
    cin >> T;
    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");
    return 0;
}