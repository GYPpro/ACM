#include <iostream>
using namespace std;
#define int long long

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

signed main()
{
    int a,m = 998244353;
    cin >> a;
    int x,y;
    exgcd(a,m,x,y);
    cout << (x + m) % m << "\n";
}