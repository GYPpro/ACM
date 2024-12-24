#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc,char * argv[]){
    // void registerGen(int argc, char* argv[], int randomGeneratorVersion)
    registerTestlibCmd(argc,argv);
    int n = inf.readInt();
    std::vector<int> arr = ouf.readInts(n,0,9);
    std::vector<int> cnt(11);
    for(auto x:arr) cnt[x] ++;
    int f = n/5;
    for(auto x:cnt) if(x != f) quitf(_wa,"")
    for(int i = 1;i < n;i ++) if()
    // return 
    quitf(_fail,"testlib checker fail");
}