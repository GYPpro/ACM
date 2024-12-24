
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
long long sum = 0;

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int t = inf.readInt();
    long long n, m;
    for(int cas=1;cas<=t;++cas) {
        //setTestCase(cas);
        n=inf.readLong();
        m=ouf.readLong(-1ll,1'000'000'000'000'000'000,"m");
        quitif(m==0,_wa,"m != 0");
        if((n & (n - 1)) == 0) {
            if(m != -1) quitf(_wa,"wa 1");
        }
        else {
            if(__gcd(n, m) != (n ^ m)) quitf(_wa,"wa 2");
        }
    }
    quitf(_ok, "all ok!");
    return 0;
}