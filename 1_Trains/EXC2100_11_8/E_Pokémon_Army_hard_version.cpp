// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> dp(n+1,vector<int>(2));
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    int mi=0,mx=0,ans=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,a[i]);
        if(i>=2&&a[i]<a[i-1]){
            ans+=max(0LL,mx-mi);
            mx=0;mi=a[i];
        }
    }
    ans+=max(0LL,mx-mi);
    cout<<ans<<"\n";
    a[0]=0;
    a[n+1]=0;
    auto add=[&](int i)->void{
        if(i==0||i==n+1) return;
        if(a[i]>=a[i-1]&&a[i]>=a[i+1]) ans+=a[i];
        if(a[i]<=a[i-1]&&a[i]<=a[i+1]) ans-=a[i];
    };
    auto del=[&](int i)->void{
        if(i==0||i==n+1) return;
        if(a[i]>=a[i-1]&&a[i]>=a[i+1]) ans-=a[i];
        if(a[i]<=a[i-1]&&a[i]<=a[i+1]) ans+=a[i];
    };
    while(q--){
        int l,r;
        cin>>l>>r;
        del(l+1);
        del(l);
        del(l-1);
        if(r!=l){
            if(r-1!=l+1&&r-1!=l) del(r-1);
            if(r!=l+1) del(r);
            del(r+1);
        }
        swap(a[l],a[r]);
        add(l+1);
        add(l);
        add(l-1);
        if(r!=l){
            if(r-1!=l+1&&r-1!=l) add(r-1);
            if(r!=l+1) add(r);
            add(r+1);
        }
        cout<<ans<<"\n";
    }
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
