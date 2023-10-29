#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 100010

#define ull unsigned long long
using namespace std;

void slove()
{
    int T;
    cin >> T;
    ull int ANS = 1;

    T --;

    for(;T >= 1;T--)
    {
        ANS *= 2;
        ANS %= mod1;
   //     T--;
    }
    cout << ANS  << endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    for(;;)slove();
    return 0;
}