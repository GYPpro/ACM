#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

#define ull unsigned long long
#define ld long double
#define maxn 100010
#define modq 1000000007
#define ll long long

using namespace std;

void solve()
{
    bool fastPow[100] = {false};
    ll int fastPowNum[100] = {0};
    int powidx = 99;
    ll int N;
    cin >> N;
    if(N == 2){
        cout << "26 650 0\n";
        return;
    }
    for(int i = N;i > 0;)
    {
        fastPow[powidx] = i%2;
        i >>= 1;powidx --;
    }
    ll int powtmp = 26;
    for(int i = 99;i > powidx;i --){
        fastPowNum[i] = powtmp;
        powtmp *= powtmp;
        powtmp %= modq;
    }
    ll int ANSm = 1;
    for(int i = 99;i > powidx;i --)
    {
        ANSm %= modq;
        if(fastPow[i])ANSm *= fastPowNum[i];
    }
    ANSm += modq;
    ANSm -= 26;
    ANSm %= modq;
    cout <<"26 0 " << ANSm << endl;
    return;
}

int main()
{
    int T = 1;
    std::ios::sync_with_stdio(false);
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        solve();
    }
    system("pause");
    return 0;
}