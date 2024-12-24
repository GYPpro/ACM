#include<bits/stdc++.h>
using namespace std;
//#define int long long
using ll=long long;
struct node{
    char c;
    int val;
};

// class fr : public std::pair<int,int>{
// public:
//     int &fz = this->first;
//     int &fm = this->second;
// };

// fr gc(fr f){
//     int t = __gcd(f.fz,f.fm);
//     return fr(f.fz/t,f.fm/t);
// }

// fr ad(fr a,fr b) {
// 
// }

using pii = pair<int,int>;
#define fz first
#define fm second

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    node s[n];
    for(int i=0;i<n;i++){
        char c;
        int val;
        cin>>c>>val;
        s[i]={c,val};
    }
    sort(s,s+n,[&](node x,node y){
        return x.val<y.val;
    });
    int val=0;
    int tp=0,fn=0,fp=0,tn=0;
    for(int i=0;i<n;i++){
        if(s[i].c=='+') tp++;
        else fp++;
    }
    vector<pii> TPR,FPR;
    using ld = long double;
    // 
    TPR.push_back({tp,tp+fn});
    FPR.push_back({fp,tn+fp});
    for(int i=0;i<n;i++){
        while(1){
            if(s[i].c=='+'){
                tp--;
                fn++;
            }
            else{
                fp--;
                tn++;
            }
            if(i+1>n||s[i+1].val!=s[i].val) break;
            i++;
        }
        //
        TPR.push_back({tp,tp+fn});
        FPR.push_back({fp,tn+fp});
    }

    // for(auto x:TPR) cout << cacu(x) << "\n";/

    auto cacu = [&](pii x )-> ld {
        return (ld)x.first/(ld)x.second;
    };

    map<pii,ld> prfmin;
    for(int i = 0;i < FPR.size();i ++)
    {
        prfmin[FPR[i]] = max(prfmin[FPR[i]],cacu(TPR[i]));
        
    }
    vector<pair<ld,ld>> sss;
    for(auto [k,v]:prfmin) {
        sss.push_back({cacu(k),v});
        // cout << cacu(k) << " " << v << "\n";
    }
    sort(sss.begin(),sss.end());
    ld res = 0;
    ld pf = 0;
    ld py = 0;
    for(auto [cx,y]:sss){
        res += (cx - pf) * py;
        py = y;
        pf = cx;
    }
    cout << fixed <<setprecision(18)<< res << "\n";
}
/*

*/