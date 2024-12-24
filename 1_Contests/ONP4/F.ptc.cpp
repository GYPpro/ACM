#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ord_set = tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
// #define map unordered_map
#pragma GCC optimize(3)
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n+1);
    lop(i,1,n+1) cin >> s[i];
    // vector<int> rs(n+2);
    // ord_set ord;
    // for(int i = n;i >= 1;i --){
    //     rs[i] = rs[i+1] + ord.order_of_key(s[i]);
    //     ord.insert(s[i]);
    // }
    auto rec = [&]() -> int {
        vector<int> rs(n+2);
        ord_set ord;
        for(int i = n;i >= 1;i --){
            rs[i] = rs[i+1] + ord.order_of_key(s[i]);
            ord.insert(s[i]);
        }
        return rs[1];
    };

    int cur = rec();
    int mi = cur;
    int m;
    cin >> m;

    while(m--)
    {
       int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
        int al = s[x],ar = s[y];
		// for(int i=x+1;i<y;i++){
		// 	cur-=s[y]<s[i];
		// 	cur-=s[x]>s[i];
        //     cur+=s[x] < s[i];
        //     cur+= s[y] > s[i];
		// }
        lop(i,x+1,y){
            if(s[i] < al) cur --;
            else if(s[i] > al) cur ++;
            if(s[i] > ar) cur --;
            else if(s[i] < ar) cur ++;
        }
        if(s[x] > s[y]) cur --;
        else if(s[x] < s[y]) cur ++;
        // if(s[x] > s[y]) cur += 2;
        // else cur -= 2;
		// // for(int i=x+1;i<y;i++){
		// // 	cur+=s[y]<s[i];
		// // 	cur+=s[x]>s[i];
		// // }
        // if(s[x] > s[y]) cur--;
        // else cur ++;
        // if(s[x] > s[y]) cur += 2;
        // else cur -= 2;
        // cur-=s[x]>s[y];
		swap(s[x],s[y]);
		// cur+=s[x]>s[y];
		// // for(int i=x+1;i<y;i++){
		// // 	cur+=s[y]<s[i];
		// // 	cur+=s[x]>s[i];
		// // }
		mi=min(mi,cur);
//		cout<<cur<<"\n";
        // cout << cur << " ";
        // cout << ((cur == rec())?"AC":"WA") << "\n";
    }
    cout << mi << "\n";
}
signed main()
{
        #ifdef FC
        freopen("F.A.in","r",stdin);
        freopen("F.A.ptc","w",stdout);
    #endif

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // init(5e5);
    int t = 1;
    cin >> t;
    while(t--) solve();
}