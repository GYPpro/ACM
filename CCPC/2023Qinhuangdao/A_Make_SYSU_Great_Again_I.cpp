#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define N 100005
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0
// #define OVERFLOW -2

using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a = 1, b = 1;
    for (ll i = 1; i <= n * 2 - 1; i++)
    {
        cout << a << " " << b << "\n";
        if (a == b)
            b++;
        else
            a++;
    }
    cout << n << " 1\n";
    a = 1;
    b = 1;
    for (ll i = n * 2 + 1; i <= k; i++)
    {
        b ++;
        if(a == b || a+1 == b) b = a+2;
        if(b > n) {
            a ++;
            b = 1;
        }
        if(a == n && b == 1) b ++;
        cout << a << " " << b << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
        solve();
    // system("pause");
}