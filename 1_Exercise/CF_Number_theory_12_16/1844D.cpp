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

class lgt
{
private:
    string chrs;
    bool iflgt[27];

public:
    lgt()
    {
        for (int i = 0; i < 26; i++)
        {
            chrs.push_back((char)('a' + i));
            iflgt[i] = true;
        }
    }

    char getLgtChr()
    {
        for (int i = 0; i < 26; i++)
        {
            if (iflgt[i])
                return chrs[i];
        }
    }

    void setIlg(char c)
    {
        iflgt[(int)(c - 'a')] = false;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> fac;
    for (int i = 1; i < (int)sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            fac.push_back(i);
            fac.push_back(n/i);
        }
    }
    vector<lgt> arr(n);
    string ans;
    for (int i = 0; i < n; i++)
    {
        char tmpChr = arr[i].getLgtChr();
        for (int j = 0; j < fac.size(); j++)
        {
            if(i+fac[j] < n)arr[i+fac[j]].setIlg(tmpChr);
        }
        ans.push_back(tmpChr);
    }
    cout << ans << endl;
    return;
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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}