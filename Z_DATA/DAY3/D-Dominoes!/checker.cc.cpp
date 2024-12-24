#include <bits/stdc++.h>
#include "testlib.h"
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
const int INF=1e9;
int n;
vector<pi> a;

void readSeq(){
    n = inf.readInt(1,200000,"n");
    a.resize(n);
    for (int i=0;i<n;i++){
        a[i].F = inf.readInt(1,INF,"x");
        a[i].S = inf.readInt(1,INF,"y");
        if (a[i].F>a[i].S) swap(a[i].F,a[i].S);
    }
    sort(a.begin(),a.end());
}

bool readAndCheckAnswer(InStream &in) {
    string str=in.readString();
    for (int i=0;i<(int)str.size();i++) if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]+'a'-'A';
    if (str=="no"){
        if (!in.eof()){
            string t=in.readString();
            if (!in.eof()) in.quitf(_wa,"excess output");
        }
        return 0;
    } else if(str!="yes"){
        in.quitf(_wa,"invalid output");
    }
    vector<pi> b(n);
    for (int i=0;i<n;i++){
        b[i].F = in.readInt(1,INF,"x");
        b[i].S = in.readInt(1,INF,"y");
    }
    if (!in.eof()){
        string t=in.readString();
        if (!in.eof()) in.quitf(_wa,"excess output");
    }
    for (int i=0;i<n-1;i++) 
        if (b[i].S==b[i+1].F) in.quitf(_wa,"the numbers on adjacent dominoes are the same");
    for (int i=0;i<n;i++){
        if (b[i].F>b[i].S) swap(b[i].F,b[i].S);
    }
    sort(b.begin(),b.end());
    for (int i=0;i<n;i++)
        if (a[i]!=b[i]) in.quitf(_wa,"input and output dominoes are inconsistent");
    return 1;
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    readSeq();
    bool ret_jury = readAndCheckAnswer(ans);
    bool ret_part = readAndCheckAnswer(ouf);
    if (ret_jury == ret_part) quitf(_ok, "correct");
    if (ret_jury) quitf(_wa,"Participant fails to find a solution.");
    if (ret_part) quitf(_fail,"Jury fails to find a solution.");
}
