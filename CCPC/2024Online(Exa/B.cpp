#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 1E6;
#define pb push_back
#define all(x) x.begin(),x.end()
void solve() {
    
    int n;
    cin >> n;
    vector<pair<pii,int>> tars(n);
    for(int i = 0;i < n;i ++) cin >> tars[i].fi.se >> tars[i].fi.fi,tars[i].se = i;
    sort(all(tars));
    vector<pair<int,pii>> rgs;
    int rrg = N,lrg = 0;
    map<int,vector<pii>> cst;
    for(auto x:tars) cst[x.fi.fi].push_back({x.fi.se,x.se});
    bool flag = 1;
    for(auto [i,lst]:cst)
    {
        sort(all(lst));
        reverse(all(lst));
        if(lrg > lst[0].fi) {flag = 0;break;}
        int k = rrg;
        for(auto [rg,idx]:lst)
        {
            rgs.pb({idx,{rg,k}});
            k --;
        }
    }
    if(!flag) cout << "-1\n";
    else {
    sort(all(rgs));
    for(auto [i,rg]:rgs) cout << rg.se << "\n";
    cout << "\n";}
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}