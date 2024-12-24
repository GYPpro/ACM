#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
const int mod = 1e9+7;
const int INF = 1e17;
void solve()
{
    int n;
    cin >> n;
    map<int,int> cnt;
    // int cnt = 0;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    int mi = arr[1];
    lop(i,1,n+1) cnt[arr[i]] ++;
    lop(i,2,n+1) mi = min(mi,min( (mi %arr[i]) == 0 ? INF:mi %arr[i], (arr[i] % mi) == 0 ? INF:(arr[i] % mi)));
    // cout << mi << "\n";
    // lop(i,0,n)
    // {
    //     int t;
    //     cin >> t;
    //     cnt[t] ++;
    // }
    cout << max(1LL,(cnt[mi]+1 >> 1)) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}