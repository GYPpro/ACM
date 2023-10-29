#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define N 100005

using namespace std;

inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    __int128 n = read();
    __int128 i, j, k1, k0, num1, num0, ans1, ans0, ans = 0;
    if (n < 5)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n < 10)
    {
        print((n - 3) / 2);
        return 0;
    }
    /*{if(n%2==0) num1=n/2-2;
    else num1=(n+1)/2-2;//奇数个数
    num0=n/2-4;//偶数个数}*/
    // print(num1);
    __int128 m = 5;
    while (m <= n)
    {
        num0 = n / 2 - m + 1;
        if (n % 2 == 0)
            num1 = n / 2 - m / 2;
        else
            num1 = (n + 1) / 2 - m / 2;
        if (num0 < 0)
            num0 = 0;
        if (num1 < 0)
            num1 = 0;
        i = num0 / m;      //[i]偶数组数
        j = num1 / m;      //[j]奇数组数
        k1 = num1 - m * j; // 溢出部分奇数个数
        k0 = num0 - m * i; // 溢出部分偶数个数
        ans1 = (1 + j) * j / 2 * m + (1 + j) * k1;
        ans0 = (1 + i) * i / 2 * m + (1 + i) * k0;
        ans += (ans1 + ans0);
        m *= 5;
    }
    print(ans);
}