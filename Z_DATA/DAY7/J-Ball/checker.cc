#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int MAXN = 3000005;
const long double EPS=1e-3;
bool check(long long l,long long x,long long y)
{
    return  (x * x + y * y <= l * l) || ((x - l) * (x - l) + y * y <= l * l);
}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    for (int cas = 1; cas <= T; ++cas)
    {
        //setTestCase(cas);
        long long l = inf.readLong();
        long long x = inf.readLong();
        long long y = inf.readLong();

        string yn = ouf.readToken("[YyEeSsNnOo]{2,3}", "yn");
        for (auto& i : yn)
        {
            i |= ' ';
        }
        quitif(yn != "yes" && yn != "no", _wa, "token must give yes or no");
        quitif(yn == "yes" && !check(l,x,y), _wa,
               "expected: no, found yes, l:%lld, x:%lld, y:%lld ", l, x, y);
        quitif(yn == "no" && check(l,x,y), _wa,
               "expected: yes, found no, l:%lld, x:%lld, y:%lld ", l, x, y);
        if (yn == "yes")
        {
            long double px=ouf.readDouble(0,l,"px");
            long double pl=max(px,l-px);
            quitif(x*x+y*y>pl*pl + EPS && (x-l)*(x-l)+y*y>pl*pl + EPS, _wa, "not hit ball x:%Lf", px);
        }
    }
    quitf(_ok, "all ok!");
    return 0;
}