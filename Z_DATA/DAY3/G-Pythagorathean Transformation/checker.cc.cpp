#include <bits/stdc++.h>
#include "testlib.h"
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int INF=1e9;
ll s,t;
int st;
bool issquare(__int128 x){
    ll l=0,r=2e18;
    while (r-l>1){
        ll mid=(l+r)>>1;
        if ((__int128)mid*mid>x) r=mid; else l=mid;
    }
    return (__int128)l*l==x;
}
const int LIMIT=2000;
bool checktri(ll u,ll v){
    if (u==v) return 0;
    if (u<v) swap(u,v);
    return issquare((__int128)u*u+(__int128)v*v)||issquare((__int128)u*u-(__int128)v*v);
}
bool readAndCheckAnswer(InStream &in) {
    string str=in.readString();
    if (str=="impossible"){
        if (!in.eof()){
            string t=in.readString();
            if (!in.eof()) in.quitf(_wa,"excess output");
        }
        return 0;
    }
    int len=0;
    if (str.size()>4) in.quitf(_wa,"invalid output");
    for (int i=0;i<str.size();i++){
        if (str[i]<'0'||str[i]>'9') in.quitf(_wa,"invalid output");
        len=len*10+(str[i]-'0');
    }
    st=len;
    if (len==0) in.quitf(_wa,"invalid output");
    if (len>LIMIT) in.quitf(_wa,"%d steps used, exceeded the limit",len);
    vector<ll> A; A.pb(s);
    for (int i=0;i<len;i++){
        ll x=in.readLong(1, 1'000'000'000'000'000'000ll,"x");
        A.pb(x);
        if (i==len-1&&x!=t) in.quitf(_wa,"the final number obtained is not t");
    }
    if (!in.eof()){
        string t=in.readString();
        if (!in.eof()) in.quitf(_wa,"excess output");
    }
    for (int i=0;i<A.size()-1;i++){
        ll u=A[i],v=A[i+1];
        if (!checktri(u,v)) in.quitf(_wa,"the %d-th step is not a valid transform",i+1);
    }
    return 1;
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    s = inf.readInt(1, 1'000'000'000, "s");
    t = inf.readInt(1, 1'000'000'000, "t");
    
    bool ret_jury = readAndCheckAnswer(ans);
    bool ret_part = readAndCheckAnswer(ouf);
    if (ret_jury == ret_part) quitf(_ok, "correct, using %d steps",st);
    if (ret_jury) quitf(_wa,"Participant fails to find a solution.");
    if (ret_part) quitf(_fail,"Jury fails to find a solution.");
}
