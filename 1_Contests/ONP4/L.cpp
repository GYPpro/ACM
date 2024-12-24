#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> speed(n+1);
    lop(i,1,n+1) cin >> speed[i];
    while(q--)
    {
        int p,k;
        cin >> p >> k;
        int cur = speed[k]*p % (2 * m);
        if(cur >= m) cur = 2 * m - cur;
        cout << cur << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}