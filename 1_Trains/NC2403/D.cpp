#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

#define map unordered_map
#define set unordered_set
#define pq priority_queue
#include <map>
#include <set>

#define int long long
#define pii pair<int,int>
#define fi first
#define pb push_back
#define se second
const int INF = 1145141919810LL;
void sort(auto &x){sort(x.begin(),x.end());}
using namespace std;

void solve(){
	int n;
    cin >> n;
    vector<pii> arr(n);
    for(auto &x:arr) cin >> x.fi >> x.se;
    map<int,int> cnt;
    for(auto x:arr) cnt[x.fi] ++,cnt[x.se] ++;

    if(n == 1){
        cout << "Yes\n" << arr[0].fi << " " << arr[0].se << " \n";
        return;
    }

    if(cnt.size() <= 1){ cout << "No\n";return;}
    int MEX = 0,MXI = 0;
    for(auto x:cnt) if(x.se > MEX) MEX = x.se,MXI = x.fi;
    if(MEX > n+1){ cout << "No\n";return;}

    map<int,map<int,int>> nxt;
    for(auto x:arr) nxt[x.fi][x.se] ++, nxt[x.se][x.fi] ++;

    priority_queue<pii> piq;
    map<int,int> pcnt;
    for(auto x:arr) if(x.fi == x.se) pcnt[x.fi] ++;
    for(auto x:pcnt) piq.push({x.se,x.fi});

    pii cur = {-1,-1};
    cout << "Yes\n";
    for(int i = 0;i < n;i ++)
    {
        vector<int> TBM;
        if(piq.size() >= 2){
            pii x = piq.top();
            piq.pop();
            if(x.se == cur.se) {
                pii t = x;
                x = piq.top();
                piq.pop();
                piq.push(t);
            }
            cur = {x.se,x.se};
            nxt[cur.fi][cur.se]--;    
            nxt[cur.se][cur.fi]--;
            if(nxt[cur.fi][cur.se] == 0) nxt[cur.fi].erase(cur.se);
            if(nxt[cur.se][cur.fi] == 0) nxt[cur.se].erase(cur.fi);
            cout << cur.fi << " " << cur.se << "\n";
            x.fi -= 1;
            if(x.fi > 0) piq.push(x);
            continue;
        } else if(piq.size()) 
        {
            if(piq.top().se != cur.se )
            {
                pii x = piq.top();
                piq.pop();
                cur = {x.se,x.se};
                nxt[cur.fi][cur.se]--;    
                nxt[cur.se][cur.fi]--;
                if(nxt[cur.fi][cur.se] == 0) nxt[cur.fi].erase(cur.se);
                if(nxt[cur.se][cur.fi] == 0) nxt[cur.se].erase(cur.fi);
                cout << cur.fi << " " << cur.se << "\n";
                x.fi -= 1;
                if(x.fi > 0) piq.push(x);
                continue;
            }
        }

        for(auto &x:nxt) {
            // for(auto y:x.se) cout << y << " ";cout <<"\n";
            if(x.se.size() == 0) TBM.pb(x.fi);
            if(x.se.size() > 0 && x.fi != cur.se) {
                cur = {x.fi,(*(x.se.begin())).fi};
                // for(auto y:x.se){
                //     if(y.se == 0) continue;
                //     if(piq.size() == 0 || y.fi != piq.top().se){
                //         cur = {x.fi,y.fi};
                        cout << cur.fi << " " << cur.se << "\n";
                        goto ENDLOOP;
                //     }
                // }
            }
        }
        ENDLOOP:
        nxt[cur.fi][cur.se]--;    
        nxt[cur.se][cur.fi]--;
        if(nxt[cur.fi][cur.se] <= 0) nxt[cur.fi].erase(cur.se);
        if(nxt[cur.se][cur.fi] <= 0) nxt[cur.se].erase(cur.fi);
        for(auto x:TBM) nxt.erase(x);
    }
    return; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}