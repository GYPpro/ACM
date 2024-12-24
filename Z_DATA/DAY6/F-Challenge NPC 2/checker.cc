#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int n,m;
typedef pair<int,int> pii;
set<pii> Ed;


 
inline int readAndCheckAnswer(InStream &in) {
    int result = in.readInt(-1, n, "result");
    if (result == -1)
        return result;
    if (result == 0) in.quitf(_wa , "invalid output containing 0") ;
    vector<int> v ; v.push_back(result) ;
    for(int i = 2;i <= n;i++) {
        int u = in.readInt(1, n, format("u_%d", i));
        v.push_back(u) ;
    }
    auto Find = [&](int u ,int v) {
        if(u > v) swap( u , v);
        if(Ed.find({u,v})!=Ed.end()) return 1;
        return 0;
    };
    for(int i = 1;i < v.size();i++) {
        if(Find(v[i - 1] , v[i])) in.quitf(_wa , "containing edge");
    }
    sort(v.begin() , v.end()) ;
    for(int i = 1;i < v.size();i++) {
        if(v[i] == v[i - 1]) in.quitf(_wa , "containing duplicated vertex" );
    }
    return 1;
}
void solv() {

    n = inf.readInt();
    m = inf.readInt() ;
    Ed.clear() ;
    for(int i = 1;i <= m;i++) {
        int u , v;
        u = inf.readInt() ;
        v = inf.readInt() ;
        if(u > v) swap(u,v);
        Ed.insert({u,v});
    }
 
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
 
    if (ja != -1 && pa == -1)
        quitf(_wa, "Jury has the answer but participant has not");
    if (ja == -1 && pa != -1)
        quitf(_fail, "Participant has the answer but jury has not");
 
}
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int t = inf.readInt() ;
    for(int i = 1;i <= t;i++) {
        solv() ;
    }
    quitf(_ok, "t=%d", t);
}
