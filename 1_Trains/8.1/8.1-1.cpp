
#include <cstdio>
#include <cmath>
using namespace std;

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}

  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  char gc() {
#if DEBUG  // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }

  template <class T>
  void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }

  void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  template <class T>
  void write(T x) {
    if (x < 0) x = -x, push('-');  // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }

  template <class T>
  void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

struct node
{
    int x, y;
} nod[10005];
int n, m;
float ans;
int jude(int num, int x0, int y0)
{
    if ((nod[num - 1].x - x0) * (nod[num - 1].x - nod[num].x) + (nod[num - 1].y - y0) * (nod[num - 1].y - nod[num].y) < 0)
        return 0;
    if ((nod[num].x - x0) * (nod[num].x - nod[num - 1].x) + (nod[num].y - y0) * (nod[num].y - nod[num - 1].y) < 0)
        return 0;
    return 1;
}
void sovle(int x0, int y0)
{
    ans = 1e9 + 7;
    for (int i = 2; i <= n; i++)
    {
        int A = nod[i - 1].y - nod[i].y;
        int B = nod[i].x - nod[i - 1].x;
        int C = nod[i].y * nod[i - 1].x - nod[i].x * nod[i - 1].y;
        float key;
        if (!jude(i, x0, y0)) // 判断垂线在不在线段上
        {
            float aa, bb;
            aa = sqrt((x0 - nod[i].x) * (x0 - nod[i].x) + (y0 - nod[i].y) * (y0 - nod[i].y));
            bb = sqrt((x0 - nod[i - 1].x) * (x0 - nod[i - 1].x) + (y0 - nod[i - 1].y) * (y0 - nod[i - 1].y));
            key = min(aa, bb);
        }
        else
            key = abs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);
        ans = min(ans, key);
    }
}

int main()
{
    IO io;
    io.read<int>(n);
    io.read<int>(m);
    for (int i = 1; i <= n; i++)
    {
        io.read<int>(nod[i].x);
        io.read<int>(nod[i].y);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        io.read<int>(a);
        sovle(a, b);
        printf("%.4lf\n", ans);
    }
    return 0;
}