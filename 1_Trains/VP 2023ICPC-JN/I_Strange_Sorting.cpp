// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

int a[1000];
void solve()
{
    int n;
    cin>>n;
    
    // vector<int> vis(n+1);
    // vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // pos[a[i]]=i;
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        int tmp=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]) tmp=j;
        }
        if(tmp==i) continue;
        else{
            ans.push_back({i,tmp});
            sort(a+i+1,a+tmp+1);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto [x,y]:ans) cout<<x<<" "<<y<<"\n";
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
