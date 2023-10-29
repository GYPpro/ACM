#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <MyLib\myRand.h>

#define ull unsigned long long
#define ld long double
#define maxn 100010
#define modq 10000007
#define ll long long

using namespace std;

myRandToolkit randtl;


vector<int> breakdown(int N) {
  vector<int> result;
  for (int i = 2; i * i <= N; i++) {
    if (N % i == 0) {  // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
      while (N % i == 0) N /= i;
      result.push_back(i);
    }
  }
  if (N != 1) {  // 说明再经过操作之后 N 留下了一个素数
    result.push_back(N);
  }
  return result;
}

void solve()
{
        ll int Num[3] = {0};
        cin >> Num[1] >> Num[2];
    if(Num[1] < Num[2]){
        ll int div = Num[2]-Num[1];
        div /= 3;
        Num[1] += 2*div;
        Num[2] -= div;
    }
    ll int ANS = 4*Num[2] + 2*(Num[1]-Num[2]);
    cout << ANS;
}

int main()
{
    int T = 1;
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        solve();
    }
    system("pause");
    return 0;
}