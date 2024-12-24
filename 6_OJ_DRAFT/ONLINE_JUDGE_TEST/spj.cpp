#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
    string s = ouf.readToken();
    if(s.size() >= 20)  quitf(_ok, "None.");
    if(s == "TESTLIB_FORCES_WA") quitf(_wa,"TESTLIB_FORCES_WA");
    if(s == "TESTLIB_FORCES_PE") quitf(_pe,"TESTLIB_FORCES_PE");
    quitf(_ok, "None.");
}